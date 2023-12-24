#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <sstream>

/* dirent.h нужен
для работы с каталогами
*/
using namespace std;
// Функция уиножения
void multiPly(const string&filename, string path)
{
    ifstream inputFile(filename);
    if (inputFile.is_open()){
        string line;
        ofstream fileOut(path + "\\mnoz.txt");
        fileOut << "File " << filename  << ", * 2 =" << "\n---------------" << std::endl ;
        while (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
            std::string element;
            while (iss >> element)
            {
               fileOut << stoi(element) * 2 << " ";
            }


        }
        std::wcout << L"Файл сохранён" << std::endl ;
        inputFile.close();
        fileOut.close();

    }

    else {
        std::wcout << L"Файл не открыт" << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "");
    // Путь к файлам
    std::string path = "Files_to_Read\\";
    DIR* dir;
    struct dirent *ent;
    // Проверяем, пустой ли каталог
    if ((dir = opendir(path.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string filename = ent->d_name;
            // Выполняем чтение файла, если он с расширением .txt
            if (filename.length() > 4 && filename.substr(filename.length()-4) == ".txt") {
                cout << "File : " << filename << ": " << endl;
                // Считываем файлы из каталога
                std::ifstream file(path + "/" + filename);
                // Задаём строку
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                }
                file.close();

                std::cout << "------------------------" << std::endl;
            }
        }
        closedir(dir);
    } else {
        std::wcout << L"Ошибка при открытии каталога - возможно, неправильно указан путь" << std::endl;
        return EXIT_FAILURE;
    }
    // Имя файла, содержимое которого необходимо умножить на 2
    multiPly(path + "\\1.txt", path);
    return 0;
}
