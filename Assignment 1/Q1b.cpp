// Q1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

void fill_matrix(int **a, int r, int c) // fills a matrix
{
	for (int i = 0; i < r; i++)
	{
		for (int d = 0; d < c;d++)
		{
			cout << "Enter element at row " << i + 1 << " and column " << d + 1 << endl;
			cin >> a[i][d];
		}
	}
}

void print_matrix(int **a, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		cout << endl<<"|";
		for (int d = 0; d < c;d++)
		{
			cout << setw(6) <<a[i][d] << "|";
		}
	}
	cout << endl;
}
void print_matrix(double **a, int r, int c) //overloading for a double array input
{
	for (int i = 0; i < r; i++)
	{
		cout << endl << "|";
		for (int d = 0; d < c;d++)
		{
			cout << setw(10) << a[i][d] << "|";
		}
	}
	cout << endl;
}

void Add(int **a, int **b, int r1, int c1, int r2, int c2)
{
	if (r1 == r2 && c1 == c2)
	{
		int **c = new int*[r1];
		for (int o = 0; o < r1; o++)
		{
			c[o] = new int[c1];
		}
		for (int i = 0; i < r1; i++)
		{
			for (int d = 0; d < c1 ;d++)
			{
				c[i][d] = a[i][d] + b[i][d];
			}
		}
		cout << "Sum of Matrix 1 and 2 is: " << endl;
		print_matrix(c, r1, c1);
	}
	else
	{
		cout << "The two matrices do not have the same dimensions which is a prerequisite for matrix addition." << endl;
	}
}
void Subtract(int **a, int **b, int r1, int c1, int r2, int c2)
{
	if (r1 == r2 && c1 == c2)
	{
		int **c = new int*[r1];
		for (int o = 0; o < r1; o++)
		{
			c[o] = new int[c1];
		}
		for (int i = 0; i < r1; i++)
		{
			for (int d = 0; d < c1;d++)
			{
				c[i][d] = a[i][d] - b[i][d];
			}
		}
		cout << "Difference of Matrix 1 and 2 is: " << endl;
		print_matrix(c, r1, c1);
	}
	else
	{
		cout << "The two matrices do not have the same dimensions which is a prerequisite for matrix subtraction." << endl;
	}
}
int ** Multiply(int **a, int **b, int r1, int c1, int r2, int c2)
{
	if (c1 == r2)
	{
		cout << "Product of the two matrices is: " << endl;
		int **c = new int*[r1];
		for (int y = 0; y < r1; y++)
		{
			c[y] = new int[c2];
		}
		for (int q = 0; q < r1;q++)
		{
			for (int j = 0; j < c2;j++)
			{
				c[q][j] = 0;
			}
		}
		for (int k = 0; k < r1; k++)
		{
			for (int j = 0; j < c2; j++)
			{
				for (int p = 0; p < r2; p++)
				{
					c[k][j] += a[k][p] * b[p][j];
				}
			}
		}
		return c;
	}
	else
	{
		cout << "Invalid Entry. The number of columns of the first matrix must be equal to the number of rows of the second for matrix multiplication to be possible. Returning null matrix: " << endl;
		int **c = new int*[r1];
		for (int y = 0; y < r1; y++)
		{
			c[y] = new int[c2];
		}
		for (int q = 0; q < r1 ;q++)
		{
			for (int j =0; j<c2 ;j++)
			{
				c[q][j] = 0;
			}
		}
		return c;


	}
}


