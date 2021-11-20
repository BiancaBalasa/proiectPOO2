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

	//function:
	double calculeazaDiscount();

};

// constructorul fara parametrii
Hrana::Hrana()
{
	//cout << "Constructor gol hrana:\n";
	this->nume = "Anonim";
	this->pret = 0;
	this->tipAnimal = "Anonim";
	this->estePtProblemeSpeciale = false;
}

// constructorul cu toti parametrii
Hrana::Hrana(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale)
{
	//cout << "Constructor cu toti parametrii hrana:\n";
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
	cout << "\nDistruge hrana: ";
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
	//HranaUscata& operator=(const HranaUscata& other);


	//overload operator<<
	friend ostream& operator<<(ostream& out, const HranaUscata& hu);

	//destructor
};

HranaUscata::HranaUscata() :Hrana()
{
	//cout << "Constructor gol hr uscata:\n";
	this->grame = 0;
}

HranaUscata::HranaUscata(string nume, double pret, string tipAnimal, bool estePtProblemeSpeciale, int grame) : Hrana(nume, pret, tipAnimal, estePtProblemeSpeciale)
{
	//cout << "Constructor cu toti parametrii hr uscata:\n";
	this->grame = grame;
}

ostream& operator<<(ostream& out, const HranaUscata& hu)
{
	out << (const Hrana&)hu;
	out << "\nGrame: " << hu.grame;
	return out;
}

HranaUscata::HranaUscata(const HranaUscata& other):Hrana(other)
{
	this->grame = other.grame;
}

//HranaUscata& HranaUscata :: operator=(const HranaUscata& other)
//{
//	cout << "petru\n";
//	if (this != &other)
//	{
//		HranaUscata
//		(Hrana)*this = (Hrana&)other;
//		this->grame = other.grame;
//
//	}
//	return *this;
//}



int main()
{
	/*Hrana h("BritCare",35,"pisica", true);
	cout << h.calculeazaDiscount();*/

	HranaUscata hu("BritCare",34.99,"pisica",false,300);
	//cout << hu;
	//cout << endl;
	HranaUscata hu1;
	hu1 = hu;
	cout << hu1;


	
}