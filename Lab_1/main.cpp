#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int num, i=0;

    // Задание 1
    wcout << L"Введите число, пожалуйста: " << endl;
    cin >> num;
    for (int i=0; i<=num; i++)
    {
        cout<<i<<' ';
    }


    // Задание 2
    wcout << L"\nВведите число для 2 задания: " << endl;
    cin >> num;
    wcout << L"Четные числа в диапазоне " << num << endl;
    while (i<num)
    {
        if (i%2 == 0) {
            cout<<i<<' ';
        }
        i++;
    }


    // №3
    wcout << L"\nВведите четырёхзначное число: " << endl;
    cin >> num;
    for (int i=1; i<=num; i++)
    {
        if(i%1000==0)
    {
        wcout<<L"Прошла " <<i/1000<<  L"тысяча/тысяч итераций"<< endl;
    }
    }
}
