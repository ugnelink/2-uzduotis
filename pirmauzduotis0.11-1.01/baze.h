#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class baze { 
private:
	string vardas; string pavarde; float vid; vector< int >paz; int kiekis; float egz; float galutinismed; float galutinisvid; float sum = 0; float med;
public:
	baze() {
		vardas = ""; pavarde = ""; vid = 0; kiekis = 0; egz = 0; galutinisvid = 0; galutinismed = 0; med = 0;
	}
	void setvardas(string var) {vardas=var; }
	string getvardas()const { return vardas; }
	void setpavarde(string pav) { pavarde = pav; }
	string getpavarde()const { return pavarde; }
	void setkiekis(int  kiek) { kiekis = kiek; }
	int getkiekis()const { return kiekis; }
	void setpaz(vector< int >pazym) { paz = pazym; }
	vector< int > getpaz()const { return paz; }
	void setegz(float egzam) { egz = egzam; }
	float getegz()const { return egz; }
	void setgalutinisvid() { galutinisvid = vid*0.4+egz*0.6; }
	float getgalutinisvid()const { return galutinisvid; }
	void setgalutinismed() { galutinismed = med*0.4+egz*0.6; }
	float getgalutinismed()const { return galutinismed; }
	void setsum(float suma) { sum = suma; setvid(); }
	float getsum()const { return sum; }
	void setvid() {vid = sum / kiekis; }
	float getvid()const { return vid; }
	void setmed(float median) { med = median;}
	float getmed()const { return med; }
};


