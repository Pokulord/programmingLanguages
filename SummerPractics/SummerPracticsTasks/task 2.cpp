#include <iostream>
#include <vector>

// Функция для проверки, является ли число совершенным
bool isPerfect(int num) {
    int sum = 1; // начинаем с 1, потому что 1 всегда делитель

    // Находим все делители числа num
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Число является совершенным, если сумма его делителей равна самому числу
    return sum == num;
}

int main() {
    int n;

    // Запрашиваем у пользователя ввод натурального числа
    std::cout << "Введите натуральное число n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Пожалуйста, введите натуральное число больше 0." << std::endl;
        return 1;
    }

    std::vector<int> perfectNumbers;

    // Ищем все совершенные числа на отрезке от 1 до n
    for (int i = 2; i <= n; ++i) {
        if (isPerfect(i)) {
            perfectNumbers.push_back(i);
        }
    }

    // Выводим результаты
    std::cout << "Совершенные числа на отрезке от 1 до " << n << ": ";
    if (perfectNumbers.empty()) {
        std::cout << "нет совершенных чисел.";
    } else {
        for (int num : perfectNumbers) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

