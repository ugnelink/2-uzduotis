#ifndef ZMOGUS_H
#define ZMOGUS_H
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class zmogus
{
protected:
    string vardas; string pavarde;
    zmogus(){ vardas = ""; pavarde = ""; }
    void setvardas(string var) {vardas=var; }
    void setpavarde(string pav) { pavarde = pav; }
    zmogus(string var, string pav) {
        vardas=var; pavarde=pav;
    }
    zmogus(const zmogus& studentas); // kopijavimo konstruktorius
    zmogus & operator=(const zmogus& studentas); //kopijavimo priskirties operatorius

public:
    virtual ~zmogus(){}; //destruktorius
    virtual string getvardas()const { return vardas; }
    virtual string getpavarde()const { return pavarde; }


};



#endif // ZMOGUS_H
