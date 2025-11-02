#include <iostream>
using namespace std;


class Produs {
	//to do home (denumire initializata cu anonim)
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;
	//camp constant??
	//camp static??
	//Design Pattern Builder - Research Net - Ofera posibilitate de construire obiect
public:
	Produs()
	{
		cout << "\nApel constructor fara parametri.";

	}
	
	Produs(const char* _denumire, int _stoc, double _pret)
	{
		if (_denumire!=nullptr && strlen(_denumire) > 3) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy_s(this->denumire, strlen(_denumire) + 1, _denumire);

		}
		if (_stoc > 0)
		{
			this->stoc = _stoc;

		}
		if (_pret > 0)
		{
			this->pret = _pret;
		}
	}
	//chiar daca e const ce anume pot modifica din p
	Produs(const Produs& p) //const pentru a-l proteja pe p
	{
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);

		}
		if (p.stoc > 0)
		{
			this->stoc = p.stoc;

		}
		if (p.pret > 0)
		{
			this->pret = p.pret;
		}
	}
	void afisare()
	{
		cout << "\nDenumire: ";
		if (this->denumire != nullptr)
			cout << this->denumire;
		else
			cout << "\nEroare!";
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}

	Produs operator=(const Produs& p)
	{ //obiectul this deja exista aici
		if (this->denumire != nullptr)
		{
			delete[] this->denumire;
			this->denumire = nullptr;

		}
		if (this != &p)
		{
			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);

			}
			else
			{
				this->denumire = nullptr;
			}
			if (p.stoc > 0)
			{
				this->stoc = p.stoc;

			}
			if (p.pret > 0)
			{
				this->pret = p.pret;
			}
			
		}
		else
		{
			return *this;
		}
		return *this;
		//dereferentierea this-ului
		//pentru a putea folosi operatorul in compunere
	}

	//destructor este folosit pentru a dezaloca tot ce se afla pe heap
	~Produs()
	{
		cout << "\nApel destructor.";
		if (this->denumire != nullptr)
		{
			delete[] this->denumire;
			this->denumire = nullptr;

		}
	}

};
Produs functieGlobala(Produs p)
{
	return p;
}
int main()
{
	Produs p1;
	Produs p2("Carte", 100, 120);
	p1.afisare();
	p2.afisare();
	Produs p3 = p2;
	Produs p4(p3);
	Produs p5;
	cout << "\n---------------";
	functieGlobala(p5);
	cout << "\n-----------------";
	/*Produs* pp = new Produs();
	delete[] pp;
	pp = nullptr;
*/
	p3 = p2;
	p1 = p1;
	//auto asignare
	p1.afisare();


	//constructor de copiere exista default dar nu gestioneaza corect alocare dinamica
	return 0;
}