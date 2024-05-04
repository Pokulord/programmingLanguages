#pragma once
#ifndef db_funcsH

// Функции для базы данных



Bands_DB_container::Bands_DB_container()
{
    sqlite3* MuzBands;
	int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK){wcout << L"При открытиии базы данных возникла ошибка!" << endl;}

    char* errmsg;
    int created_database = sqlite3_exec(MuzBands, "DROP TABLE IF EXISTS bands; CREATE TABLE bands (band_name text, status int, genre int, listeners_count int); DELETE FROM bands", NULL, NULL, &errmsg);
    if (created_database != SQLITE_OK){wcout << errmsg << endl; wcout << L"Ошибка при создании таблиц" << endl;}
}


Bands_DB_container::~Bands_DB_container()
{
    sqlite3* MuzBands;
    int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK) { wcout << L"Ошибка при удалении" << endl; }


    char* errmsg;
    int deleted_database = sqlite3_exec(MuzBands, "DROP TABLE IF EXISTS bands;", NULL, NULL, &errmsg);
    if (deleted_database != SQLITE_OK) { wcout << errmsg << endl; wcout << L"Ошибка при удалении таблиц" << endl; }
    sqlite3_close(MuzBands);
}


void Bands_DB_container::AddBand(BandPtr new_band)
{
    sqlite3* MuzBands;
    int openResult = sqlite3_open16(L"bands.db", &MuzBands);
    if (openResult != SQLITE_OK) { wcout << L"Ошибка при открытии БД при попытке добавить новую запись" << endl; }

    char* errmsg;
    int addPlane = sqlite3_exec( MuzBands, string("INSERT INTO bands (band_name, status, genre, listeners_count) VALUES (" + new_band->GetBandName() + string(", ")\
        + to_string(static_cast<int>(new_band->GetBandStatus())) + string(", ") + to_string(static_cast<int>(new_band->WhatGenre())) + string(", ") + to_string(new_band->how_many_listeners())
        + string(")")).c_str(), NULL, NULL, &errmsg);

    if (addPlane != SQLITE_OK) { wcout << errmsg << endl; wcout << L"Ошибка при добавлении записи" << endl; }

}
#endif // db_funcsH
