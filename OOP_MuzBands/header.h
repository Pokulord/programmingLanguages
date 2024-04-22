#ifndef MUZBANDS_H
#define MUZBANDS_H
#include <string>
using namespace std;

enum class Statuses : int {
	Active,
	Paused,
	Not_Active
};
enum class Muz_genres : int
{
	Grunge,
	Metal,
	Post_Punk,
	Electronic
};


class Default_band {
protected:
	Default_band();
	string band_name = "Noname";
	int foundation_year;
	int albums_count = 0;
	Muz_genres genre;
	Statuses band_status;
	int Totally_listens;

public:
	virtual string WhatSBandName() const { return band_name; }
	virtual void ChangeBandName() = 0 ;
	virtual Statuses GetBandStatus() const { return band_status; }
	virtual void PlaySong() const = 0;
	virtual void ChangeGenre() = 0;
	virtual Muz_genres WhatGenre() const = 0;

};

class Grunge_band : public Default_band {
protected:
	Grunge_band();
public:
	void PlaySong() {
		cout << "Играем, но грязно. Получаются классные песни";
	};
	void ShootInHead() {
		cout << "Ура! Я встречусь с Куртом Кобейном!!!!" << endl;
	};
	Muz_genres WhatGenre() { return Muz_genres::Grunge; }

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
