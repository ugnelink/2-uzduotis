#include "zmogus.h"


zmogus::zmogus(const zmogus& studentas):

	vardas{ studentas.vardas },
	pavarde{ studentas.pavarde }

	 {
	vardas = studentas.vardas;
	pavarde = studentas.pavarde;
	 }



zmogus& zmogus::operator=(const zmogus& studentas) {

    if (&studentas == this) return *this;
	vardas = studentas.vardas;
	pavarde = studentas.pavarde;
	return *this;


}
