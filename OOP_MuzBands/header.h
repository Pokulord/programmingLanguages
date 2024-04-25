#ifndef MUZBANDS_H
#define MUZBANDS_H
#include <string>
using namespace std;

enum class Statuses : int {
	Active = 1,
	Paused = 2,
	Not_Active = 3,
	Unknown = 4
};
enum class Muz_genres : int
{
	Grunge=1,
	Metal=2,
	Post_Punk=3,
	Electronic=4,
	Unknown = 0
};

// Basic class
class Default_band {
protected:
    int foundation_year = 0;
    string band_name;
	int albums_count = 0;
	Muz_genres Genre = Muz_genres::Unknown;
	Statuses band_status = Statuses::Unknown;
	int Totally_listens = 0;
    Default_band()
    {
        band_name = "Noname";
    }

public:
	virtual void WhatSBandName() const { cout << L"Название группы :" << band_name; }
//	virtual void ChangeBandName(string new_name) = 0 ;
	virtual Statuses GetBandStatus() const { return band_status; }
	virtual void PlaySong() const = 0;
//	virtual void ChangeGenre() = 0;
//	virtual Muz_genres WhatGenre() const = 0;

};


// Группа, которая выступает в стиле Grunge
class Grunge_band : public Default_band {
protected:
public:
    Grunge_band() : Default_band() {Genre = Muz_genres::Grunge ;};
//    void ChangeBandName(string new_name)
//    {
//        band_name = new_name ;
//    }
	void PlaySong() const override {
		cout << "Играем, но грязно. Получаются классные песни";
	};
//	void ShootInHead() const {
//		cout << "Ура! Я встречусь с Куртом Кобейном!!!!" << endl;
//	};
//	Muz_genres WhatGenre() { return Muz_genres::Grunge; }
};


class Metal_band : public Default_band {
protected:
	Metal_band();
public:
	void PlaySong() {
		cout << "Рубим в пониженном строе. Громко кричим в процессе." << endl;

	};

	void GetDrunk() {
		cout << "Все металлисты пьют. Конечно же, чай с лимончиком!" << endl;
	};
};
#endif

