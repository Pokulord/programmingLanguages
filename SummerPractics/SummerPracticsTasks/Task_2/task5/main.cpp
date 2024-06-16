#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


// Число строк и столбцов
const int ROWS_COUNT = 5 ;
const int COLUMNS_COUNT = 5 ;


void HowManyMinusElems(int matrix[ROWS_COUNT][COLUMNS_COUNT])
{
    // Есть ли в матрице 0
    bool isZeroInMatrix = false;
    // Проходимся по матрице
    for (int row_index = 0 ; row_index < ROWS_COUNT ; row_index++ )
    {
        // Счётчик отрицательных элементов
        int minuselemscounter = 0 ;
        // Проходимся в диапазоне количества столбцов
        for (int col_index = 0 ; col_index < COLUMNS_COUNT ; col_index++ )
        {
            // Если в строке есть 0 - перебираем её и считаем отрицательные элементы
            if (matrix[row_index][col_index] == 0 )
            {
                isZeroInMatrix = true;
                for (int index_counter = 0 ; index_counter < COLUMNS_COUNT ; index_counter++)
                {
                    // Если в строке есть отрицательные элементы - считаем их количество
                    if (matrix[row_index][index_counter] < 0)
                    {
                        minuselemscounter++ ;
                    }
                }
                wcout << L"Количество отрицательных элементов в строке " << row_index+1 << " : " << minuselemscounter << endl ;
            }
        }


    }

    if (!isZeroInMatrix) {wcout << L"В матрице нет отрицательных элементов" << endl ; }
}
// Функция для генерации матрицы

void GenerateMatrix(int matrix[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int row_ind = 0 ; row_ind < ROWS_COUNT; row_ind++)
    {
        for (int col_ind = 0 ; col_ind < COLUMNS_COUNT ; col_ind++)
        {
            matrix[row_ind][col_ind] = rand() % 21 - 10 ;
        }
    }
}

// Функция для вывода матрицы на экран

void PrintMatrix(int matrix[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int row_index = 0 ; row_index < ROWS_COUNT; row_index++)
    {
        for (int col_index = 0 ; col_index < COLUMNS_COUNT  ; col_index++ )
        {
            wcout << setw(5) <<  matrix[row_index][col_index] << "\t" ;
        }
        wcout << endl ;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int matrix[ROWS_COUNT][COLUMNS_COUNT] ;

    GenerateMatrix(matrix) ;
    // Принудительно зануляем некоторые элементы
    matrix[0][3] = 0 ;
    matrix[2][4] = 0 ;
    matrix[4][4] = 0 ;

    wcout << L"Исходная матрица : " << endl ;
    PrintMatrix(matrix) ;
    // Вызываем функцию подсчёта отрицательных элементов
    HowManyMinusElems(matrix) ;



    return 0;
}
