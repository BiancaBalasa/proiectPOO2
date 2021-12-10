#include <iostream>
#include <string>

using namespace std;

class Hrana
{
protected:
	string nume;
	double pret;
	string tipAnimal;
	bool estePtProblemeSpeciale;

public:
	//setters
	void setNume(string nume) { this->nume = nume; }
	void setPret(double pret) { this->pret = pret; }
	void setTipAnimal(string tipAnimal) { this->tipAnimal = tipAnimal; }
	void setEstePtProblemeSpeciale(bool estePtProblemeSpeciale) { this->estePtProblemeSpeciale = estePtProblemeSpeciale; }

	//getters 
	string getNume() { return this->nume; }
	double getPret() { return this->pret; }
	string getTipAnimal() { return this->tipAnimal; }
	bool getEstePtProblemeSpeciale() { return this->estePtProblemeSpeciale; }

	//constructorul fara parametrii
	Hrana();

	//constructorul cu toti parametrii
	Hrana(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale);

	//copy constructor
	Hrana(const Hrana& other);

	//overload operator=
	Hrana& operator=(const Hrana& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const Hrana& h);

	//overload operator>>
	friend istream& operator>>(istream& in, Hrana& h);

	//destructor
	~Hrana();

	//function
	double calculeazaDiscountHrana();

};

// constructorul fara parametrii
Hrana::Hrana()
{
	//cout << "Constructor fara parametrii pentru hrana:\n";
	this->nume = "Anonim";
	this->pret = 0;
	this->tipAnimal = "Anonim";
	this->estePtProblemeSpeciale = false;
}

// constructorul cu toti parametrii
Hrana::Hrana(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale)
{
	//cout << "Constructor cu toti parametrii pentru hrana:\n";
	this->nume = nume;
	this->pret = pret;
	this->tipAnimal = tipAnimal;
	this->estePtProblemeSpeciale = estePtProblemeSpeciale;
}

// copy constructor
Hrana::Hrana(const Hrana& other)
{
	this->nume = other.nume;
	this->pret = other.pret;
	this->tipAnimal = other.tipAnimal;
	this->estePtProblemeSpeciale = other.estePtProblemeSpeciale;
}

// overload operator=
Hrana& Hrana::operator=(const Hrana& other)
{
	if (this != &other)
	{
		this->nume = other.nume;
		this->pret = other.pret;
		this->tipAnimal = other.tipAnimal;
		this->estePtProblemeSpeciale = other.estePtProblemeSpeciale;
	}
	return *this;
}

// overload operator<<
ostream& operator<<(ostream& out, const Hrana& h)
{
	out << "\nNume: " << h.nume;
	out << "\nPret: " << h.pret;
	out << "\nTip animal: " << h.tipAnimal;
	out << "\nEste pentru probleme speciale: " << h.estePtProblemeSpeciale;
	return out;
}
// overload operator>>
istream& operator>>(istream& in, Hrana& h)
{
	cout << "\nNume: ";
	in >> h.nume;
	cout << "\nPret: ";
	in >> h.pret;
	cout << "\nTip animal: ";
	in >> h.tipAnimal;
	cout << "\nEste pentru probleme speciale: ";
	in >> h.estePtProblemeSpeciale;
	return in;
}

// destructor
Hrana::~Hrana()
{
	//cout << "\nDistruge hrana:";
	//cout << this->nume << endl;
}

//function
double Hrana::calculeazaDiscountHrana()
{
	double discount = 0;
	if (this->estePtProblemeSpeciale == true)
		discount = 10 * 0.01 * this->pret;
	return discount;
}

class HranaUscata : virtual public Hrana
{
protected:
	int grame;

public:
	//setter
	void setGrame(int grame) { this->grame = grame; }

	//getter
	int getGrame() { return this->grame; }

	//constructor fara parametrii
	HranaUscata(); 

	//constructor cu toti parametrii
	HranaUscata(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale, int grame);

	//copy constructor
	HranaUscata(const HranaUscata& other);

	//overload operator=
	HranaUscata& operator=(const HranaUscata& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const HranaUscata& hu);

	//overload operator>>
	friend istream& operator>>(istream& in, HranaUscata& hu);

	//destructor
	~HranaUscata();

	//function
	double calculeazaDiscountHranaUscata();
};

//constructor fara parametrii
HranaUscata::HranaUscata() :Hrana()
{
	//cout << "Constructor fara parametrii pentru hrana uscata:\n";
	this->grame = 0;
}

//constructor cu toti parametrii
HranaUscata::HranaUscata(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale, int grame) : Hrana(nume, pret, tipAnimal, estePtProblemeSpeciale)
{
	//cout << "Constructor cu toti parametrii pentru hrana uscata:\n";
	this->grame = grame;
}

//copy constructor
HranaUscata::HranaUscata(const HranaUscata& other) :Hrana(other)
{
	this->grame = other.grame;
}

