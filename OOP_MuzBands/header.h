#ifndef MUZBANDS_H
#define MUZBANDS_H
#include <string>
#include <vector>
#include "Decorators.h"
using namespace std;

enum class Statuses : int {
	Active = 1,
	Paused = 2,
	Not_Active = 3,
	Unknown = 0
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
    string band_name = "NoNameeeee" ;
	int albums_count = 0;
	Muz_genres Genre = Muz_genres::Unknown;
	Statuses band_status = static_cast<Statuses>(rand()%(4)+1);
	int Totally_listens = 0;
	bool IsThatAtmospheric = (rand() % 100)/2 ;
public:
        Default_band()
    {
    }
    string GetBandName() const {return band_name;}
	void WhatSBandName()
	{
	     cout << GetBandName() << endl ;
    }
	virtual void ChangeBandName(string new_name)
	{
	    band_name = new_name ;
	};
	virtual Statuses GetBandStatus() const { return band_status; }
	virtual void PlaySong() const = 0;
	virtual void ChangeStatus(Statuses new_status)
	{
	    band_status = new_status ;
	};
	virtual Muz_genres WhatGenre() const
	{
	    return Genre;
	};
	virtual void NoTea() = 0 ;
	void Add_listeners (int howmany_listeners)
	{
	    Totally_listens= Totally_listens + howmany_listeners ;
	};

	bool IsThisAtmos()
	{
	    if (IsThatAtmospheric)
        {
            return true;
        }
        else
        {
            return false;
        }
	};
	int how_many_listeners() const {return Totally_listens ;}

};


typedef Default_band *BandPtr ;

// Группа, которая выступает в стиле Grunge
class Grunge_band : public Default_band {
protected:
   string band_name = "SomethingGrungeGroup" ;
public:
    Grunge_band() : Default_band() {Genre = Muz_genres::Grunge ;};
	void PlaySong() const override {
		wcout << L"Играем, но грязно. Получаются классные песни";
	};
	void ShootInHead() const {
		wcout << L"Ура! Я встречусь с Куртом Кобейном!!!!" << endl;
	};
	void NoTea() {} ;
};

// Группа , которая выступает в жанре Metal
class Metal_band : public Default_band {
protected:
    // А пьёт ли металлист чай
    bool IsDrinkingTea = true ;
public:
    Metal_band() : Default_band() {Genre = Muz_genres::Metal ;};
	void PlaySong() const override {
		wcout << L"Рубим в пониженном строе. Громко кричим в процессе." << endl;

	};

	void NoTea()
	{
	  IsDrinkingTea = false ;
	};

	void GetDrunk() {
		wcout << L"Все металлисты пьют. Конечно же, чай с лимончиком!" << endl;
	};

    Muz_genres WhatGenre() const {return Muz_genres::Metal;}



};

class Post_Punk_band : public Default_band
{
protected:
public:
    Post_Punk_band() : Default_band() {Genre = Muz_genres::Post_Punk ;};
    void PlaySong() const override
    {
       wcout << L"Играем крайне атмосферную музыку" << endl ;
    }

    void SoAtmosphere() const
    {
        wcout << L"Музыка оказалась настолько атмфосферной, что слушатель проникся" << endl;
    }
    void NoTea() {} ;
};

// Итераторы для обхода контейнеров

class FContainerIterator : public Iterator<BandPtr>
{
private:
    const list <BandPtr> *FBandCont ;
    list <BandPtr>::const_iterator Iterator;
public:
    void First(){Iterator = FBandCont->begin();}
    void Next() {Iterator++;}
    bool IsDone() const {return Iterator == FBandCont->end();}
    BandPtr GetCurrent() const {return *Iterator ;}
    FContainerIterator(const list<BandPtr> *Fbandcont)
    {
        FBandCont = Fbandcont;
        Iterator = FBandCont->begin();
    }

};
// Контейнеры

class Container
{
public:
    virtual void AddBand (BandPtr ) = 0 ;
    virtual int GetCount() const = 0 ;
    virtual Iterator<BandPtr> *GetIterator() = 0;
};

