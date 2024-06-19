#include <iostream>
#include <cstdlib>
using namespace std;


// Размер массива (число букв имени и фамилии)
const int ARRAY_SIZE = 17 ;

// Функция для генерации массива, который содержит в себе
// Сумму содержимого двух массивов
int* SumTwoArrays(int *arr1, int *arr2)
{
    // Создаём результирующий массив
    int *res_array = new int[ARRAY_SIZE] ;
    // Итерационно складываем элементы двух массивов
    for (int index = 0 ; index < ARRAY_SIZE ; index++)
    {
        res_array[index] = arr1[index] + arr2[index] ;
    }

    // Возвращаем полученный массив
    return res_array ;
}

// Функция для заполнения массива случайными числами
void FillArray(int *arr)
{
    for (int index = 0 ; index < ARRAY_SIZE ; index++)
    {
        arr[index] = rand() % 21-10 ;
    }
}

// Функция для вывода содержимого массива на экран
void PrintArray(int *arr)
{
    for (int index = 0; index < ARRAY_SIZE ; index++)
    {
        wcout << arr[index] << " , " ;
    }
    wcout << endl ;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    // Создаём массивы и заполняем их данными
    int *array1 = new int[ARRAY_SIZE];
    int *array2 = new int[ARRAY_SIZE] ;
    wcout << L"Содержимое первого массива : "  << endl ;
    FillArray(array1) ;
    PrintArray(array1) ;
    wcout << L"Содержимое второго массива :" << endl ;
    FillArray(array2) ;
    PrintArray(array2) ;
    // Вызываем функцию, которая суммирует содержимое двух массивово
    wcout << L"Содержимое результирующего массива, содержащего суммы элементов : " << endl ;
    int *res_arr = SumTwoArrays(array1, array2) ;
    PrintArray(res_arr) ;

    // Очищаем память, удаляя массивы из памяти
    delete array1, array2 ;

    return 0;
}
