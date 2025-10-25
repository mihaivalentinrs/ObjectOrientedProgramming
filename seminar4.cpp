#include <iostream>
#include <string>
using namespace std;

class Student {
	string nume;
	int nrNote;
	int* note;
	double buget;
public:
	Student(double _buget)
	{
		if (_buget > 0)
			this->buget = _buget;
		else
			this->buget = 0;
	}

	Student()
	{

	}
	void afisare() const  //protejam obiectul de la adresa this => marcam faptul ca este o functie de afisare nu de modificare
	{
		cout << "\nNume: " << this->nume;
		cout << "\nNumar de note: " << this->nrNote;
		cout << "\nNote: ";
		for (int i = 0; i < nrNote; i++)
		{
			cout << "Nota " << i + 1 << ":";
			cout << this->note[i] << "\n";
		}
		cout << "\nBuget:" << this->buget;
	}
	void setNote(int _nrNote, int* _note)
	{
		//de facut acasa
		//!obj deja exista
		if (_nrNote > 0 && _note != nullptr)
		{
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < nrNote; i++)
			{
				this->note[i] = _note[i];
			}

		}

	}
	void setNota(int _nota, int _index)
	{
	
		if (_index > this->nrNote || _index < 0)
			cout << "\nIndexul introdus este eronat!";
		else
			this->note[_index] = _nota;


	}
	int getNota(int _index)
	{
		
		return this->note[_index];
	}
	int getNrNote()
	{
		return this->nrNote;
	}
	
};
int main()
{
	Student s;
	int note[] = { 10, 8, 7, 5, 3 };
	s("Alex", 5, note, 4000);
	s.afisare();
return 0;
}
