#include <iostream>
using namespace std;

struct dataCalendatristica {
	int zi, luna, an;
};

///multime formata din constante globale\
///daca prima valoare este setata manual celalalte cresc secvential cu o unitate
enum FormaInvatamant
{
	IF, ID, IFR
};
class Student {
private:
	char* nume;
	bool areBursa;
	FormaInvatamant formaInvatamant;
	double medieAdmitere;
public:
	Student() {

		cout << "\nApel constructor fara parametrii!" << "\n";
		///pointerul this -> adresa obiectului apelator
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
		this->areBursa = false;
		///similar cu (*this).areBursa;
		///nu lasam variabile neinitializate
		this->formaInvatamant = FormaInvatamant::IF;
		///"::" operator de rezolutie
		this->medieAdmitere = 0.0;

	}
	///meth acceser - getter si setter
	double getmedieAdmitere()
	{
		return this->medieAdmitere;

	}

	void setmedieAdmitere(double medieAdmitereNoua)
	{
		if (medieAdmitereNoua >= 5 && medieAdmitereNoua <= 10)
			this->medieAdmitere = medieAdmitereNoua;
	}

	FormaInvatamant getFormaInvatamant()
	{
		return this->formaInvatamant;
	}
	void setFormaInvatamant(FormaInvatamant _FormaInvatamant)
	{
		this->formaInvatamant = _FormaInvatamant;

	}

	char* getNume_Versiunea1()
	{
		return this->nume;
	}
	const char* getNume_Versiunea2()
	{
		return this->nume;
	}
	char* getNume_VersiuneaCorecta()
	{
		char* copie = new char[strlen(this->nume) + 1];
		strcpy_s(copie, strlen(this->nume) + 1, this->nume);
		return copie;

	}
	/// aceasta tehnica ne obliga sa facem dezalocare la copie - memorie heap

};

int main()
{
	Student s;
	cout << "\nMedie admitere: " << s.getmedieAdmitere();
	s.setmedieAdmitere(9);
	cout << "\nMedia dupa utilizarea setterului: " << s.getmedieAdmitere() << endl;

	return 0;
}

///Tema: lucru cu clase si cu method accessere
