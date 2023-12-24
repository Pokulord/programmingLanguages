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
    wcout << L"Изначальная матрица" << endl;
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
    wcout << L"Матрица без отрицательных элементов :" << endl;
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
        wcout << L"Сумма в строке " << ind_1 + 1 << " = " << sum << endl;
        sum = 0;
    }
}

int main()
{
    setlocale(LC_ALL,"Russian");
 //Задание 1
 wcout << L"Массив 1 :" << endl;
 int arr_1[10] = {2,55,6,66,67,4,2,90,55,56};
 printArray(arr_1,10);
 cout << "\n";
 //Задание 2
 int arr_2[10] ;
 wcout << L"Массив 2 :" << endl;
 for (int index = 0; index < 10 ; index++)
 {
     arr_2[index] = rand() % (10+10+1) - 10;
 }
 printArray(arr_2,10);
 cout << "\n";
 //Задание 3

 int arr_3[5], element_by_index;
 for (int index = 0; index<5; index ++)
 {
     wcout << L"Пожалуйста, введите " << index+1 << L" элемент" << endl;
     cin >> element_by_index ;
     arr_3[index] = element_by_index;
 }
 wcout << L"Массив 3 : " << endl;
 printArray(arr_3,5);


 // Задание 4

 wcout << L"\nИсходный массив 4:"<< endl;
 printArray(arr_2, 10);
 wcout << L"\nМассив после проверки на чётность/нечётность" << endl;
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


 // Задание 5

 int matrix_1[5][5];

 for (int index_1 = 0; index_1 < 5 ; index_1++)
 {
     for (int index_2 = 0 ; index_2 < 5; index_2++)
     {
         matrix_1[index_1][index_2] = rand() % (10+10+1) - 10;
     }
 }

 wcout << L"\nМатрица 1" << endl;

 printMatrix(matrix_1, 5);

 summOfString(matrix_1,5);

 change_minus_elems(matrix_1,5);

}

