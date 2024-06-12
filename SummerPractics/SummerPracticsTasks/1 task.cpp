#include <iostream>

using namespace std;


// Функция для нахождения квадратного корня методом Ньютона
double sqrt_newton(double num) {
    // Начальное приближение: берем само число num как x и единицу как y
    double x = num;
    double y = 1.0;
    // Значение точности, до которой хотим вычислить квадратный корень
    double epsilon = 0.000001; // точность
    // В каждой итерации улучшаем приближения x и y
    while (x - y > epsilon) {
        // Новое приближение x является средним арифметическим текущих x и y
        x = (x + y) / 2;
        // Новое приближение y вычисляется как num, деленное на текущее значение x
        y = num / x;
    }
    // Итоговое значение. которое равняется корню из числа, которое поступило на вход
    return x;
}

int main()
{

    double side1, side2 ;
    setlocale(LC_ALL, "Russian") ;
    // Ввод длин сторон a и b
    wcout << L"Введите длину стороны a" << endl;
    cin>>side1;
    wcout << L"Введите длину стороны b" << endl;
    cin>>side2;
    // Проверка на корректность ввода (больше нуля и числовой тип)
    if (side1 <= 0 || side2 <=0)
    {
        wcout << L"Длины сторон должны быть положительными и не должны равняться 0" << endl;
        return -1;
    }
    // √(a**2+b**2)
    // Значение диагонали без корня
    double diagonal_withno_sqtr = side1*side1+side2*side2 ;
    // Значение диагонали с корнем (вызываем функцию, которая отвечает за это)
    double diagonal_with_sqtr = sqrt_newton(diagonal_withno_sqtr) ;
    wcout << L"Длина диагонали : " << diagonal_with_sqtr << endl ;
    return 0;




}
