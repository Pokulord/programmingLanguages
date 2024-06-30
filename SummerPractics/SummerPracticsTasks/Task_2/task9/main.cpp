#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//  Число N
const int N = rand() % 100 + 1 ;

// Функция для записи произедения
void make_product_of_neigbours(vector<int>d_array)
{
    // Открываем файл для записи произведения
    ofstream final_file("product.txt") ;
    // Перемножаем "соседей"
    for (int index = 0 ; index < N ; index++)
    {
        final_file << d_array[index] * d_array[index+1] << "  " ;
    }
    wcout << L"Запись произведения в файл произошла успешно!" << endl ;
}
// Функция для вывода содержимого массива в консоль
void Print_array(vector<int>d_array)
{
    for (int index = 0 ; index < N ; index++)
    {
        wcout << d_array[index] << "  " ;
    }
    wcout << endl ;
}
int main()
{
    setlocale(LC_ALL, "Russian") ;
    // Массив, в котором храним числа для записи в изначальный файл
    vector<int>array_of_numbers(N) ;
    // Заполняем массив случайными числами
    for (int index = 0 ; index < N ; index++)
    {
        array_of_numbers[index] = rand() % 21 - 10 ;
    }

    wcout << L"Содержимое изначального файла : " << endl ;
    Print_array(array_of_numbers) ;
    // Записываем содержимое массива в файл
    ofstream originalfile("original.txt");
    // Проверяем на корректность открытия
    if (!originalfile.is_open())
    {
        wcout << L"Изначальный файл не был открыт" << endl;
        return -1 ;
    }

    for (int number : array_of_numbers) {originalfile << number << "    " ;}
    originalfile.close() ;

    wcout << L"Запись в изначальный файл прошла успешно!" << endl ;

    // Производим запись произведения соседних компонент в файл

    make_product_of_neigbours(array_of_numbers) ;
    return 0;
}
