#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian") ;
    // Открываем файл, содержимое которого необходимо скопировать
    wifstream initial_file("initial_file.txt") ;
    // Если файл открыт успешно
    if (initial_file.is_open())
    {
        wofstream final_file("final_file.txt") ;
        wcout << L"Файл успешно открыт" << L"\nСодержимое файла: " <<  endl ;
        // Задаём переменную, в которую будем записывать каждую строку файла
        // В дальнейшем изначальный файл будем перебирать построчно
        wstring line ;
        // Запускаем цикл построчного перебора содержимого файла
        while (getline(initial_file, line))
        {
            wcout << line << endl ;
            // Записываем строку в файл
            final_file << line << endl ;
        }
        // Послесловие от автора
        final_file << "--------------\nCopied by Svyat" << endl ;

        wcout << L"\n\nКопирование произведено успешно!" << endl ;
        // Закрываем файлы, с которыми производилась работа
        initial_file.close();
        final_file.close();
    }
    // В случае, если файл не удалось открыть
    else {
        wcout << L"Ошибка при отрытии файла. Возможно, неправильно указано имя" << endl ;
        return -1 ;
    }

    return 0;
}
