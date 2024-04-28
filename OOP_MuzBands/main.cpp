#include <sstream>
#include <iostream>
#include <list>
#include "header.h"
using namespace std;


wstring PrintBandGenre( const Muz_genres Genre)
{
    switch(Genre)
    {
        case Muz_genres::Grunge: return L"Жанр Grunge";
        case Muz_genres::Metal: return L"Metal";
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
        case Muz_genres::Post_Punk: return new Post_Punk_band();
        default : return 0 ;
    }
}


// Задачи


// Задача 1. Запретить всем металлистам пить чай
void Task_1_no_more_tea(Iterator<BandPtr> *Iterator)
{
    for (Iterator->First(); !Iterator->IsDone() ; Iterator->Next())
    {
        const BandPtr CurBand = Iterator->GetCurrent();
        CurBand->NoTea();

    }

    wcout << L"Отныне металлисты не пьют ничего - в том числе, чай" << endl ;

}


void Task1(VContainer *bandbox)
{
    for (int i =0 ; i < bandbox->GetCount(); i++)
    {
        const BandPtr current_band = bandbox->GetByIndex(i) ;
        wcout << PrintBandGenre(current_band->WhatGenre()) << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    wcout << L"Привет!!" << endl ;

    VContainer first_cont ;
    FContainer second_cont ;
    Metal_band gb1 ;

    for (int i=0; i < rand()%400+501; i++)
    {
        first_cont.AddBand(Create_new_band(static_cast<Muz_genres>(rand()%(3)+1)));
    }
    wcout << L"В списке: " << first_cont.GetCount() << L" элемента/элементов" << endl ;

//    Iterator<BandPtr> *Iterator = new BandTypeDecorator(second_cont.GetIterator(), Muz_genres::Metal);
//    Task_1_no_more_tea(Iterator);
    Task1(&first_cont);
    return 0;
}
