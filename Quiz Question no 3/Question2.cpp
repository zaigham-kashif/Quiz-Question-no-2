#include<iostream>

using namespace std;

bool isprime(int no_check);
void SplitArray(int** array1, int sizeof_array1, int**& array2, int**& array3, int& NoOfRows_array2, int& NoOfRows_array3, int*& NoOfEntries_array2, int*& NoOfEntries_array3);
void print(int** array, int NoOfRows_array, int* NoOfEntries_array);
void deAllocate(int**& array, int no_of_rows);


int main()
{
	int sizeof_array1;
	bool prime_check;
	cout << "	Enter the size of Array : "; 
	cin >> sizeof_array1;
	cout << endl;
	int** array1 = new int* [sizeof_array1];
	int** array2;
	int** array3;
	int NoOfRows_array2 = 0, NoOfRows_array3 = 0;
	int* NoOfEntries_array2;
	int* NoOfEntries_array3;
	for (int i = 0; i < sizeof_array1; i++)
	{
		array1[i] = new int[sizeof_array1];
	}
	for (int i = 0; i < sizeof_array1; i++)
	{
		for (int j = 0;j < sizeof_array1; j++)
		{
			cout << "	Enter Element number" << i + 1 << "*" << j + 1 <<" : ";
			cin >> array1[i][j];
		}
		cout << endl;
	}

	system("CLS");

	cout << "	Original Array" << endl;
	cout << endl;
	cout << endl;
	print(array1, sizeof_array1, nullptr);
	cout << endl;
	cout << endl;

	SplitArray(array1, sizeof_array1, array2, array3, NoOfRows_array2, NoOfRows_array3, NoOfEntries_array2, NoOfEntries_array3);
	cout << "	Array Of Prime Numbers is" << endl;
	cout << endl;
	cout << endl;

	print(array2, NoOfRows_array2, NoOfEntries_array2);
	cout << endl;
	cout << endl;
	cout << "	Array Of Non-Prime Numbers is" << endl;
	cout << endl;
	cout << endl;

	print(array3, NoOfRows_array3, NoOfEntries_array3);

	deAllocate(array1, sizeof_array1);
	deAllocate(array2, NoOfRows_array2);
	deAllocate(array3, NoOfRows_array3);
}

bool isprime(int no_check)
{
	int counter_prime = 0;
	for (int i = 1; i <= no_check; i++)
	{
		if (no_check % i == 0)
		{
			counter_prime++;
		}
	}
	if (counter_prime == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SplitArray(int** array1, int sizeof_array1, int**& array2, int**& array3, int& NoOfRows_array2, int& NoOfRows_array3, int*& NoOfEntries_array2, int*& NoOfEntries_array3)
{
	bool prime_check;
	int prime = 0, not_prime = 0;
	for (int i = 0; i < sizeof_array1; i++)
	{
		for (int j = 0; j < sizeof_array1; j++)
		{
			prime_check = isprime(array1[i][j]);
			if (prime_check == true)
			{
				prime++;
			}
			else
			{
				not_prime++;
			}
		}
		if (prime != 0)
		{
			NoOfRows_array2++;
		}
		if (not_prime != 0)
		{
			NoOfRows_array3++;
		}
		prime = 0;
		not_prime = 0;
	}
	array2 = new int* [NoOfRows_array2];
	array3 = new int* [NoOfRows_array3];
	NoOfEntries_array2 = new int[NoOfRows_array2];
	NoOfEntries_array3 = new int[NoOfRows_array3];


	int x = 0, y = 0;
	for (int i = 0; i < sizeof_array1; i++)
	{
		for (int j = 0; j < sizeof_array1; j++)
		{
			prime_check = isprime(array1[i][j]);
			if (prime_check == true)
			{
				prime++;
			}
			else
			{
				not_prime++;
			}
		}
		if (prime != 0)
		{
			array2[x] = new int[prime];
			NoOfEntries_array2[x] = prime;
			x++;
		}
		if (not_prime != 0)
		{
			array3[y] = new int[not_prime];
			NoOfEntries_array3[y] = not_prime;
			y++;
		}
		prime = 0;
		not_prime = 0;
	}


	int x_array2 = 0, y_array2 = 0, x_array3 = 0, y_array3 = 0;
	bool prime_flag = false, notPrime_flag = false;
	for (int i = 0; i < sizeof_array1; i++)
	{
		for (int j = 0; j < sizeof_array1; j++)
		{
			prime_check = isprime(array1[i][j]);
			if (prime_check == true)
			{
				array2[x_array2][y_array2] = array1[i][j];
				y_array2++;
				prime_flag = true;
			}
			else
			{
				array3[x_array3][y_array3] = array1[i][j];
				y_array3++;
				notPrime_flag = true;
			}
		}
		if (prime_flag == true)
		{
			x_array2++;
			prime_flag = false;
		}
		if (notPrime_flag == true)
		{
			x_array3++;
			notPrime_flag = false;
		}
		y_array2 = 0;
		y_array3 = 0;
	}

}

void print(int **array, int NoOfRows_array, int* NoOfEntries_array)
{
	if (NoOfEntries_array==nullptr)
	{
		for (int i = 0; i < NoOfRows_array; i++)
		{
			for (int j = 0; j < NoOfRows_array; j++)
			{
				cout << "	" << array[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < NoOfRows_array; i++)
		{
			for (int j = 0; j < NoOfEntries_array[i]; j++)
			{
				cout << "	" << array[i][j];
			}
			cout << endl;
		}
	}
}

void deAllocate(int** &array, int no_of_rows)
{
	for (int i = 0; i < no_of_rows; i++)
	{
		delete[]array[i];
	}
	delete[]array;
	array = nullptr;
}