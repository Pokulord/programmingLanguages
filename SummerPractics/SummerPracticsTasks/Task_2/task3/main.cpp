#include <iostream>
using namespace std;




// Функция, которая возращает указатель на строку по номеру дня
const wchar_t* WhatDayOfWeek(int day_num)
{
    // Массив с названиями дней недели
    const wchar_t* days[] = {
    L"Понедельник",
    L"Вторник",
    L"Среда",
    L"Четверг",
    L"Пятница",
    L"Суббота",
    L"Воскресенье"};
    // Номер дня недели должен быть числом не меньше 1 и не больше 7
    // Возвращаем указатель
    return days[day_num-1] ;
}

int main()
{
    int day_of_week_num  ;
    setlocale(LC_ALL, "Russian") ;
    // Ввод номера дня недели
    wcout << L"Введите номер дня недели (от 1 до 7)" << endl;
    cin >> day_of_week_num ;
    if (day_of_week_num <=0 || day_of_week_num > 7)
    {
        wcout << L"Введите корректный номер дня недели" << endl ;
        return -1 ;
    }
    // Вызов функции и вывод результатов
    const wchar_t* day = WhatDayOfWeek(day_of_week_num) ;
    wcout << L"День с номером " << day_of_week_num << "  " <<  day << endl ;
    return 0;
}
