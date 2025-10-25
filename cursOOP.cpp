#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

class salariat

{

	int marca;
	char* numeSalariat;
	int numar_ora;
	static int generare_marca;

public:

	/*salariat() : marca(0), numar_ora(0), salariu_ora(0)

	{

		strcpy(ns, "Anumar_oranim");

	}*/

	salariat(int fmarca = 0, const char* fns = "Anumar_oranim", int fnumar_ora = 0, float fsalariu_ora = 0) : marca(generare_marca), numar_ora(fnumar_ora), salariu_ora(fsalariu_ora)

	{

		numeSalariat = new char[strlen(fns) + 1];

		strcpy(numeSalariat, fns);

	}



	salariat(const salariat& obs) : marca(generare_marca), numar_ora(obs.numar_ora), salariu_ora(obs.salariu_ora)
	{

		numeSalariat = new char[strlen(obs.numeSalariat) + 1];

		strcpy(numeSalariat, obs.numeSalariat);

	}

	void set_nr_ore(int k)

	{

		if (k >= 0) this->numar_ora = k;

	}

	void set_pl(char t)

	{

		numeSalariat[0] = t;

	}

	int get_nr_ore() { return numar_ora; }

	float get_salariu() { return this->numar_ora * salariu_ora; }

	/*void afisare()

	{

		cout << marca << "  " << numeSalariat << "  " << numar_ora << "  " << salariu_ora << "  " << get_salariu() << endl;

	}*/
	friend ostream& operator<<(ostream& os, salariat& s)
	{
		os  << s.marca << "  " << s.numeSalariat << "  " << s.numar_ora << "  " << s.salariu_ora << "  " << s.get_salariu() << endl;
		return os;
	}

	static int marcaSalariatUrmator()
	{
		return generare_marca;
	}
	~salariat() { delete[] numeSalariat; }

	salariat& operator = (const salariat& obs)
	{
		delete[] numeSalariat;
		numeSalariat = new char[strlen(obs.numeSalariat) + 1];
		strcpy(numeSalariat, obs.numeSalariat);
		numar_ora = obs.numar_ora;
		salariu_ora = obs.salariu_ora;
		return *this;
	}
private:

	float salariu_ora;

};
int salariat::generare_marca = 100;


void main()

{
	cout << "\nMarca urmatorului obiect: " << salariat::marcaSalariatUrmator() << endl;
	salariat s1, s2(150, "Ana", 55, 5.2), * ps;
	ps = new salariat(100, "Gigi", 50, 12.5);
	salariat s3 = s2; //operatie de initializare + constructor de copiere
	s2.set_pl('I');
	s1 = s2;
	//operatie de atribuire
	cout << "Dupa atribuire: ";
	//s1.afisare(); s2.afisare(); //s3.afisare(); ps->afisare();
	cout << s1 << s2 << endl;

	

}
