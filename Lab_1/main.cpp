#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int num, i=0;

    // Задание 1
    cout << "Введите число, пожалуйста: " << endl;
    cin >> num;
    for (int i=0; i<=num; i++)
    {
        cout<<i<<' ';
    }


    // Задание 2
    cout << "\nВведите число для 2 задания: " << endl;
    cin >> num;

    while (i<num)
    {
        if (i%2 == 0) {
            cout<<i<<' ';
        }
        else{
            cout<<"b"<<' ';
        }
        i++;
    }


    // №3
    cout << "\nВведите четырёхзначное число: " << endl;
    cin >> num;
    for (int i=1; i<=num; i++)
    {
        if(i%1000==0)
    {
        cout<<"Прошла " <<i/1000<<  "тысяча/тысяч итераций"<< endl;
    }
    }
}