pair<double **, double **> Inverse(int **a, int **b, int r1, int c1, int r2, int c2) //considering input matrices are 3x3 only
{
	double **ta = new  double*[r1];
	for (int y = 0; y < r1; y++)
	{
		ta[y] = new double[c1];
	}

	double **tb = new double*[r2];
	for (int t = 0; t < r2; t++)
	{
		tb[t] = new double[c2];
	}
	//Matrix 1 inverse
	//Finding determinant keeping row 1 as a reference
	double det1 = 0.0; 
	if (r1 == c1)
	{
		for (int y = 0; y < c1; y++)
		{
		
					
			if (y == 0) //
			{
				det1 += 1.0*(a[0][y])*((a[1][1] * a[2][2]) - (a[2][1] * a[1][2]));
			}
			else if (y == 1)
			{
				det1 -= 1.0*(a[0][y])*((a[1][0] * a[2][2]) - (a[2][0] * a[1][2]));
			}
			else
			{
				det1 += 1.0*(a[0][y])*((a[1][0] * a[2][1]) - (a[2][0] * a[1][1]));
			}
				
				
		}
		cout << endl << "Determinant of Matrix 1: " << det1 << endl;
		if (det1 == 0)
		{
			cout << "Matrix 1 has a determinant of zero so isn't invertible. Returning Null Matrix:" << endl;
			for (int q = 0; q < r1;q++)
			{
				for (int j = 0; j < c2;j++)
				{
					ta[q][j] = 0;
				}
			}
		}
		else
		{
			//Finding Transpose
			for (int l = 0; l < r1; l++)
			{
				for (int h = 0; h < c1; h++)
				{
					ta[l][h] = a[h][l];
				}
			}
			cout << "Transpose of Matrix 1:" << endl;
			print_matrix(ta, r1, c1);
			//Making cofactor matrix of transpose matrix
			double **cof1 = new double*[2];
			for (int t = 0; t < 2; t++)
			{
				cof1[t] = new double[2];
			}
			double **hold1 = new double*[r1];
			for (int t = 0; t < r1; t++)
			{
				hold1[t] = new double[c1];
			}
			int count;
			for (int l = 0; l < r1; l++) //fixing needed
			{
				for (int h = 0; h < c1; h++)
				{
					count = 1;
					for (int g = 0; g < r1 ; g++)
					{
						for (int p = 0; p < c1; p++)
						{

							if (g != l && p != h)
							{
								if (count == 1)
								{
									cof1[0][0] = ta[g][p];
									count++;

								}
								else if (count == 2)
								{
									cof1[0][1] = ta[g][p];
									count++;
								}
								else if (count == 3)
								{
									cof1[1][0] = ta[g][p];
									count++;

								}
								else
								{
									cof1[1][1] = ta[g][p];
									count = 1;
									hold1[l][h] = (cof1[0][0] * cof1[1][1]) - (cof1[0][1] * cof1[1][0]);
								}
							}
						}
					}
				}
			}
			for (int e = 0; e < r1; e++)
			{
				for (int u = 0; u < c1; u++)
				{
					ta[e][u] = hold1[e][u];
				}
			}
			
			//Fixing signs and dividing by determinant
			for (int y = 0; y < r1; y++)
			{
				for (int g = 0; g < c1; g++)
				{
					if (((y + g) % 2) != 0)
					{
						ta[y][g] = -1*(ta[y][g])*(1.0 / det1);
					}
					else
					{
						ta[y][g] = (ta[y][g])*(1.0 / det1);
					}
				}
			}
			//cout << "Inverse of Matrix 1:" << endl;
			//print_matrix(ta, r1, c1);





		}
	}
	else
	{
		cout << "Matrix 1 is not a square matrix so isn't invertible. Returning Null Matrix:" << endl;
	
		for (int q = 0; q < r1;q++)
		{
			for (int j = 0; j < c2;j++)
			{
				ta[q][j] = 0.0;
			}
		}
	}
	//Matrix 2 inverse
	if (r2 == c2)
	{
		//Finding determinant 2
		double det2 = 0.0;
		for (int y = 0; y < c2; y++)
		{


			if (y == 0) 
			{
				det2 += 1.0*(b[0][y])*((b[1][1] * b[2][2]) - (b[2][1] * b[1][2]));
			}
			else if (y == 1)
			{
				det2 -= 1.0*(b[0][y])*((b[1][0] * b[2][2]) - (b[2][0] * b[1][2]));
			}
			else
			{
				det2 += 1.0*(b[0][y])*((b[1][0] * b[2][1]) - (b[2][0] * b[1][1]));
			}


		}
		cout << endl << "Determinant of Matrix 2: " << det2 << endl;
		if (det2 == 0)
		{
			cout << "Matrix 2 has a determinant of zero so isn't invertible. Returning Null Matrix:" << endl;
			
			for (int s = 0; s < r2;s++)
			{
				for (int j = 0; j < c2;j++)
				{
					tb[s][j] = 0;
				}
			}
		}
		else
		{
			
			//Finding Transpose
			for (int l = 0; l < r2; l++)
			{
				for (int h = 0; h < c2; h++)
				{
					tb[l][h] = b[h][l];
				}
			}
			cout << "Transpose of Matrix 2:" << endl;
			print_matrix(tb, r2, c2);
			//Making cofactor matrix of transpose matrix
			double **cof = new double*[2]; //needs fixing
			for (int t = 0; t < 2; t++)
			{
				cof[t] = new double[2];
			}
			double **hold2 = new double*[r2];
			for (int t = 0; t < r2; t++)
			{
				hold2[t] = new double[c2];
			}
			for (int l = 0; l < r2; l++)
			{
				for (int h = 0; h < c2; h++)
				{
					int count1 = 1;
					for (int g = 0; g < r2 ; g++)
					{
						for (int p = 0; p < c2 ; p++)
						{

							if (g != l && p != h)
							{
								if (count1 == 1)
								{
									cof[0][0] = tb[g][p];
									count1++;
								}
								else if (count1 == 2)
								{
									cof[0][1] = tb[g][p];
									count1++;
								}
								else if (count1 == 3)
								{
									cof[1][0] = tb[g][p];
									count1++;
								
								}
								else
								{
									cof[1][1] = tb[g][p];
									count1 = 1;
									hold2[l][h] = (cof[0][0] * cof[1][1]) - (cof[0][1] * cof[1][0]);
									
								}
							}
						}
					}
				}
			}
			
			//copying to tb
			for (int e = 0; e < r2; e++)
			{
				for (int u = 0; u < c2; u++)
				{
					tb[e][u] = hold2[e][u];
				}
			}
			

			//Fixing signs and dividing by determinant
			for (int y = 0; y < r2; y++)
			{
				for (int g = 0; g < c2; g++)
				{
					if (((y + g) % 2) != 0)
					{
						tb[y][g] = -1*(tb[y][g])*(1.0/det2);
					}
					else
					{
						tb[y][g] = (tb[y][g])*(1.0 / det2);
					}
				}
			}
			//cout << "Inverse of Matrix 2:" << endl;
			//print_matrix(tb, r2, c2);




		}
		
	}
	else
	{
		cout << "Matrix 2 is not a square matrix so isn't invertible. Returning Null Matrix:" << endl;
		
		for (int s = 0; s < r2;s++)
		{
			for (int j = 0; j < c2;j++)
			{
				tb[s][j] = 0;
			}
		}
    }
	return make_pair(ta, tb);
}
int main()
{
	int row1, col1, row2, col2;
	cout << "Enter first the number of rows and then the number of columns in matrix 1" << endl;
	cin >> row1 >> col1;
	cout << "Enter first the number of rows and then the number of columns in matrix 2" << endl;
	cin >> row2 >> col2;
	//2D arrays are arrays of pointers to arrays
	int **mat1 = new int*[row1]; //dynamically allocating the rows
	for (int u = 0; u < row1; u++)//dynamically allocating columns 
	{
		mat1[u] = new int[col1];
	}
	int **mat2 = new int*[row2]; //dynamically allocating the rows
	for (int u = 0; u < row2; u++)//dynamically allocating columns 
	{
		mat2[u] = new int[col2];
	}
	cout << "Filling Matrix 1:" << endl;
	fill_matrix(mat1, row1, col1);
	
	cout << "Printing Matrix 1:" << endl;
	print_matrix(mat1, row1, col1);

	cout << "Filling Matrix 2:" << endl;
	fill_matrix(mat2, row2, col2);
	
	cout << "Printing Matrix 2:" << endl;
	print_matrix(mat2, row2, col2);

	cout << "Enter the operation you would like to apply on the two matrices. Press 1 for addition, 2 for subtraction, 3 for multiplication and 4 for the inverses of the matrices." << endl;
	int x;
	cin >> x;
	while (x < 1 || x>4)
	{
		cout << "Invalid entry. Try again. Enter 1,2,3,or 4 according to your desired operation" << endl;
		cin >> x;
	}

	if (x == 1) //addition
	{
		Add(mat1,mat2,row1,col1,row2,col2);
	}
	else if(x == 2) //subtraction
	{
		Subtract(mat1, mat2, row1, col1, row2, col2);
	}
	else if (x == 3) //multiplication
	{
		print_matrix(Multiply(mat1, mat2, row1, col1, row2, col2), row1 ,col2 );

	}
	else //inverses
	{
		
		pair<double **, double **> Inv =Inverse(mat1,mat2, row1, col1,row2,col2);
		cout << "Inverse of Matrix 1:" << endl;
		print_matrix(Inv.first,row1,col1);
		cout << "Inverse of Matrix 2: " << endl;
		print_matrix(Inv.second,row2,col2);

	}
   //cleaning up heap memory by deleting both the dynamically allocated matrices
	for (int i = 0; i < row1; ++i) {
		delete[] mat1[i];
	}
	delete[] mat1;

	for (int i = 0; i < row2; ++i) {
		delete[] mat2[i];
	}
	delete[] mat2;

	return 0;
}