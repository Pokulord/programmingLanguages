#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int num, i=0;

    // ������� 1
    cout << "������� �����, ����������: " << endl;
    cin >> num;
    for (int i=0; i<=num; i++)
    {
        cout<<i<<' ';
    }


    // ������� 2
    cout << "\n������� ����� ��� 2 �������: " << endl;
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


    // �3
    cout << "\n������� ������������� �����: " << endl;
    cin >> num;
    for (int i=1; i<=num; i++)
    {
        if(i%1000==0)
    {
        cout<<"������ " <<i/1000<<  "������/����� ��������"<< endl;
    }
    }
}
