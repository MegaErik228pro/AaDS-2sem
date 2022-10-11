#include <iostream>
using namespace std;
void shellsort(int* mas, int N);
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int N, kol = 0, tr = 1;
    cout << "N=";
    cin >> N;
    int* A = new int[N];
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 10;
        cout << A[i] << " ";
    }
    cout << endl;
    shellsort(A, N);
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;
    int max = A[N - 1];
    for (int i = N - 1; tr <= 3 ; --i)
    {
        if (A[i] == max)
        {
            kol++;
        }
        else
        {
            if (tr != 3)
            {
                kol++;
                max = A[i];
            }
            tr++;
        }
    }
    cout << "Количество призёров: " << kol;
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