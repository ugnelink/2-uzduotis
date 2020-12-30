#include "funkcijos.h"
void ketvirta(int irasusk) {
	ofstream rf(to_string(irasusk) + ".txt");
	int r, t, k;
	string name[] = { "Jonas", "Petras", "Justinas","Adomas", "Tadas", "Dominykas", "Donatas", "Remigijus", "Antanas", "Vincas" };
	string pavarde[] = { "Jonaitis", "Petraitis", "Justinaitis", "Adomaitis", "Tadaitis", "Dominykaitis", "Donataitis", "Kazlauskas", "Antanaitis", "Vincaitis" };
	int nd;
	srand(time(NULL));
	vector <baze> studentai;
	baze studentas;
	cout << "iveskite namu darbu skaiciu " << endl;
	cin >> nd;
	skaicius_ir_tikr(nd);

	for (int i = 0; i < irasusk; i++) {
		r = rand() % 10;
		t = rand() % 10;
		baze b;
		studentas.setvardas(name[r] + to_string(rand() % 100 + 1));
		studentas.setpavarde(pavarde[t] + to_string(rand() % 100 + 1));
		studentas.setkiekis(nd);
		vector <int> paz;

		for (int j = 0; j < nd; j++) {
			k = rand() % 10 + 1;
			paz.push_back(k);
		}
		studentas.setpaz(paz);
		studentas.setegz(rand() % 10 + 1);
		studentai.push_back(b);

	}

	rf << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde";
	for (int j = 0; j < nd; j++) { rf << left << setw(15) << setfill(' ') << "ND" << j + 1; }
	rf << left << setw(15) << setfill(' ') << "egzaminas" << endl;
	for (auto& a : studentai) {
		rf << left << setw(15) << setfill(' ') << a.getvardas() << left << setw(15) << setfill(' ') << a.getpavarde();
		for (auto& aa : a.getpaz()) { rf << left << setw(15) << setfill(' ') << aa; }
		rf << left << setw(15) << setfill(' ') << a.getegz() << endl;
	}
	rf.close();
}
void nuskaitymas(string failas, vector <baze>& studentai) {
	int n = 0;
	ifstream df(failas + ".txt");
	int g;
	string antraste;
	getline(df, antraste, '\n');
	g = count(antraste.begin(), antraste.end(), 'N');
	while (!df.eof()) {
		baze b;
		b.setkiekis(g);
		n = n + 1;
		float sum = 0;
		string vardas, pavarde;

		df >>vardas >> pavarde;
		b.setvardas(vardas);
		b.setpavarde(pavarde);
		vector <int> paz;
		for (int i = 0; i < b.getkiekis(); i++) {
			float sk;
			df >> sk; paz.push_back(sk); sum = sum + sk;
		}
		b.setpaz(paz);
		b.setsum(sum);
	
		sort(b.getpaz().begin(), b.getpaz().end());
		if (b.getkiekis() % 2 == 1) b.setmed( b.getpaz().at((b.getkiekis() + 1) / 2)); else b.setmed( b.getpaz().at(b.getkiekis() / 2) + b.getpaz().at(((b.getkiekis() / 2) + 1) / 2));
		float egz;
		df >> egz;
		b.setegz(egz);
		b.setgalutinisvid();
		b.setgalutinismed();
		studentai.push_back(b);
		studentai.reserve(n);
	}
	df.close();
}

void funkcija(string failas, vector <baze> studentai) {

	ofstream rf(failas + ".txt");
	rf << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde" << left << setw(15) << setfill(' ') << "galutinisvid" << left << setw(15) << setfill(' ') << "galutinismed" << endl;
	rf << string(60, '-') << endl;
	for (auto& a : studentai) {
		rf << left << setw(15) << setfill(' ') << a.getvardas() << left << setw(15) << setfill(' ') << a.getpavarde() << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.getgalutinisvid() << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.getgalutinismed() << endl;
	}

	rf.close();
}
void pirma(vector <baze> studentai, vector <baze> &vargsiukai, vector <baze> &galvociai) {
	for (auto& a : studentai) {
		if (a.getgalutinisvid() >= 5) galvociai.push_back(a);
		else vargsiukai.push_back(a);

	}

}
void padalinimostrategija(vector <baze>& studentai, vector <baze>& vargsiukai) {
	

    for (auto& a : studentai) {
     
		if (a.getgalutinisvid() < 5)  vargsiukai.push_back(a); 		 
}

	studentai.erase(remove_if(studentai.begin(), studentai.end(), [&](baze
		const& studentas) { return studentas.getgalutinisvid() < 5; }), studentai.end());
}

