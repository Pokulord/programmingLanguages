#include <iostream>
#include <cstdlib>
using namespace std;



// Размер массива (число букв имени и фамилии)
const int ARRAY_SIZE = 17 ;

// Функция для сортировки массива методом пузырька

void sortArray(int* arr, int sizear) {
    // Перебираем все элементы массива
    for (int i = 0; i < sizear; ++i) {
        // Так как в первую итерацию один из элементов "всплывёт",
        // то диапазон на 1 меньше
        for (int j = 0; j < sizear-1; ++j) {
            // Если предшествующий элемент меньше - двигаем вперёд
            if (arr[j] > arr[j+1]) {
                // Временное значение предыдущего элемента
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Функция для вычисления модуля
int abs_func(int digit)
{
    // Модуль - расстояние, поэтому возвращаем обратное по знаку значение
    if (digit < 0) {return -digit;}
    return digit ;
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

// Функция для замены всех отрицательных элементов их квадратами
// И последующей сортировки получившегося массива
void ReplaceAndSort(int *arr)
{
    for (int index = 0; index < ARRAY_SIZE ; index++)
    {
        // Если элемент отрицательный - заменяем значение квадратом
        if (arr[index] < 0) {arr[index] *= arr[index] ;}
    }
    wcout << L"Массив с квадратами отрицательных чисел" << endl ;
    PrintArray(arr) ;
    // Сортируем массив
    sortArray(arr, ARRAY_SIZE) ;
    wcout << L"Отсортированный массив : " << endl ;
    PrintArray(arr) ;

}

// Функция для вычисления суммы элементов до минимального элемента
void SumBeforeMinElem(int arr[ARRAY_SIZE])
{
    // Сумма
    int sum = 0 ;
    // Изначальный индекс минимального элемента
    int min_elem_index = 0;
    // Изначальное значение минимального элемента
    int min_elem = abs_func(arr[0]) ;
    // Проходимся по массиву
    for (int index =0 ; index < ARRAY_SIZE; index++)
    {
        // Если модуль числа меньше минимального элемента - переприсваеваем значение и индекс
        if (abs_func(arr[index]) < min_elem & abs_func(arr[index]) !=  min_elem)
        {
            min_elem = abs_func(arr[index]) ;
            min_elem_index = index ;
        }
    }
    wcout << L"Минимальный элемент: " << min_elem << endl << L"Индекс минимального элемента " << min_elem_index << endl ;
    // Вычисляем сумму до минимального элемента
    for (int index = 0 ; index < min_elem_index ; index++) {sum+=abs_func(arr[index]);}
    wcout << L"Сумма до минимального элемента : " << sum << endl ;

}

// Функция для вычисленния количества отрицательных элементов
int HowManyMinusElems (int arr[ARRAY_SIZE])
{
    // Счётчик
    int minuselemscounter = 0 ;
    for (int index = 0 ; index < ARRAY_SIZE ; index++)
    {
        if (arr[index] < 0) {minuselemscounter++;}
    }
    return minuselemscounter ;
}

int main()
{
    setlocale(LC_ALL, "Russian") ;
    // Создаём динамический массив
    int *array_of_digits = new int[ARRAY_SIZE] ;

    // Заполняем массив случайными числами

    for (int index = 0 ; index < ARRAY_SIZE; index++)
    {
        array_of_digits[index] = rand() % 21 - 10 ;
    }
    wcout << L"Изначальное содержимое массива" << endl ;
    PrintArray(array_of_digits) ;
    wcout << L"Количество отрицательных элементов : " << HowManyMinusElems(array_of_digits) << endl  ;
    SumBeforeMinElem(array_of_digits) ;
    ReplaceAndSort(array_of_digits) ;
    // Очищаем память, удаляя массив
    delete array_of_digits ;
    return 0;
}