//overload operator=
HranaUscata& HranaUscata :: operator=(const HranaUscata& other)
{
	if (this != &other)
	{
		Hrana::operator=(other);   //(Hrana&)(*this) = other;
		this->grame = other.grame;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const HranaUscata& hu)
{
	out << (const Hrana&)hu;
	out << "\nGrame: " << hu.grame << endl;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, HranaUscata& hu)
{
	in >> (Hrana&)hu;
	cout << "\nGrame: ";
	in >> hu.grame;
	cout << endl;
	return in;
}

//destructor
HranaUscata::~HranaUscata()
{
	//cout << "\nDistruge hrana uscata " << endl;
}

//function: 
double HranaUscata::calculeazaDiscountHranaUscata()
{
	double discountTotal = 0; // se calculeaza la totalul de grame, NU pe suta de grame
	
	if (this->grame >= 500 && this->grame < 1500)
		discountTotal = 15 * 0.01 * this->pret;
	else
		if (this->grame >= 1500)
			discountTotal = 25 * 0.01 * this->pret;
	
	if (((Hrana)*this).calculeazaDiscountHrana() == 0)
		return discountTotal;
	else
		return discountTotal + ((Hrana)*this).calculeazaDiscountHrana();
	
}

class HranaUmeda : virtual public Hrana
{
protected:
	int nrPlicuri;

public:
	//setter
	void setNrPlicuri(int nrPlicuri) { this->nrPlicuri = nrPlicuri; }

	//getter
	int getNrPlicuri() { return this->nrPlicuri; }

	//constructor fara parametrii
	HranaUmeda();

	//constructor cu toti parametrii
	HranaUmeda(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale, int nrPlicuri);

	//copy constructor
	HranaUmeda(const HranaUmeda& other);

	//overload operator=
	HranaUmeda& operator=(const HranaUmeda& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const HranaUmeda& hu);

	//overload operator>>
	friend istream& operator>>(istream& in, HranaUmeda& hu);

	//destructor
	~HranaUmeda();

	//function
	double calculeazaDiscountHranaUmeda();
};

//constructor fara parametrii
HranaUmeda::HranaUmeda() :Hrana()
{
	//cout<<"\nConstructor fara parametrii pentru hrana umeda";
	this->nrPlicuri = 0;
}

//constructor cu toti parametrii
HranaUmeda::HranaUmeda(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale, int nrPlicuri) :Hrana(nume, pret, tipAnimal, estePtProblemeSpeciale)
{
	//cout << "Constructor cu toti parametrii pentru hrana umeda:\n";
	this->nrPlicuri = nrPlicuri;
}

//copy constructor
HranaUmeda::HranaUmeda(const HranaUmeda& other) :Hrana(other)
{
	this->nrPlicuri = other.nrPlicuri;
}

//overload operator=
HranaUmeda& HranaUmeda :: operator=(const HranaUmeda& other)
{
	if (this != &other)
	{
		Hrana::operator=(other);
		this->nrPlicuri = other.nrPlicuri;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const HranaUmeda& hu)
{
	out << (const Hrana&)hu;
	out << "\nNumar plicuri: " << hu.nrPlicuri << endl;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, HranaUmeda& hu)
{
	in >> (Hrana&)hu;
	cout << "\nNumar plicuri: ";
	in >> hu.nrPlicuri;
	cout << endl;
	return in;
}

//destructor
HranaUmeda::~HranaUmeda()
{
	//cout << "\nDistruge hrana umeda " << endl;
}

//function
double HranaUmeda::calculeazaDiscountHranaUmeda()
{
	double discountPerPlic = 0; 
	double discountTotal = 0;

	if (this->nrPlicuri >= 15 && this->nrPlicuri < 35)
		discountPerPlic = 10 * 0.01 * this->pret;
	else
		if (this->nrPlicuri >= 35)
			discountPerPlic = 20 * 0.01 * this->pret;

	discountTotal = discountPerPlic * this->nrPlicuri;

	if (((Hrana)*this).calculeazaDiscountHrana() == 0)
		return discountTotal;
	else
		return discountTotal + ((Hrana)*this).calculeazaDiscountHrana();
}

class MixHrana :public HranaUscata, public HranaUmeda
{
private:
	double concentratieUscata;
	double concentratieUmeda;

public:
	//setters
	void setConcentratieUscata(double concentratieUscata) { this->concentratieUscata = concentratieUscata; }
	void setConcentratieUmeda(double concentratieUmeda) { this->concentratieUmeda = concentratieUmeda; }

	//getters
	double getConcentratieUscata() { return this->concentratieUscata; }
	double getConcentratieUmeda() { return this->concentratieUmeda; }

	//contructor fara parametrii
	MixHrana();

	//constructor cu toti parametrii
	MixHrana(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale, int grame, int nrPlicuri, double concentratieUscata, double concentratieUmeda);

	//copy constructor
	MixHrana(const MixHrana& other);

	//overload operator=
	MixHrana& operator=(const MixHrana& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const MixHrana& mh);

	//overload operator>>
	friend istream& operator>>(istream& in, MixHrana& mh);

	//destructor
	~MixHrana();

	//function
	int CalculeazaGramaj();
	//calculeaza gramaj total al mixturi: grame + 85 * nr.plicuri

};

//constructor fara parametrii
MixHrana::MixHrana() :HranaUscata(), HranaUmeda()
{
	this->concentratieUscata = 0;
	this->concentratieUmeda = 0;
}

//constructor cu toti parametrii
MixHrana::MixHrana(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale, int grame, int nrPlicuri, double concentratieUscata, double concentratieUmeda)
	: Hrana(nume, pret, tipAnimal, estePtProblemeSpeciale), HranaUscata(nume, pret, tipAnimal, estePtProblemeSpeciale, grame),
	HranaUmeda(nume, pret, tipAnimal, estePtProblemeSpeciale, nrPlicuri)
{
	this->concentratieUscata = concentratieUscata;
	this->concentratieUmeda = concentratieUmeda;
}

//copy constructor
MixHrana::MixHrana(const MixHrana& other) : Hrana(other), HranaUscata(other), HranaUmeda(other)
{
	this->concentratieUscata = other.concentratieUscata;
	this->concentratieUmeda = other.concentratieUmeda;
}

//overload operator=
MixHrana& MixHrana::operator=(const MixHrana& other)
{
	if (this != &other)
	{
		Hrana::operator=(other);
		this->grame = other.grame;
		this->nrPlicuri = other.nrPlicuri;
		this->concentratieUscata = other.concentratieUscata;
		this->concentratieUmeda = other.concentratieUmeda;

	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const MixHrana& mh)
{
	out << (const Hrana&)mh;
	out << "\nGrame: " << mh.grame;
	out << "\nNr Plicuri: " << mh.nrPlicuri;
	out << "\nConcentratie Uscata: " << mh.concentratieUscata;
	out << "\nConcentratie Umeda: " << mh.concentratieUmeda;
	out << endl;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, MixHrana& mh)
{
	in >> (Hrana&)mh;
	cout << "\nGrame: ";
	in >> mh.grame;
	cout << "\nNr Plicuri: ";
	in >> mh.nrPlicuri;
	cout << "\nConcentratie Uscata: ";
	in >> mh.concentratieUscata;
	cout << "\nConcentratie Umeda: ";
	in >> mh.concentratieUmeda;
	cout << endl;
	return in;
}

//destructor
MixHrana::~MixHrana()
{
	//cout << "\nDistruge MixHrana " << endl;
}

//function
int MixHrana::CalculeazaGramaj()
{
	int gramajTotal = 0;
	gramajTotal = this->grame + this->nrPlicuri * 85;
	return gramajTotal;
}


class Animal
{
protected:
	string nume;
	char sex;
	int varsta;
	double greutate;
	double pret;
	bool areProblemeSpeciale;

public:
	//setters
	void setNume(string nume) { this->nume = nume; }
	void setSex(char sex) { this->sex = sex; }
	void setVarsta(int varsta) { this->varsta = varsta; }
	void setGreutate(double greutate) { this->greutate = greutate; }
	void setPret(double pret) { this->pret = pret; }
	void setAreProblemeSpeciale(bool areProblemeSpeciale) { this->areProblemeSpeciale = areProblemeSpeciale; }

	//getters
	string getNume() { return this->nume; }
	char getSex() { return this->sex; }
	int getVarsta() { return this->varsta; }
	double getGreutate() { return this->greutate; }
	double getPret() { return this->pret; }
	bool getAreProblemeSpeciale() { return this->areProblemeSpeciale; }

	//constructor fara parametrii
	Animal();

	//costructor cu toti parametrii
	Animal(string nume, char sex, int varsta, double greutate, double pret, bool areProblemeSpeciale);

	//copy constructor
	Animal(const Animal& other);

	//overload operator=
	Animal& operator=(const Animal& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const Animal& a);

	//overload operator>>
	friend istream& operator>>(istream& in, Animal& a);

	//destructor
	~Animal();

	//function
	virtual bool verificaObezitate() = 0;
};

//constructor fara parametrii
Animal::Animal()
{
	//cout << "Constructor fara parametrii pentru animal:\n";
	this->nume = "Anonim";
	this->sex = '-';
	this->varsta = 0;
	this->greutate = 0;
	this->pret = 0;
	this->areProblemeSpeciale = false;
}

//constructor cu toti parametrii
Animal::Animal(string nume, char sex, int varsta, double greutate, double pret, bool areProblemeSpeciale)
{
	//cout << "Constructor cu toti parametrii pentru animal:\n";
	this->nume = nume;
	this->sex = sex;
	this->varsta = varsta;
	this->greutate = greutate;
	this->pret = pret;
	this->areProblemeSpeciale = areProblemeSpeciale;
}

//copy constructor
Animal::Animal(const Animal& other)
{
	this->nume = other.nume;
	this->sex = other.sex;
	this->varsta = other.varsta;
	this->greutate = other.greutate;
	this->pret = other.pret;
	this->areProblemeSpeciale = other.areProblemeSpeciale;
}

//overload operator=
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->nume = other.nume;
		this->sex = other.sex;
		this->varsta = other.varsta;
		this->greutate = other.greutate;
		this->pret = other.pret;
		this->areProblemeSpeciale = other.areProblemeSpeciale;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const Animal& a)
{
	out << "\nNume: " << a.nume;
	out << "\nSex: " << a.sex;
	out << "\nVarsta: " << a.varsta;
	out << "\nGreutate: " << a.greutate;
	out << "\nPret: " << a.pret;
	out << "\nAre probleme speciale: " << a.areProblemeSpeciale;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, Animal& a)
{
	cout << "\nNume: ";
	in >> a.nume;
	cout << "\nSex: ";
	in >> a.sex;
	cout << "\nVarsta: ";
	in >> a.varsta;
	cout << "\nGreutate: ";
	in >> a.greutate;
	cout << "\nPret: ";
	in >> a.pret;
	cout << "\nAre probleme speciale: ";
	in>> a.areProblemeSpeciale;
	return in;
}

//destructor
Animal::~Animal()
{
	//cout << "\nDistruge animalul: ";
	//cout << this->nume << endl;
}

class Pisica : public Animal
{
private:
	bool areGheareTaiate;

public:
	//setter
	void setAreGheareTaiate(bool areGheareTaiate) { this->areGheareTaiate = areGheareTaiate; }

	//getter
	bool getAreGheareTaiate() { return this->areGheareTaiate; }

	//constructor fara parametrii
	Pisica();

	//constructor cu toti parametrii
	Pisica(string nume, char sex, int varsta, double greutate, double pret, bool areProblemeSpeciale, bool areGheareTaiate);

	//copy constructor
	Pisica(const Pisica& other);

	//overload operator=
	Pisica& operator=(const Pisica& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const Pisica& p);

	//overload operator>>
	friend istream& operator>>(istream& in, Pisica& p);

	//destructor
	~Pisica();

	//function
	bool verificaObezitate();

};

//constructor fara parametrii
Pisica::Pisica() :Animal()
{
	//cout << "Constructor fara parametrii pentru pisica:\n";
	this->areGheareTaiate = false;

}

//constructor cu toti parametrii
Pisica::Pisica(string nume, char sex, int varsta, double greutate, double pret, bool areProblemeSpeciale, bool areGheareTaiate) 
	   :Animal(nume, sex, varsta, greutate, pret, areProblemeSpeciale)
{
	this->areGheareTaiate = areGheareTaiate;
}

//copy constructor
Pisica::Pisica(const Pisica& other) : Animal(other)
{
	this->areGheareTaiate = other.areGheareTaiate;
}

//overload operator=
Pisica& Pisica :: operator=(const Pisica& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->areGheareTaiate = other.areGheareTaiate;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const Pisica& p)
{
	out << (const Animal&)p;
	out << "\nAre gheaare taiate: " << p.areGheareTaiate << endl;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, Pisica& p)
{
	in >> (Animal&)p;
	cout << "\nAre gheare taiate: ";
	in >> p.areGheareTaiate;
	cout << endl;
	return in;
}

//destructor
Pisica::~Pisica()
{
	//cout << "\nDistruge pisica:" << endl;
}

//function 
bool Pisica::verificaObezitate() 
{
	bool obezitatePisica = false;
	int criteriuObezitatePisica;
	if (this->varsta < 2)
		criteriuObezitatePisica = 7;
	else
	{
		if (this->varsta >= 2 && this->varsta <= 10)
			criteriuObezitatePisica = 12;
		else
			criteriuObezitatePisica = 10;
	}

	if (this->greutate >= criteriuObezitatePisica)
	{
		this->areProblemeSpeciale = true;
		obezitatePisica  = true;
	}

	return obezitatePisica;
}

class Caine :public Animal
{
private:
	bool esteDresat;

public:
	//setter
	void setEsteDresat(bool esteDresat) { this->esteDresat = esteDresat; }

	//getter
	bool getEsteDresat() { return this->esteDresat; }

	//constructor fara parametrii
	Caine();

	//constructor cu toti parametrii
	Caine(string nume, char sex, int varsta, double greutate, double pret, bool areProblemeSpeciale, bool esteDresat);

	//copy constructor
	Caine(const Caine& other);

	//overload operator=
	Caine& operator=(const Caine& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const Caine& c);

	//overload operator>>
	friend istream& operator>>(istream& in, Caine& c);

	//destructor
	~Caine();

	//function
	bool verificaObezitate();
};

//constructor fara parametrii
Caine::Caine():Animal()
{
	this->esteDresat = false;
}

//constructor cu toti parametrii
Caine::Caine(string nume, char sex, int varsta, double greutate, double pret, bool areProblemeSpeciale, bool esteDresat)
	:Animal(nume, sex, varsta, greutate, pret, areProblemeSpeciale)
{
	this->esteDresat = esteDresat;
}

//copy constructor
Caine::Caine(const Caine& other) :Animal(other)
{
	this->esteDresat = other.esteDresat;
}

//overload operator=
Caine& Caine::operator=(const Caine& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->esteDresat = other.esteDresat;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const Caine& c)
{
	out << (const Animal&)c;
	out << "\nEste dresat: " << c.esteDresat << endl;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, Caine& c)
{
	in >> (Animal&)c;
	cout << "\nEste dresat: ";
	in >> c.esteDresat;
	cout << endl;
	return in;
}

//destructor
Caine::~Caine()
{
	//cout << "\nDistruge caine " << endl;
}

//function
bool Caine::verificaObezitate()
{
	bool obezitateCaine = false;
	int criteriuObezitateCaine;
	if (this->varsta < 2)
		criteriuObezitateCaine = 25;
	else
	{
		if (this->varsta >= 2 && this->varsta <= 10)
			criteriuObezitateCaine = 35;
		else
			criteriuObezitateCaine = 30;
	}

	if (this->greutate >= criteriuObezitateCaine)
	{
		this->areProblemeSpeciale = true;
		obezitateCaine = true;
	}

	return obezitateCaine;
}

class Client
{
protected:
	string numePrenume;
	char sex;
	double rating;
	int animaleDetinute;

public:
	//setters
	void setNumePrenume(string numePrenume) { this->numePrenume = numePrenume; }
	void setSex(char sex) { this->sex = sex; }
	void setRating(double rating) { this->rating = rating; }
	void setAnimaleDetinute(int animaleDetinute) { this->animaleDetinute = animaleDetinute; }

	//getters
	string getNumePrenume() { return this->numePrenume; }
	char getSex() { return this->sex; }
	double getRating() { return this->rating; }
	int getAnimaleDetinute() { return this->animaleDetinute; }

	//costructor fara parametrii
	Client();

	//constructor cu toti parametrii
	Client(string numePrenume, char sex, double rating, int animaleDetinute);

	//copy constructor
	Client(const Client& other);

	//overload operator=
	Client& operator=(const Client& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const Client& c);

	//overload operator>>
	friend istream& operator>>(istream& in, Client& c);

	//destructor
	~Client();

	//function 
	bool poateAdopta(Animal& a) const;
};

//constructor fara parametrii
Client::Client()
{
	this->numePrenume = "Anonim";
	this->sex = '-';
	this->rating = 0;
	this->animaleDetinute = 0;
}

//constructor cu toti parametrii
Client::Client(string numePrenume, char sex, double rating, int animaleDetinute)
{
	this->numePrenume = numePrenume;
	this->sex = sex;
	this->rating = rating;
	this->animaleDetinute = animaleDetinute;
}

//copy constructor
Client::Client(const Client& other)
{
	this->numePrenume = other.numePrenume;
	this->sex = other.sex;
	this->rating = other.rating;
	this->animaleDetinute = other.animaleDetinute;
}

//overload operator=
Client& Client::operator=(const Client& other)
{
	if (this != &other)
	{
		this->numePrenume = other.numePrenume;
		this->sex = other.sex;
		this->rating = other.rating;
		this->animaleDetinute = other.animaleDetinute;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const Client& c)
{
	out << "\nNume prenume: " << c.numePrenume;
	out << "\nSex: " << c.sex;
	out << "\nRating: " << c.rating;
	out << "\nAnimale detinute: " << c.animaleDetinute;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, Client& c)
{
	cout << "\nNume prenume: ";
	in >> c.numePrenume;
	cout << "\nSex: ";
	in >> c.sex;
	cout << "\nRating: ";
	in >> c.rating;
	cout << "\nAnimale detinute: ";
	in >> c.animaleDetinute;
	return in;
}

//destructor
Client::~Client()
{
	//cout << "\nDistruge client ";
	//cout << this->numePrenume << endl;
}

//function 
bool Client::poateAdopta(Animal& a) const
{
	bool poateAdopta = true;

	if (this->rating <= 2.5 && this->animaleDetinute >= 5)
		poateAdopta = false;
	else
		if (this->animaleDetinute >= 3 && a.getAreProblemeSpeciale() == true)
			poateAdopta = false;

	return poateAdopta;
}

class Adult :public Client
{
private:
	int membriiCasa;
	bool calatoresteMult;

public:
	//setters
	void setMembriiCasa(int membriiCasa) { this->membriiCasa = membriiCasa; }
	void setCalatoresteMult(bool calatoresteMult) { this->calatoresteMult = calatoresteMult; }

	//getters
	int getMembriiCasa() { return this->membriiCasa; }
	bool getCalaltoresteMult() { return this->calatoresteMult; }

	//constructor fara parametrii
	Adult();

	//constructor cu toti parametrii
	Adult(string numePrenume, char sex, double rating, int animaleDetinute, int membriiCasa, bool calatoresteMult);

	//copy constructor
	Adult(const Adult& other);

	//overload operator=
	Adult& operator=(const Adult& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const Adult& a);

	//overload operator>>
	friend istream& operator>>(istream& in, Adult& a);

	//destructor 
	~Adult();

	//function
	bool poateAdoptaAdultul(Animal& a);
};

//constructor fara parametrii
Adult::Adult() :Client()
{
	this->membriiCasa = 0;
	this->calatoresteMult = false;
}

//constructor cu toti parametrii
Adult::Adult(string numePrenume, char sex, double rating, int animaleDetinute, int membriiCasa, bool calatoresteMult)
	:Client(numePrenume, sex, rating, animaleDetinute)
{
	this->membriiCasa = membriiCasa;
	this->calatoresteMult = calatoresteMult;
}

//copy constructor
Adult::Adult(const Adult& other) :Client(other)
{
	this->membriiCasa = other.membriiCasa;
	this->calatoresteMult = other.calatoresteMult;
}

//overload operator=
Adult& Adult::operator=(const Adult& other)
{
	if (this != &other)
	{
		Client::operator=(other);
		this->membriiCasa = other.membriiCasa;
		this->calatoresteMult = other.calatoresteMult;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const Adult& a)
{
	out << (const Client&)a;
	out << "\nMembrii casa: " << a.membriiCasa;
	out << "\nCalatoreste mult: " << a.calatoresteMult;
	out << endl;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, Adult& a)
{
	in >> (Client&)a;
	cout << "\nMembrii casa: ";
	in >> a.membriiCasa;
	cout << "\nCalatoreste mult: ";
	in >> a.calatoresteMult;
	cout << endl;
	return in;
}

//destructor
Adult::~Adult()
{
	//cout << "\nDistruge adult " << endl;
}

//function
bool Adult::poateAdoptaAdultul(Animal& a)
{
	bool poateAdopta = true;

	if (this->calatoresteMult == true && this->membriiCasa == 1)
		poateAdopta = false;
	
	if (poateAdopta == true && this->poateAdopta(a) == true)
		return true;
	else
		return false;
}

class Pensionar : public Client
{
private:
	bool areProblemeSanatate;

public:
	//setter
	void setAreProblemeSanatate(bool areProblemeSanatate) { this->areProblemeSanatate = areProblemeSanatate; }

	//getter
	bool getAreProblemeSanatate() { return this->areProblemeSanatate; }

	//constructor fara parametrii
	Pensionar();

	//constructor cu toti parametrii
	Pensionar(string numePrenume, char sex, double rating, int animaleDetinute, bool areProblemeSanatate);

	//copy constructor
	Pensionar(const Pensionar& other);

	//overload operator=
	Pensionar& operator=(const Pensionar& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const Pensionar& p);

	//overload operator>>
	friend istream& operator>>(istream& in, Pensionar& p);

	//destructor
	~Pensionar();

	//function
	bool poateAdoptaPensionarul(Animal& a);

};

//constructor fara parametrii
Pensionar::Pensionar() :Client()
{
	this->areProblemeSanatate = false;
}

//constructor cu toti parametrii
Pensionar::Pensionar(string numePrenume, char sex, double rating, int animaleDetinute, bool areProblemeSanatate)
	: Client(numePrenume, sex, rating, animaleDetinute)
{
	this->areProblemeSanatate = areProblemeSanatate;
}

//copy constructor
Pensionar::Pensionar(const Pensionar& other) :Client(other)
{
	this->areProblemeSanatate = other.areProblemeSanatate;
}

//overload operator=
Pensionar& Pensionar::operator=(const Pensionar& other)
{
	if (this != &other)
	{
		Client::operator=(other);
		this->areProblemeSanatate = other.areProblemeSanatate;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const Pensionar& p)
{
	out << (const Client&)p;
	out << "\nAre probleme de sanatate: " << p.areProblemeSanatate;
	out << endl;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, Pensionar& p)
{
	in >> (Client&)p;
	cout << "\nAre probleme de sanatate: ";
	in >> p.areProblemeSanatate;
	cout << endl;
	return in;
}

//destructor
Pensionar::~Pensionar()
{
	//cout << "\nDistruge pensionarul: ";
	//cout << endl;
}

//function
bool Pensionar::poateAdoptaPensionarul(Animal& a)
{
	bool poateAdopta = true;

	if (this->areProblemeSanatate == true && a.getAreProblemeSpeciale() == true)
		poateAdopta = false;
	
	if (poateAdopta == true && this->poateAdopta(a) == true)
		return true;
	else
		return false;
}

int main()
{
	Adult* listaAdulti[100];
	Pensionar* listaPensionari[100];
	HranaUscata* listaHranaUscata[100];
	HranaUmeda* listaHranaUmeda[100];
	Pisica* listaPisici[100] ;
	Caine* listaCaini[100];

	int indexListaAdulti = 0;
	int indexListaPensionari = 0;
	int indexListaHranaUscata = 0;
	int indexListaHranaUmeda = 0;
	int indexListaPisici = 0;
	int indexListaCaini = 0;

	int input = -1;
	while (input != 0)
	{
		cout << "\nALEGETI OPTIUNEA: " << endl;
		cout << " 0. Exit!\n";
		cout << " 1. Creeaza adult\n";
		cout << " 2. Creeaza pensionar\n";
		cout << " 3. Creeaza hrana uscata\n";
		cout << " 4. Creeaza hrana umeda\n";
		cout << " 5. Creeaza pisica\n";
		cout << " 6. Creeaza caine\n";
		cout << " 7. Afiseaza toti adultii\n";
		cout << " 8. Afiseaza toti pensionarii\n";
		cout << " 9. Afiseaza toata hrana uscata\n";
		cout << "10. Afiseaza toata hrana umeda\n";
		cout << "11. Afiseaza toate pisicile\n";
		cout << "12. Afiseaza toti cainii\n";
		cout << "13. Verifica daca un adult poate adopta o pisica\n";
		cout << "14. Verifica daca un adult poate adopta un caine\n";
		cout << "15. Verifica daca un pensionar poate adopta o pisica\n";
		cout << "16. Verifica daca un pensionar poate adopta un caine\n";
		cout << "17. Calculeaza discount pentru o hrana uscata\n";
		cout << "18. Calculeaza discount pentru o hrana umeda\n";
		cout << "19. Verifica daca o pisica are probleme cu obezitatea\n";
		cout << "20. Verifica daca un caine are probleme cu obezitatea\n";
		


		cin >> input;

		switch (input)
		{
		case 0:
			cout << "Iesire din program! " << endl;
			break;

		case 1:
		{
			listaAdulti[indexListaAdulti] = new Adult();
			cin >> *listaAdulti[indexListaAdulti];
			indexListaAdulti++;
			break;
		}

		case 2:
		{
			listaPensionari[indexListaPensionari] = new Pensionar();
			cin >> *listaPensionari[indexListaPensionari];
			indexListaPensionari++;
			break;
		}

		case 3:
		{
			listaHranaUscata[indexListaHranaUscata] = new HranaUscata();
			cin >> *listaHranaUscata[indexListaHranaUscata];
			indexListaHranaUscata++;
			break;
		}

		case 4:
		{
			listaHranaUmeda[indexListaHranaUmeda] = new HranaUmeda();
			cin >> *listaHranaUmeda[indexListaHranaUmeda];
			indexListaHranaUmeda++;
			break;
		}

		case 5:
		{
			listaPisici[indexListaPisici] = new Pisica();
			cin >> *listaPisici[indexListaPisici];
			indexListaPisici++;
			break;
		}

		case 6:
		{
			listaCaini[indexListaCaini] = new Caine();
			cin >> *listaCaini[indexListaCaini];
			indexListaCaini++;
			break;
		}

		case 7:
		{
			for (int i = 0; i < indexListaAdulti; i++)
			{
				cout << *listaAdulti[i] << endl;
			}
			break;
		}

		case 8:
		{
			for (int i = 0; i < indexListaPensionari; i++)
			{
				cout << *listaPensionari[i] << endl;
			}
			break;
		}

		case 9:
		{
			for (int i = 0; i < indexListaHranaUscata; i++)
			{
				cout << *listaHranaUscata[i] << endl;
			}
			break;
		}

		case 10:
		{
			for (int i = 0; i < indexListaHranaUmeda; i++)
			{
				cout << *listaHranaUmeda[i] << endl;
			}
			break;
		}

		case 11:
		{
			for (int i = 0; i < indexListaPisici; i++)
			{
				cout << *listaPisici[i] << endl;
			}
			break;
		}

		case 12:
		{
			for (int i = 0; i < indexListaCaini; i++)
			{
				cout << *listaCaini[i] << endl;
			}
			break;
		}

		case 13:
		{
			for (int i = 0; i < indexListaAdulti; i++)
			{  
				cout << "Index adult: " << i << endl;
				cout << *listaAdulti[i] << endl;
			}

			for (int i = 0; i < indexListaPisici; i++)
			{
				cout << "Index pisica: " << i << endl;
				cout << *listaPisici[i] << endl;
			}

			int indexAdult;
			cout << "Indexul adultului dorit: ";
			cin >> indexAdult;

			int indexPisica;
			cout << "Indexul pisicii dorite: ";
			cin >> indexPisica;
			cout << endl;

			if (listaAdulti[indexAdult]->poateAdoptaAdultul(*listaPisici[indexPisica]) == true)
				cout << " Adultul poate adopta pisica\n";
			else
				cout << " Adultul nu poate adopta aceasta pisica\n";

			break;
		}

		case 14:
		{
			for (int i = 0; i < indexListaAdulti; i++)
			{
				cout << "Index adult: " << i << endl;
				cout << *listaAdulti[i] << endl;
			}

			for (int i = 0; i < indexListaCaini; i++)
			{
				cout << "Index caine: " << i << endl;
				cout << *listaCaini[i] << endl;
			}

			int indexAdult;
			cout << "Indexul adultului dorit: ";
			cin >> indexAdult;

			int indexCaine;
			cout << "Indexul cainelui dorit: ";
			cin >> indexCaine;
			cout << endl;

			if (listaAdulti[indexAdult]->poateAdoptaAdultul(*listaPisici[indexCaine]) == true)
				cout << " Adultul poate adopta cainele\n";
			else
				cout << " Adultul nu poate adopta acest caine\n";

			break;
		}

		case 15:
		{
			for (int i = 0; i < indexListaPensionari; i++)
			{
				cout << "Index pensionar: " << i << endl;
				cout << *listaPensionari[i] << endl;
			}

			for (int i = 0; i < indexListaPisici; i++)
			{
				cout << "Index pisica: " << i << endl;
				cout << *listaPisici[i] << endl;
			}

			int indexPensionar;
			cout << "Indexul pensionarului dorit: ";
			cin >> indexPensionar;

			int indexPisica;
			cout << "Indexul pisicii dorite: ";
			cin >> indexPisica;
			cout << endl;

			if (listaPensionari[indexPensionar]->poateAdoptaPensionarul(*listaPisici[indexPisica]) == true)
				cout << " Pensionarul poate adopta pisica\n";
			else
				cout << " Pensionarul nu poate adopta aceasta pisica\n";

			break;
		}

		case 16:
		{
			for (int i = 0; i < indexListaPensionari; i++)
			{
				cout << "Index pensionar: " << i << endl;
				cout << *listaPensionari[i] << endl;
			}

			for (int i = 0; i < indexListaCaini; i++)
			{
				cout << "Index caine: " << i << endl;
				cout << *listaCaini[i] << endl;
			}

			int indexPensionar;
			cout << "Indexul pensionarului dorit: ";
			cin >> indexPensionar;

			int indexCaine;
			cout << "Indexul cainelui dorit: ";
			cin >> indexCaine;
			cout << endl;

			if (listaPensionari[indexPensionar]->poateAdoptaPensionarul(*listaPisici[indexCaine]) == true)
				cout << " Pensionarul poate adopta cainele\n";
			else
				cout << " Pensionarul nu poate adopta acest caine\n";

			break;
		}
		
		case 17:
		{
			for (int i = 0; i < indexListaHranaUscata; i++)
			{
				cout << "Index hrana uscata: " << i << endl;
				cout << *listaHranaUscata[i] << endl;
			}

			int indexHranaUscata;
			cout << "Indexul hranii uscate dorite: ";
			cin >> indexHranaUscata;
			cout << endl;

			cout << "Discountul oferit pentru aceasta hrana uscata este de "
				<< listaHranaUscata[indexHranaUscata]->calculeazaDiscountHranaUscata() << " lei" << endl;
			break;
		}

		case 18:
		{
			for (int i = 0; i < indexListaHranaUmeda; i++)
			{
				cout << "Index hrana umeda: " << i << endl;
				cout << *listaHranaUmeda[i] << endl;
			}

			int indexHranaUmeda;
			cout << "Indexul hranii umede dorite: ";
			cin >> indexHranaUmeda;
			cout << endl;

			cout << "Discountul oferit pentru aceasta hrana umeda este de "
				<< listaHranaUmeda[indexHranaUmeda]->calculeazaDiscountHranaUmeda() << " lei" << endl;
			break;
		}

		case 19:
		{
			for (int i = 0; i < indexListaPisici; i++)
			{
				cout << "Index pisica: " << i << endl;
				cout << *listaPisici[i] << endl;
			}

			int indexPisica;
			cout << "Indexul pisicii dorite: ";
			cin >> indexPisica;
			cout << endl;


			bool copieAreProblemeSpeciale = listaPisici[indexPisica]->getAreProblemeSpeciale();

			if (copieAreProblemeSpeciale == false && listaPisici[indexPisica]->verificaObezitate() == false)
				cout << " Pisica nu are nicio problema speciala\n";
			else
				if (copieAreProblemeSpeciale == true && listaPisici[indexPisica]->verificaObezitate() == false)
					cout << " Pisica nu are probleme cu obezitatea, dar are alte probleme speciale\n";
				else
					cout << " Pisica are probleme cu obezitatea\n";
			break;
		}

		case 20:
		{
			for (int i = 0; i < indexListaCaini; i++)
			{
				cout << "Index caine: " << i << endl;
				cout << *listaCaini[i] << endl;
			}

			int indexCaine;
			cout << "Indexul cainelui dorit: ";
			cin >> indexCaine;
			cout << endl;


			bool copieAreProblemeSpeciale = listaCaini[indexCaine]->getAreProblemeSpeciale();

			if (copieAreProblemeSpeciale == false && listaCaini[indexCaine]->verificaObezitate() == false)
				cout << " Cainele nu are nicio problema speciala\n";
			else
				if (copieAreProblemeSpeciale == true && listaCaini[indexCaine]->verificaObezitate() == false)
					cout << " Cainele nu are probleme cu obezitatea, dar are alte probleme speciale\n";
				else
					cout << " Cainele are probleme cu obezitatea\n";
			break;
		}

		default:
			cout << "Optiunea nu exista! " << endl;
			break;
		}
	}












	/*MixHrana h1;
	cin >> h1;
	cout << h1;*/
	/*Hrana h("BritCare",35,"pisica", true);
	cout << h.calculeazaDiscount();*/

	//HranaUscata hu("BritCare",2.66,"pisica",false,300);
	////cout << hu;
	////cout << endl;
	//HranaUscata hu1;
	//hu1 = hu;
	//cout << hu1;
	
	//HranaUscata hu2("BritCare", 2.66, "pisica", true, 600);
	//cout <<hu2.calculeazaDiscount();
	//cout << endl;
	//cout <<((Hrana) hu2).calculeazaDiscount();  // cout << hu2.Hrana::calculeazaDiscount();

	/*HranaUmeda hum3("Pedigree", 1.99, "caine", true, 35);
	cout << hum3.calculeazaDiscount();
	cout << endl;
	cout << hum3.Hrana::calculeazaDiscount();*/
	/*const Client c;
	Pisica p("Piscotel", 'M', 1, 2.7, 355, false, true);

	cout<<c.poateAdopta(p);*/

	/*Pensionar p;
	Adult a;
	Pisica pi("Piscotel", 'M', 1, 2.7, 355, false, true);
	cout << p.poateAdoptaPensionarul(pi);
	cout << endl;
	cout << a.poateAdoptaAdultul(pi);
	cout << endl;
	cout << p.poateAdopta(pi);*/

}
