#include <iostream>
using namespace std;
void shellsort(int* mas, int N);
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int N, sum = 0;
	cout << "N=";
	cin >> N;
	int* A = new int [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
    cout << endl;
    shellsort(A, N);
    if (N % 2 == 0)
    {
        for (int i = 0, j = N - 1; i != j && i < j; i += 2, j -= 2)
        {
            swap(A[i], A[j]);
        }
        for (int i = 0; i < N; i++)
        {
            cout << A[i] << " ";
            if (i % 2 == 0)
            {
                sum = sum + A[i];
            }
        }
        cout << endl << "Max sum = " << sum;
    }
    else
    {
        for (int i = 0, j = N - 2; i != j && i < j; i += 2, j -= 2)
        {
            swap(A[i], A[j]);
        }
        for (int i = 0; i < N; i++)
        {
            cout << A[i] << " ";
            if (i % 2 == 0)
            {
                sum = sum + A[i];
            }
        }
        cout << endl <<"Max sum = " << sum;
    }
}

void shellsort(int* mas, int N) //Сортировка Шелла
{
    int d = N;
    d = d / 2;
    while (d > 0) {
        for (int i = 0; i < N - d; i++) {
            int j = i;
            while (j >= 0 && mas[j] > mas[j + d]) {
                swap(mas[j], mas[j + d]);
                j--;
            }
        }
        d = d / 2;
    }
}