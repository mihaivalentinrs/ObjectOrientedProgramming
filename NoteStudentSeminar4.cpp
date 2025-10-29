#include <iostream>
#include <string>
using namespace std;
//195353
//01953

class Student {
	string nume;
	int nrNote;
	int* note;
	double buget;
public:
	/*Student(double _buget)
	{
		if (_buget > 0)
			this->buget = _buget;
		else
			this->buget = 0;
	}*/

	Student(string _nume, int _nrNote, int* _note, double _buget)
	{
		this->nume = _nume;
		if (_nrNote > 0) 
		{
			this->nrNote = _nrNote;
			note = new int[nrNote];
			for (int i = 0; i < nrNote; i++)
			{
				this->note[i] = _note[i];
			}
		}
		else
		{
			cout << "\nNumarul de note introdus nu este valid!";
			this->nrNote = 0;
			this->note = nullptr;
			return;
		}
		
		if (_buget > 0)
			this->buget = _buget;
		else
			this->buget = 0;


	}
	void afisare() const  //protejam obiectul de la adresa this => marcam faptul ca este o functie de afisare nu de modificare
	{
		cout << "\nNume: " << this->nume;
		cout << "\nNumar de note: " << this->nrNote;
		cout << "\nNote: \n";
		for (int i = 0; i < nrNote; i++)
		{
			cout << "Nota " << i + 1 << ":";
			cout << this->note[i] << "\n";
		}
		cout << "Buget: " << this->buget;
		
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

	void stergereNote()
	{
		if (note != nullptr)
		{
			delete[] note;
			this->note = nullptr;

		}
		this->nrNote = 0;
	}
	void completareNoteZero()
	{
		for (int i = 0; i < this->nrNote; i++)
		{
			this->note[i] = 0;
			//setez toate notele la variabila minima	
		}
	}
	void stergereUltimaNota()
	{	
		if (this->nrNote <= 0 || this->note == nullptr)
			return;
		int* vector_nou = this->note;
		this->nrNote = this->nrNote - 1;
		if (this->nrNote >= 0)
		{	//daca avem ce sterge
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
			{
				this->note[i] = vector_nou[i];
			}
		}
		else
		{
			this->note = nullptr;
		}
		delete[] vector_nou;
		
	}
	void stergereaNotelorSubMedie(int medie)
	{
		int nr=0;//numar de note sub medie din vectorul de note al obiectului

		for (int i = 0; i < this->nrNote; i++)
		{
			if (this->note[i] < medie)
				nr++;
		}
		int* vector_intermediar = this->note;
		if (nr > 0)
		{
			this->nrNote = this->nrNote - nr;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
			{
				if (vector_intermediar[i] >= medie)
					this->note[i] = vector_intermediar[i];
			}
		}
		else
		{
			cout << "\nStudentul nu are note sub medie!";
			return;
		}
		delete[] vector_intermediar;
	}
	void dublareUltimaNota()
	{
		if (this->nrNote < 0 || this->note == nullptr)
			return;
		int dimensiune_veche = this->nrNote;
		this->nrNote = this->nrNote + 1;
		int* vector_intermediar = this->note;
		this->note = new int[this->nrNote];
		for (int i = 0; i < dimensiune_veche; i++)
		{
			this->note[i] = vector_intermediar[i];
		}
		this->note[this->nrNote-1] = vector_intermediar[dimensiune_veche-1];

		delete[] vector_intermediar;
	}


	
	//supraincarcarea operatorului
	friend ostream& operator<<(ostream& os, Student& stud)
	{
		os << "\nNumele studentului: " << stud.nume;
		os<<"\nNumarul de note: "<<stud.nrNote;
		for (int i = 0; i < stud.nrNote; i++)
		{	
			os << "\nNota " << i + 1 << ":";
			os << stud.note[i];
		}
		os << "\nBugetul studentului: ";
		os << stud.buget;
		return os;
	}
	//Destructor pentru eliberarea memoriei
	~Student()
	{
		delete[] note;
	}
	
};
int main()
{
	int note[] = { 10, 8, 7, 5, 3 };
	Student s("Alex", 5, note, 4000);
	/*cout << "\nAfisare inainte de supraincarcarea operatorului: ";
	s.afisare();
	cout << "\nAfisare dupa supraincarcarea operatorului: ";
	cout << s;
	cout << "\nCompletarea notelor cu zero.";
	s.completareNoteZero();*/
	/*cout << "\nAfisarea vectorului dupa stergerea ultimei note.";
	s.stergereUltimaNota();
	cout << s;*/
	/*cout << "\nEliminarea notelor sub medie.";
	s.stergereaNotelorSubMedie(5);
	cout << s;*/
	cout << "\nDublarea notei finale.";
	s.dublareUltimaNota();
	cout << s;
return 0;
}
