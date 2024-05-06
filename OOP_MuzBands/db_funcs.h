#pragma once
#ifndef db_funcsH

// Функции для базы данных


sqlite3* MuzBands;


Bands_DB_container::Bands_DB_container()
{

	int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK){wcout << L"При открытиии базы данных возникла ошибка!" << endl;}

    char* errmsg;
    int created_database = sqlite3_exec(MuzBands, "DROP TABLE IF EXISTS bands_table; CREATE TABLE bands_table (band_name text, status int, genre int, listeners_count int); DELETE FROM bands_table", NULL, NULL, &errmsg);
    if (created_database != SQLITE_OK){wcout << errmsg << endl; wcout << L"Ошибка при создании таблицы" << endl;}
}


Bands_DB_container::~Bands_DB_container()
{
    int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK) { wcout << L"Ошибка при удалении" << endl; }


    char* errmsg;
    int deleted_database = sqlite3_exec(MuzBands, "DROP TABLE IF EXISTS bands_table;", NULL, NULL, &errmsg);
    if (deleted_database != SQLITE_OK) { wcout << errmsg << endl; wcout << L"Ошибка при удалении таблиц" << endl; }
    sqlite3_close(MuzBands);
}


void Bands_DB_container::AddBand(BandPtr new_band)
{

    int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK) { wcout << L"Ошибка при открытии БД при попытке добавить новую запись" << endl; }

    char* errmsg;
    int addBand = sqlite3_exec( MuzBands, string("INSERT INTO bands_table VALUES (" + string("\"") +  string(new_band->GetBandName()) + string("\"") + string("") + string(", ")\
        + to_string(static_cast<int>(new_band->GetBandStatus())) + string(", ") + to_string(static_cast<int>(new_band->WhatGenre())) + string(", ") + to_string(new_band->how_many_listeners())
        + string(")")).c_str(), NULL, NULL, &errmsg);

    if (addBand != SQLITE_OK) { wcout << errmsg << endl; wcout << L"Ошибка при добавлении записи!@!!" << endl; }
    else {wcout << L"Запись добавлена успешно!!!" << endl ;}

}


int Bands_DB_container::GetCount() const
{
    sqlite3* MuzBands;
    int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK) { wcout << L"При открытии БД произошла ошибка" << endl; }

    int count = 0;
    sqlite3_stmt* pStatement;
    int createGetCount = sqlite3_prepare_v2(MuzBands, "SELECT COUNT (*) FROM bands_table", -1, &pStatement, NULL);
    if(createGetCount != SQLITE_OK)
    {
        const char* errmsg = sqlite3_errmsg(MuzBands);
        wcout << errmsg << endl;
        wcout << L"При подсчёте количества записей произошла ошибка" << endl;
    }

    int getCount = sqlite3_step(pStatement);
    if (getCount == SQLITE_ROW)
    {
        count = sqlite3_column_int(pStatement, 0);

    }
    else
    {
        const char* errmsg = sqlite3_errmsg(MuzBands);
        wcout <<  errmsg << endl;
        wcout << L"При подсчёте количества записей произошла ошибка" << endl;
    }
    sqlite3_finalize(pStatement);
    return count;
}



bool DataBaseBandstIterator::IsDone() const
{
    sqlite3* MuzBands;
    int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK) { wcout << L"Ошибка открытия БД" << endl; }

    sqlite3_stmt* pStatement;
    int createGetCount = sqlite3_prepare_v2(MuzBands, "SELECT COUNT(*) FROM bands_table;", -1, &pStatement, NULL);
    if (createGetCount != SQLITE_OK)
    {
        wcout << L"Ошибка при проверке окончания выполнения" << endl;
        const char* errmsg2 = sqlite3_errmsg(MuzBands);
        wcout << errmsg2 << endl;

    }

    int Bands_counter = 0;
    int getCount = sqlite3_step(pStatement);
    if (getCount == SQLITE_ROW)
    {
        Bands_counter = sqlite3_column_int(pStatement, 0);
    }
    else
    {
        wcout << L"Ошибкa" << endl;
        const char* errmsg1 = sqlite3_errmsg(MuzBands);
        wcout << errmsg1 << endl;

    }

    sqlite3_finalize(pStatement);
    return position == Bands_counter ;
}


BandPtr DataBaseBandstIterator::GetCurrent() const
{
    sqlite3* MuzBands;
    int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK) { wcout << L"Ошибка открытия БД " << endl; }


    sqlite3_stmt* pStatement;
    int prep = sqlite3_prepare(MuzBands, string("SELECT band_name,status,genre,listeners_count,rowid FROM bands_table WHERE rowid = " + to_string(position)).c_str(), -1, &pStatement, NULL);
    if (prep != SQLITE_OK)
    {
        wcout << L"Ошибка позиционирования" << endl;
        string err = sqlite3_errstr(prep);
        cout << err << endl;
        const char* errmsg = sqlite3_errmsg(MuzBands);
        wcout << errmsg << endl;

    }

    int stepRes = SQLITE_DONE;
    while (true)
    {
        int stepRes = sqlite3_step(pStatement);
        if (stepRes != SQLITE_ROW) { sqlite3_finalize(pStatement); break; }

        Muz_genres genre = Muz_genres(sqlite3_column_int(pStatement, 1));
        Statuses band_status = Statuses(sqlite3_column_int(pStatement, 2));
        bool is_atmos = sqlite3_column_int(pStatement, 3) ;
        sqlite3_finalize(pStatement);

        switch (genre)
        {
        case Muz_genres::Grunge: return new Grunge_band();
        case Muz_genres::Post_Punk: return new Post_Punk_band() ;
        case Muz_genres::Metal: return new Metal_band();
        }


    }

}
#endif // db_funcsH
