#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;
void bubblesort(int* mas, int N) //����������� ����������
{
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (mas[i] > mas[j]) {
                swap(mas[i], mas[j]);
            }
        }
    }
}
void shellsort(int* mas, int N) //���������� �����
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
void choicesort(int* mas, int N) //���������� �������
{
    for (int i = 0; i < N; i++) {
        int min = i;
        for (int j = i + 1; j < N; j++)
            min = (mas[j] < mas[min]) ? j : min;

        if (i != min) {
            swap(mas[i], mas[min]);
        }
    }
}
void quicksort(int* mas, int first, int last) { //������� ����������
    int mid;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //���������� �������� ��������
    do
    {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;
        if (f <= l) //������������ ���������
        {
            swap(mas[f], mas[l]);
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int N;
    cout << "������� ���������� ���������" << endl;
    cin >> N;

    int* A = new int[N]; cout << "A = ";
    for (int count = 0; count < N; count++)
        A[count] = (rand() % 100 + 1);
    //for (int count = 0; count < N; count++)
    //    cout << A[count] << "    "; cout << endl;

    int* B = A; cout << "B = "; //����������� ����������
    unsigned int start_time = clock();
    bubblesort(B, N);
    unsigned int end_time = clock();
    unsigned int search_time_bubble = end_time - start_time;
    for (int count = 0; count < N; count++)
        cout << B[count] << "    "; cout << endl;

    int* C = A; cout << "C = "; //���������� �����
    start_time = clock();
    shellsort(C, N);
    end_time = clock();
    unsigned int search_time_shell = end_time - start_time;
    //for (int count = 0; count < N; count++)
        //cout << C[count] << "    "; cout << endl;

    int* D = A; cout << "D = "; //���������� �������
    int buf;
    start_time = clock();
    choicesort(D, N);
    end_time = clock();
    unsigned int search_time_choice = end_time - start_time;
    //for (int count = 0; count < N; count++)
       // cout << D[count] << "    "; cout << endl;

    int* E = A; cout << "E = "; //������� ����������
    start_time = clock();
    quicksort(E, 1, N+1);
    end_time = clock();
    unsigned int search_time_quick = end_time - start_time;
    for (int count = 0; count < N; count++)
        cout << E[count] << "    "; cout << endl;

    cout << "����������� ���������� " << search_time_bubble << "��" << endl;
    cout << "���������� ����� " << search_time_shell << "��" << endl;
    cout << "���������� ������� " << search_time_choice << "��" << endl;
    cout << "������� ���������� " << search_time_quick << "��" << endl;

  
    delete[] A;
}