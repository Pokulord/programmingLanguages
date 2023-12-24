#include <iostream>
#include <iomanip>
using namespace std;
void printArray(int *array, int size)
{
    for (int index = 0; index<size;index++)
    {
        cout << array[index] << "  ";
    }
}

void printMatrix(int matrix[5][5], int size)
{
    for (int index_1 = 0 ; index_1 < size ; index_1++ )
    {
        for (int index_2 = 0; index_2 < size; index_2++)
        {
            cout << setw(5) << matrix[index_1][index_2];
        }
        cout << "\n";
    }
}

void change_minus_elems(int matrix[5][5], int size)
{
    cout << "����������� ������� : " << endl;
    printMatrix(matrix,5);
    for (int index_1 = 0 ; index_1 < size ; index_1++)
    {
        for (int index_2 = 0 ; index_2 < size ; index_2++)
        {
            if (matrix[index_1][index_2] < 0){
                matrix[index_1][index_2] = 0;
            }
        }
    }
    cout << "������� ��� ������������� ��������� :" << endl;
    printMatrix(matrix,5);
}

void summOfString(int matrix[5][5], int size)
{
    int sum = 0;
    for (int ind_1 = 0 ; ind_1 < size; ind_1++)
    {
        for (int ind_2 = 0 ; ind_2 < size  ; ind_2++)
        {
            sum = sum + matrix[ind_1][ind_2];
        }
        cout << "����� � ������ " << ind_1 + 1 << " = " << sum << endl;
        sum = 0;
    }
}

int main()
{
    setlocale(LC_ALL,"Russian");
 //������� 1
 cout << "������ 1 :" << endl;
 int arr_1[10] = {2,55,6,66,67,4,2,90,55,56};
 printArray(arr_1,10);
 cout << "\n";
 //������� 2
 int arr_2[10] ;
 cout << "������ 2 :" << endl;
 for (int index = 0; index < 10 ; index++)
 {
     arr_2[index] = rand() % (10+10+1) - 10;
 }
 printArray(arr_2,10);
 cout << "\n";
 //������� 3

 int arr_3[5], element_by_index;
 for (int index = 0; index<5; index ++)
 {
     cout << "����������, ������� " << index+1 << " �������" << endl;
     cin >> element_by_index ;
     arr_3[index] = element_by_index;
 }
 cout << "������ 3 : " << endl;
 printArray(arr_3,5);


 // ������� 4

 cout << "\n�������� ������ 4:"<< endl;
 printArray(arr_2, 10);
 cout << "\n������ ����� �������� �� ��������/����������" << endl;
 for (int index = 0 ; index < 10; index++)
 {
     if (arr_2[index] % 2 == 0){
        arr_2[index] = arr_2[index] * 3;
     }
     else {
        arr_2[index] = arr_2[index] * 5;
     }
 }
 printArray(arr_2,10);


 // ������� 5

 int matrix_1[5][5];

 for (int index_1 = 0; index_1 < 5 ; index_1++)
 {
     for (int index_2 = 0 ; index_2 < 5; index_2++)
     {
         matrix_1[index_1][index_2] = rand() % (10+10+1) - 10;
     }
 }

 cout << "\n������� 1" << endl;

 printMatrix(matrix_1, 5);

 summOfString(matrix_1,5);

 change_minus_elems(matrix_1,5);

}

