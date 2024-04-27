#include <iostream>
#include "header.h"
using namespace std;


wstring PrintBandGenre( const Muz_genres Genre)
{
    switch(Genre)
    {
        case Muz_genres::Grunge: return L"Жанр Grunge";
        case Muz_genres::Metal: return L"Жанр Metal";
        case Muz_genres::Post_Punk: return L"Жанр Post-punk";
        case Muz_genres::Electronic: return L"Жанр Electronic";
        default: return L"Неизвестный науке жанр" ;
    }
}


Default_band *Create_new_band(Muz_genres Genre)
{
    switch(Genre)
    {
        case Muz_genres::Grunge: return new Grunge_band() ;
        case Muz_genres::Metal: return new Metal_band() ;
        default : return 0 ;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    wcout << L"Привет!!" ;
    return 0;
}
