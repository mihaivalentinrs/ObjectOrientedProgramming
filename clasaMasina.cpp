#include <iostream>
using namespace std;

class masina {
	private:
		int capacitate_rezervor;
		int volum_curent;
		float* alimentari;
		int nr_alimentari;
		
public:
	masina()
	{
		this->capacitate_rezervor = 0;
		this->volum_curent = 0;
		this->alimentari = nullptr;
		this->nr_alimentari = 0;
	}
	masina(int _capacitate_rezervor, int _volum_curent, float* _alimentari, int _nr_alimentari)
	{
		this->capacitate_rezervor = _capacitate_rezervor;
		this->volum_curent = _volum_curent;
		this->nr_alimentari = _nr_alimentari;
		this->alimentari = new float[nr_alimentari];
		for (int i = 0; i < nr_alimentari; i++)
		{
			this->alimentari[i] = _alimentari[i];
		}
	}
	//getter si setter pentru elementele private ale clasei
	void set_capacitate_rezervor(int capacitate_rezervor)
	{
		this->capacitate_rezervor = capacitate_rezervor;
	}
	int get_capacitate_rezervor()
	{
		return this->capacitate_rezervor;
	}
	void set_volum_curent(int l)
	{
		if (l > 0 && l < 120)
		{
			this->volum_curent = l;
		}

	}
	int get_volum_curent()
	{
		return this->volum_curent;
	}

	void set_nr_alimentari(int _max) //setam numarul de alimentari la un maxim impus de utilizator
	{
		this->nr_alimentari = _max;
	}
	int get_nr_alimentari()
	{
		return this->nr_alimentari;
	}

	void set_alimentari(float *_alimentari)
	{
		if (this->nr_alimentari <= 0)
			return;
		else {
			for (int i = 0; i < this->nr_alimentari; i++)
			{
				this->alimentari[i] = _alimentari[i];
			}
		}
	}
	float get_alimentare(int _index)
	{
		return this->alimentari[_index];
	}

	void consum_combustibil(float _consum, int distanta)
	{
		float litri_consumati = 0;
		if (this->volum_curent > 0) {
			if (_consum < 0 && distanta<0)
			{
				cout << "\nConsum imposibil si distanta eronata!";
				return;
			}
			else
			{
				litri_consumati = _consum * distanta / 100;
				if (this->volum_curent - litri_consumati > 0)
					this->volum_curent = this->volum_curent - litri_consumati;
				else
					cout << "\nConsumul a depasit maximul!";
			}
		}
	}
	float consum_mediu(float* consum_instant, int n)
	{
		float consum_mediu = 0.0;
		for (int i = 0; i < n; i++)
		{
			consum_mediu = consum_mediu + consum_instant[i];
			
		}
		consum_mediu = consum_mediu / n;
		return consum_mediu;
	}

	friend istream& operator>>(istream& is, masina& m)
	{
		cout << "\nIntroduceti capacitatea rezervorului: ";
		is >> m.capacitate_rezervor;
		cout << "\nIntroduceti volumul curent: ";
		is >> m.volum_curent;
		cout << "\nIntroduceti numarul de alimentari: ";
		is >> m.nr_alimentari;
		cout << "\n";
		for (int i = 0; i < m.nr_alimentari; i++)
		{
			cout << "Introduceti alimentarea " << i + 1 << " :";
			is >> m.alimentari[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, masina& m)
	{
		cout << "\nCapacitatea rezervorului actualizata pentru output: ";
		os << m.capacitate_rezervor;
		cout << "\nVolumul curent: ";
		os << m.volum_curent;
		cout << "\nNumarul de alimentari: ";
		os << m.nr_alimentari;
		cout << "\n";
		for (int i = 0; i < m.nr_alimentari; i++)
		{
			cout << "Alimentarea " << i + 1 << " :";
			os<<m.alimentari[i];
		}
		return os;

	}

	~masina() { delete[] alimentari; }


};

int main()
{
	masina m;
	cin >> m;

	return 0;
}