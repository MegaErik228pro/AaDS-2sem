#include <iostream>
#include <ctime>
using namespace std;
int fibonacci(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return fibonacci(index - 1) + fibonacci(index - 2);
}


int main()
{
    setlocale(LC_ALL, "rus");
    int N;
    cout << "����� ���������� ����� "; cin >> N;
    unsigned int start_time = clock();
    //for (int count = 0; count < N; ++count)
    cout << fibonacci(N-1) << " ";
    cout << endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "����� ����������� �����(��������): " << search_time << " ��." << endl;

    int a = 1, b = 1, c;
    unsigned int start_time_2;
    unsigned int end_time_2;
    if (N == 1) {
         cout << "0 ";
    }
    else
    {
        if (N == 2) { cout << "1 "; }
        else
        {

            //cout << "0 1 1";
            start_time_2 = clock();
            for (int i = 3; i < N; i++)
            {
                c = a + b;
                a = b; b = c;
            }
            end_time_2 = clock();
            cout << c;
        }
    }
    
    unsigned int search_time_2 = end_time_2 - start_time_2;
    cout << "\n����� ����������� �����(������): " << search_time_2 << " ��." << endl;

    int raz = search_time - search_time_2;
    cout << "�������: " << abs(raz) << " ��.";
    return 0;
}