class FContainer : public Container
{
private:
    list<BandPtr> BandFCont;

public:
    void AddBand(BandPtr New_band)
    {
        BandFCont.push_back(New_band);
    }
    int GetCount() const {return BandFCont.size() ;}

    Iterator<BandPtr> *GetIterator()
    {
        return new FContainerIterator(&BandFCont);
    };
};



class VContainerIterator : public Iterator<BandPtr>
{
private:
	const vector <BandPtr> *BandVCont;
	vector <BandPtr>::const_iterator Iterator;

public:
	void First(){Iterator = BandVCont->begin();}
	void Next() {Iterator++;}
	bool IsDone() const {return Iterator == BandVCont->end();}
	BandPtr GetCurrent() const { return *Iterator; }
    VContainerIterator(const vector<BandPtr> *BandVCont)
    {
		BandVCont = BandVCont;
		Iterator = BandVCont->begin();
	}
};



class VContainer : public Container
{
private:
    vector<BandPtr> BandVCont;

public:
    void AddBand(BandPtr New_Band) {BandVCont.push_back(New_Band);}
    int GetCount() const {return BandVCont.size();}
    BandPtr GetByIndex(int index) {return BandVCont[index];}

   Iterator<BandPtr> *GetIterator()
    {
        return new VContainerIterator(&BandVCont);
    };
};


// Для работы с БД
class DataBaseBandstIterator : public Iterator<BandPtr>
{
private:
	sqlite3* MuzBands;
	int position = 1;
public:
	DataBaseBandstIterator(sqlite3* muzBands) { MuzBands = muzBands; }
	void First() { position = 1; }
	void Next() { position++; }
	bool IsDone() const;
	BandPtr GetCurrent() const;
};



class Bands_DB_container : public Container
{
private:
	sqlite3* MuzBands;

public:
	void AddBand(BandPtr new_band);
	int GetCount() const;
	Bands_DB_container();
	~Bands_DB_container();

	Iterator<BandPtr>* GetIterator()
	{
		return new DataBaseBandstIterator(MuzBands);
	};
};



class BandTypeDecorator : public IteratorDecorator<BandPtr>
{
private:
    Muz_genres TargetType;
public:
    BandTypeDecorator(Iterator<BandPtr> *Iterator, Muz_genres targetype) : IteratorDecorator(Iterator)
    {
        TargetType = targetype ;
    }

    void First()
    {
        Decorator->First();
        while (!Decorator->IsDone()&& Decorator->GetCurrent()->WhatGenre()!=TargetType)
        {
            Decorator->Next();
        }
    }

    void Next()
    {
        do
        {
            Decorator->Next();
        }
        while(!Decorator->IsDone()&&Decorator->GetCurrent()->WhatGenre()!= TargetType);
    }
};


class BandStatusDecorator : public IteratorDecorator<BandPtr>
{
private:
    Statuses StatusType;
public:
    BandStatusDecorator(Iterator<BandPtr> *Iterator, Statuses statustype) : IteratorDecorator(Iterator)
    {
        StatusType = statustype ;
    }

    void First()
    {
        Decorator->First();
        while (!Decorator->IsDone()&& Decorator->GetCurrent()->GetBandStatus()!=StatusType)
        {
            Decorator->Next();
        }
    }

    void Next()
    {
        do
        {
            Decorator->Next();
        }
        while(!Decorator->IsDone()&&Decorator->GetCurrent()->GetBandStatus()!= StatusType);
    }
};


class AtmosphericDecorator : public IteratorDecorator<BandPtr>
{
private:
    bool IsAtmos;
public:
    AtmosphericDecorator(Iterator<BandPtr> *Iterator, bool isAtmos) : IteratorDecorator(Iterator)
    {
        IsAtmos = isAtmos;
    }

    void First()
    {
        Decorator->First();
        while (!Decorator->IsDone()&& Decorator->GetCurrent()->IsThisAtmos()!=IsAtmos)
        {
            Decorator->Next();
        }
    }

    void Next()
    {
        do
        {
            Decorator->Next();
        }
        while(!Decorator->IsDone()&&Decorator->GetCurrent()->IsThisAtmos()!= IsAtmos);
    }
};
#endif

