#include <sstream>
#include <iostream>
#include <list>
#include "header.h"
using namespace std;


wstring PrintBandStatus (const Statuses Status)
{
    switch(Status)
    {
        case Statuses::Active : return L"Активна" ;
        case Statuses::Paused : return L"Деятельность приостановлена" ;
        case Statuses::Not_Active : return L"Неактивна" ;
        default : return L"Незвестно" ;
    }
}

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
        case Muz_genres::Post_Punk: return new Post_Punk_band();
        default : return 0 ;
    }
}


// Задачи


// Задача 1. Запретить всем металлистам пить чай
void Task_1_no_more_tea(Iterator<BandPtr> *Iterator)
{
    int no_tea_counter = 0 ;
    for (Iterator->First(); !Iterator->IsDone() ; Iterator->Next())
    {
        const BandPtr CurBand = Iterator->GetCurrent();
        CurBand->NoTea();
        no_tea_counter++;
        wcout << PrintBandGenre(CurBand->WhatGenre()) << endl ;

    }

    wcout << L"Отныне металлисты не пьют ничего - в том числе, чай" << endl ;
    wcout << L"Чая лишены " << no_tea_counter << L" группы/групп" << endl ;

}

// Задача 2. Увеличить популярность групп, которые выступают в жанре Grunge
void Do_more_popular_all_grunge_bands(Iterator<BandPtr> *Iterator)
{
    wcout << L"Астрологи объявили неделю гранжа" << endl ;
    for (Iterator->First(); !Iterator->IsDone() ; Iterator->Next())
    {
        int how_many_poplular = rand() % (100-50 + 1) + 50 ;
        const BandPtr CurBand = Iterator->GetCurrent();
        CurBand->Add_listeners(how_many_poplular);
        wcout << L"Количество прослушиваний группы в жанре : ";
        wcout << PrintBandGenre(CurBand->WhatGenre()) ;
        wcout << L"  Увеличено на " << how_many_poplular << endl ;
        how_many_poplular = 0 ;


    }
}

// Задача 2 - Сделать группы активными

void MakeActive(Iterator<BandPtr> *Iterator)
{
    wcout << L"Правительство решило поддержать все неактивные группы. Их деятельность возобновлена!!!" << endl ;
    int how_many = 0 ;
    for (Iterator->First(); !Iterator->IsDone() ; Iterator->Next())
    {
        const BandPtr CurBand = Iterator->GetCurrent();
        CurBand->ChangeStatus(Statuses::Active);
        how_many++ ;


    }
    wcout << how_many << L" групп теперь активны." << endl ;
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

    for (int i=0; i < rand()%400+501; i++)
    {
        first_cont.AddBand(Create_new_band(static_cast<Muz_genres>(rand()%(3)+1)));
    }


    for (int i=0; i < rand()%400+501; i++)
    {
        second_cont.AddBand(Create_new_band(static_cast<Muz_genres>(rand()%(3)+1)));
    }
    wcout << L"В списке: " << first_cont.GetCount() << L" элемента/элементов" << endl ;

    // Для металлистов
//    Iterator<BandPtr> *Iterator = new BandTypeDecorator(second_cont.GetIterator(), Muz_genres::Metal);
//    Task_1_no_more_tea(Iterator);
////    Task1(&first_cont);
//    Iterator<BandPtr> *Iterator = new BandTypeDecorator(second_cont.GetIterator(), Muz_genres::Grunge);
//    Do_more_popular_all_grunge_bands(Iterator);
    // Для восстановления активных групп, которые играют атмосферно
    Iterator<BandPtr> *Iterator = new AtmosphericDecorator( new BandStatusDecorator(second_cont.GetIterator(), Statuses::Not_Active), true);
    MakeActive(Iterator) ;

    return 0;
}
