#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//showArr
template <typename T> void showArr(T arr[], int length);
//fillArr
template <typename T> void fillArr(T arr[], int length, int max, int min);
//������ 2
template <typename T> T* resizeArr(T arr[], int& size1, int size2);


int main() {
	setlocale(LC_ALL, "Russian");

	//������ 1
	cout << "������ 1\n";
	const int n = 5, m = 5;
	int* A = new int[n];
	int* B = new int[m];
	for (int i = 0; i < n; i++)
		A[i] = i;

	for (int i = 0; i < m; i++)
		B[i] = i + 5;
	cout << "������ A:\n";
	showArr(A, n);
	cout << "������ B:\n";
	showArr(B, m);

	int* C = new int[n + m];
	for (int i = 0; i < n + m; i++) {
		if (i < 5) 
			C[i] = A[i];
		else
			C[i] = B[i - n];
	}
	delete[] A;
	delete[] B;
	cout << "������ C:\n";
	showArr(C, n + m);
	cout << endl;
	delete[] C;

	//������ 2
	cout << "������ 2\n������� ����� �������:\n";
	int size1, size2, min, max;
	cin >> size1;
	cout << "������� �������� �� �������� � ��������:\n";
	cin >> max >> min;
	int* arr = new int[size1];
	fillArr(arr, size1, max, min);
	cout << "������������ ������:\n";
	showArr(arr, size1);

	cout << "������� ����� ����� �������:\n";
	cin >> size2;
	arr = resizeArr(arr, size1, size2);
	cout << "������������ ������:\n";
	showArr(arr, size2);
	cout << endl;
	delete[] arr;

	return 0;
}

//������ 2
template <typename T> T* resizeArr(T arr[], int& size1, int size2) {
	int size3 = size2 - size1;
	T* tmp = new T[size1 + size3];
	for (int i = 0; i < size1 + size3; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[size1 + size3];
	for (int i = 0; i < size1 + size3; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}

//fillArr
template <typename T> void fillArr(T arr[], int length, int max, int min) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}

//showArr
template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}