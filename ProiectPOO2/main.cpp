#include <iostream>
#include <string>

using namespace std;

class Hrana
{
private:
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
	double calculeazaDiscount();

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
	cout << "\nDistruge hrana:";
	cout << this->nume << endl;
}

//function
double Hrana::calculeazaDiscount()
{
	double discount = 0;
	if (this->estePtProblemeSpeciale == true)
		discount = 10 * 0.01 * this->pret;
	return discount;
}

class HranaUscata :public Hrana
{
private:
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
	double calculeazaDiscount();
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
	cout << "\nDistruge hrana uscata " << endl;
}

//function: 
double HranaUscata::calculeazaDiscount()
{
	double discountTotal = 0; // se calculeaza la totalul de grame, NU pe suta de grame
	
	if (this->grame >= 500 && this->grame < 1500)
		discountTotal = 15 * 0.01 * this->getPret();
	else
		if (this->grame >= 1500)
			discountTotal = 25 * 0.01 * this->getPret();
	
	if (((Hrana)*this).calculeazaDiscount() == 0)
		return discountTotal;
	else
		return discountTotal + ((Hrana)*this).calculeazaDiscount();
	
}

class HranaUmeda : public Hrana
{
private:
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
	double calculeazaDiscount();
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
	cout << "\nDistruge hrana umeda " << endl;
}

//function
double HranaUmeda::calculeazaDiscount()
{
	double discountPerPlic = 0; 
	double discountTotal = 0;

	if (this->nrPlicuri >= 15 && this->nrPlicuri < 35)
		discountPerPlic = 10 * 0.01 * this->getPret();
	else
		if (this->nrPlicuri >= 35)
			discountPerPlic = 20 * 0.01 * this->getPret();

	discountTotal = discountPerPlic * this->nrPlicuri;

	if (((Hrana)*this).calculeazaDiscount() == 0)
		return discountTotal;
	else
		return discountTotal + ((Hrana)*this).calculeazaDiscount();
}

class Animal
{
private:
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
	cout << "\nDistruge animalul: ";
	cout << this->nume << endl;
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
	cout << "\nDistruge pisica:" << endl;
}

//function 
bool Pisica::verificaObezitate()
{
	bool obezitatePisica = false;
	int criteriuObezitatePisica;
	if (this->getVarsta() < 2)
		criteriuObezitatePisica = 7;
	else
	{
		if (this->getVarsta() >= 2 && this->getVarsta() <= 10)
			criteriuObezitatePisica = 12;
		else
			criteriuObezitatePisica = 10;
	}

	if (this->getGreutate() >= criteriuObezitatePisica)
	{
		this->setAreProblemeSpeciale(true);
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
	cout << "\nDistruge caine " << endl;
}

//function
bool Caine::verificaObezitate()
{
	bool obezitateCaine = false;
	int criteriuObezitateCaine;
	if (this->getVarsta() < 2)
		criteriuObezitateCaine = 25;
	else
	{
		if (this->getVarsta() >= 2 && this->getVarsta() <= 10)
			criteriuObezitateCaine = 35;
		else
			criteriuObezitateCaine = 30;
	}

	if (this->getGreutate() >= criteriuObezitateCaine)
	{
		this->setAreProblemeSpeciale(true);
		obezitateCaine = true;
	}

	return obezitateCaine;
}

class Cal :public Animal
{
private:
	bool arePotcoave;

public:
	//setter
	void setArePotcoave(bool arePotcoave) { this->arePotcoave = arePotcoave; }

	//getter
	bool getArePotcoave() { return this->arePotcoave; }

	//constructor fara parametrii
	Cal();

	//constructor cu toti parametrii
	Cal(string nume, char sex, int varsta, double greutate, double pret, bool areProblemeSpeciale, bool arePotcoave);

	//copy constructor
	Cal(const Cal& other);

	//overload operator=
	Cal& operator=(const Cal& other);

	//overload operator<<
	friend ostream& operator<<(ostream& out, const Cal& c);

	//overload operator>>
	friend istream& operator>>(istream& in, Cal& c);

	//destructor
	~Cal();

	//function
	bool verificaObezitate();
};

//constructor fara parametrii
Cal::Cal() :Animal()
{
	this->arePotcoave = false;
}

//constructor cu toti parametrii
Cal::Cal(string nume, char sex, int varsta, double greutate, double pret, bool areProblemeSpeciale, bool arePotcoave)
	:Animal(nume, sex, varsta, greutate, pret, areProblemeSpeciale)
{
	this->arePotcoave = arePotcoave;
}

//copy constructor
Cal::Cal(const Cal& other) :Animal(other)
{
	this->arePotcoave = other.arePotcoave;
}

//overload operator=
Cal& Cal::operator=(const Cal& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->arePotcoave = other.arePotcoave;
	}
	return *this;
}

//overload operator<<
ostream& operator<<(ostream& out, const Cal& c)
{
	out << (const Animal&)c;
	out << "\nAre potcoave: " << c.arePotcoave << endl;
	return out;
}

//overload operator>>
istream& operator>>(istream& in, Cal& c)
{
	in >> (Animal&)c;
	cout << "\nAre potcoave: ";
	in >> c.arePotcoave;
	cout << endl;
	return in;
}

//destructor
Cal::~Cal()
{
	cout << "\nDistruge cal " << endl;
}

//function
bool Cal::verificaObezitate()
{
	bool obezitateCal = false;
	int criteriuObezitateCal;
	if (this->getVarsta() < 2)
		criteriuObezitateCal = 150;
	else
	{
		if (this->getVarsta() >= 2 && this->getVarsta() <= 10)
			criteriuObezitateCal = 500;
		else
			criteriuObezitateCal = 450;
	}

	if (this->getGreutate() >= criteriuObezitateCal)
	{
		this->setAreProblemeSpeciale(true);
		obezitateCal = true;
	}

	return obezitateCal;
}

class Client
{
private:
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
	bool poateAdopta(Animal& a);
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
	cout << "\nDistruge client ";
	cout << this->numePrenume << endl;
}

//function 
bool Client::poateAdopta(Animal& a)
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
	bool poateAdopta();
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
	cout << "\nDistruge adult " << endl;
}

//function
bool Adult::poateAdopta()
{
	
}














int main()
{
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
	Client c;
	Pisica p;

	cout<<c.poateAdopta(p);



	
}