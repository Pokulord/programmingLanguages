#include <iostream>
#include <cstdlib>
using namespace std;


// Размер массива. Помещаем его в глобальную область видимости
const int ARRAY_SIZE = 15 ;


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
// Функция для разделения массива по чётным и нечётным индексам
// И их последующей сортировки
void sortEvenAndOdd(int* arr, int sizear)
{
    // Массивы для чётных и нечётных элементов
    int EvenArr[ARRAY_SIZE/2 +1], OddArr[ARRAY_SIZE/2]  ;
    // Индексы для чётных и нечётных элементов
    int EvenIndex = 0, OddIndex = 0 ;
    // Разделяем чётные и нечётные элементы массива
    for (int index = 0; index < sizear; index++)
    {
        if (index % 2 == 0) {EvenArr[EvenIndex++] = arr[index];}
        else {OddArr[OddIndex++] = arr[index];}
    }
    // Сортируем массивы чётных и нечётных элементов
    sortArray(EvenArr, EvenIndex) ;
    sortArray(OddArr, OddIndex) ;
    wcout << L"Отсортированные по чётным и нечётным индексам элементы : " << endl ;
    EvenIndex = OddIndex = 0 ;
    // Перезаписываем исходный массив отсортированными элементами
    for (int i = 0; i < sizear; ++i) {
        if (i % 2 == 0) {
            arr[i] = EvenArr[EvenIndex++];
        } else {
            arr[i] = OddArr[OddIndex++];
        }
    }
}
// функция для вычисления суммы до минимального элемента
int SumPerMinimalElem(const int* arr, int sizear)
{
    int sum = 0 ;
    // Изначально минимальный элемент - самый первый
    int minimal_elem = arr[0];
    // Индекс минимального элемента
    int min_elem_ind = 0 ;
    for (int index = 0 ; index < sizear; index++)
    {
        // Если элемент меньше того, что ранее был минимальным - перезаписываем
        if (arr[index] <= minimal_elem)
        {
            minimal_elem = arr[index] ;
            min_elem_ind = index ;


        }
    }
    wcout << L"\nМинимальный элемент массива : " << minimal_elem << endl ;
    wcout << L"\nИндекс минимального элемента : " << min_elem_ind << endl ;
    // Вычисляем сумму до минимального элемента
    for (int index = 0 ; index < min_elem_ind; index++)
    {
        sum+= arr[index] ;
    }
    return sum ;
}
// Функция для вычисления произведения положительных элементов массива

int ProductOfPositive(const int* arr, int sizear)
{
    // Изначальное значение суммы
    int product = 1;
    // Логическая переменная для проверки наличия хотя бы одного положительного элемента массива
    bool PositiveInArray = false;
    // Перебираем массив
    for (int index; index < sizear; index++)
    {
        // Если положительное - умножаем
        if (arr[index] > 0)
        {
            product *= arr[index] ;
            PositiveInArray = true;
        }
    }
    // Если положительных элементов нет - возвращаем 0
    if (!PositiveInArray) {product = 0 ;}
    return product ;
}

int main()
{
    setlocale(LC_ALL, "Russian") ;
    // Размер массива
    int array_of_digits[ARRAY_SIZE] ;
    // Заполняем массив случайными числами
    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        array_of_digits[index] = rand() % (10+10+1) - 10 ;
    }
    // Выводим
    wcout << L"Содержимое массива : ";
    for (int index = 0 ; index < ARRAY_SIZE ; index++)
    {
        wcout << array_of_digits[index] << " , " ;
    }
    wcout << endl ;
    wcout << L"Произведение положительных элементов массива : " << ProductOfPositive(array_of_digits, ARRAY_SIZE) << endl ;
    int sum_per_min_elem = SumPerMinimalElem(array_of_digits, ARRAY_SIZE) ;
    wcout << L"Сумма до минимального элемента: " << sum_per_min_elem << endl ;
    sortEvenAndOdd(array_of_digits, ARRAY_SIZE) ;
    for (int index = 0 ; index < ARRAY_SIZE; index++)
    {
        wcout << array_of_digits[index] << " , " ;
    }
    wcout << endl ;
    return 0;
}
