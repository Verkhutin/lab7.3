#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Input(int** T, const int r, const int c)
{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << "T[" << i << "][" << j << "] = ";
				cin >> T[i][j];
			}
			cout << endl;
		}
}

void Print(int** T, const int r, const int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			cout << setw(4) << T[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int Amount(int** T, const int r, const int c) {
	int am = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			if (T[j][i] == 0) {
				am++;
				break;
			}
		}
	}
	return am;
}

void NumRow(int** T, const int r, const int c) {
	int el = 0;
	int maxi = 0;
	int maxel = -1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r - 1; j++)
		{
			if (T[i][j] == T[i][j+1])
			{
				el++;
			}
			else
			{
				break;
			}
			if (el > maxel)
			{
				maxel = el;
				maxi = i;
			}

		}
	}
	if (maxel > -1)
	cout << maxi << endl;
	else
	cout << "there are no same elements in rows" << endl;
}

int main() {
	srand((unsigned)time(NULL));

	const int r = 3, c = 2;
	int** T = new int* [r];
	for (int i = 0; i < r; i++)
		T[i] = new int[c];

	cout << "Start array: " << endl;
	Input(T, r, c);
	Print(T, r, c);
	cout << "Amount of columns that consist elements of zero = " << Amount(T, r, c) << endl;
	cout << "Number of row with the longest series of the same elements = ";
	NumRow(T, r, c);

	for (int i = 0; i < r; i++)
		delete[] T[i];
	delete[] T;

	return 0;
}
