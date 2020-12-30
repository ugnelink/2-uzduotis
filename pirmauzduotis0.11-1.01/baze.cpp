
#include "baze.h"
baze::baze(const baze& studentas):

	vardas{ studentas.vardas },
	pavarde{ studentas.pavarde },
		vid{ studentas.vid },
		paz{ studentas.paz },
		kiekis{ studentas.kiekis },
		egz{ studentas.egz },
		galutinismed{ studentas.galutinismed },
		galutinisvid{ studentas.galutinisvid },
		sum{ studentas.sum },
		med{ studentas.med }
	 {
	vardas = studentas.vardas;
	pavarde = studentas.pavarde;
	vid = studentas.vid;
	paz = studentas.paz;
	egz = studentas.egz;
	galutinismed = studentas.galutinismed;
	galutinisvid = studentas.galutinisvid;
	sum = studentas.sum;
	med = studentas.med;
	 }



baze& baze::operator=(const baze& studentas) {

    if (&studentas == this) return *this;

	paz.clear();
	vardas = studentas.vardas;
	pavarde = studentas.pavarde;
	vid = studentas.vid;
	paz = studentas.paz;
	egz = studentas.egz;
	galutinismed = studentas.galutinismed;
	galutinisvid = studentas.galutinisvid;
	sum = studentas.sum;
	med = studentas.med;
	return *this;


}
