#include <iostream>
#include <vector>


using namespace std;
// Функция для проверки, является ли число совершенным
// Число является совершенным, если сумма его делителей равна самому числу
bool isPerfect(int num) {
    int sum = 0; // иизначальное значениее суммы

    // Находим все числа, на которые число делится без остатка
    for (int i = 1; i < num ;++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Возвращаем логический аргумент, совершенное ли число
    return sum == num;
}

int main() {
    int n;
    setlocale(LC_ALL, "Russian") ;
    // Запрашиваем у пользователя ввод натурального числа
    wcout << L"Введите натуральное число n: ";
    cin >> n;

    if (n <= 0) {
        wcout << L"Пожалуйста, введите натуральное число больше 0." << endl;
        return 1;
    }
    // Массив, в котором храним совершенные числа с целью последующего вывода
    vector<int> perfectNumbers;

    // Ищем все совершенные числа на отрезке от 1 до n
    for (int i = 1; i <= n; ++i) {
        // Если совершенное - добавляем в массив
        if (isPerfect(i)) {
            perfectNumbers.push_back(i);
        }
    }

    // Выводим все совершенные числа
    wcout << L"Совершенные числа на отрезке от 1 до " << n << ": ";
    // Если пустой
    if (perfectNumbers.empty()) {
        wcout << L"Нет совершенных чисел.";
    } else {
        for (int num : perfectNumbers) {
            wcout << num << " ";
        }
    }
    cout << endl;

    return 0;
}

