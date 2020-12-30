
#include "funkcijos.h"
#include "Header5.h"
void antra(int irasusk);
int main() {
	vector <baze> studentai;
	int m; int h; int g; int p; 
	cout << "Jei norite atlikti spartos greicio analize, iveskite 1, jei nenorite, iveskite 0" << endl;
	cin >> p;
	iv_ir_tikr(p);
	
	if (p == 1) {

		antra(1000);  antra(10000); antra(100000); antra(1000000); antra(10000000); 
	}
	else {
		cout << " jei norite duomenis nuskaityti is failo, iveskite 1, jei nenorite iveskite 0 " << endl;
		cin >> h;
		iv_ir_tikr(h); 

		if (h == 1) {
			string failas;
			cout << "iveskite failo pavadinima" << endl;
			cin >> failas;
			nuskaitymas(failas, studentai);

			funkcija("rezultatai", studentai);
		}
		else {

			cout << "iveskite studentu skaiciu: " << endl;
			cin >> m;
			skaicius_ir_tikr(m);
			for (long i = 1; i <= m; i = i + 1)
			{
				baze b;
				cout << "iveskite " << i << "studento varda, pavarde, namu darbu skaiciu, namu darbus, egzamina : ";
				string vardas, pavarde;
				int kiekis;
				cin >> vardas >> pavarde;
				b.setvardas(vardas);
				b.setpavarde(pavarde);
				cin >> kiekis; 
				b.setkiekis(kiekis);
				skaicius_ir_tikr(kiekis);
				vector <int> paz;
				float sum = 0;
				for (int j = 0; j < b.getkiekis(); j++) {
					float sk;
					cin >> sk;
					paz_ir_tikr(sk);
					vector <int> paz;

					paz.push_back(sk);
					sum = sum + sk;
					paz.reserve(kiekis+1);
					
				}
				b.setpaz(paz);
				float egz;
				cin >> egz;
				b.setegz(egz);
				paz_ir_tikr(egz);
				

				sort(b.getpaz().begin(), b.getpaz().end());
				if (b.getkiekis() % 2 == 1) b.setmed(  b.getpaz().at((b.getkiekis() + 1) / 2)); else b.setmed ( b.getpaz().at(b.getkiekis() / 2) + b.getpaz().at(((b.getkiekis() / 2) + 1) / 2));
				b.setgalutinisvid();
				b.setgalutinismed();
				studentai.push_back(b);
				studentai.reserve(m+1);
			}
			cout << endl;
			cout << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde" << left << setw(15) << setfill(' ') << "galutinisvid" << left << setw(15) << setfill(' ') << "galutinismed" << endl;
			cout << string(60, '-') << endl;
			for (auto& a : studentai) {
				cout << left << setw(15) << setfill(' ') << a.getvardas() << left << setw(15) << setfill(' ') << a.getpavarde() << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.getgalutinisvid() << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.getgalutinismed() << endl;
			}
		}
	}
	studentai.clear();
	return (0);
}

void antra(int irasusk)
{
	vector <baze> studentai; vector <baze> vargsiukai; vector <baze> galvociai;
	cout << "testas su vektoriais" << endl;
	ketvirta(irasusk);
	nuskaitymas(to_string(irasusk), studentai);

	auto start = chrono::high_resolution_clock::now();
	pirma(studentai, vargsiukai, galvociai);

	chrono::duration <double> diff = chrono::high_resolution_clock::now() - start;
	cout << "Failo is " << irasusk << " irasu rusiavimas, pagal pirma strategija, uztruko: " << diff.count() << " s\n";
	studentai.clear();
	vargsiukai.clear();
	galvociai.clear();
	nuskaitymas(to_string(irasusk), studentai);
	start = chrono::high_resolution_clock::now();
	padalinimostrategija(studentai, vargsiukai);
    diff = chrono::high_resolution_clock::now() - start;
	cout << "Failo is " << irasusk << " irasu rusiavimas, pagal antra strategija, uztruko: " << diff.count() << " s\n";
	studentai.clear();
	vargsiukai.clear();
	galvociai.clear();
	list <baze1> studentai1; list <baze1> vargsiukai1; list <baze1> galvociai1;
	cout << "testas su listais" << endl;
	nuskaitymas1(to_string(irasusk), studentai1);

	start = chrono::high_resolution_clock::now();
	pirma1(studentai1, vargsiukai1, galvociai1);

    diff = chrono::high_resolution_clock::now() - start;
	cout << "Failo is " << irasusk << " irasu rusiavimas, pagal pirma strategija, uztruko: " << diff.count() << " s\n";
	studentai1.clear();
	vargsiukai1.clear();
	galvociai1.clear();
	nuskaitymas1(to_string(irasusk), studentai1);
	start = chrono::high_resolution_clock::now();
	padalinimostrategija1(studentai1, vargsiukai1);
	diff = chrono::high_resolution_clock::now() - start;
	cout << "Failo is " << irasusk << " irasu rusiavimas, pagal antra strategija, uztruko: " << diff.count() << " s\n";
	studentai1.clear();
	vargsiukai1.clear();
	galvociai1.clear();
}
