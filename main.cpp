#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Companie {
private:
	char* denumireCompanie;
	int numar_ani;
	int* venit_anual;
	int costuriOperationale;
	bool tip;

public:
	Companie()
	{
		this->denumireCompanie = new char[8];
		strcpy_s(this->denumireCompanie, strlen(this->denumireCompanie+1), "Anonim");
		this->numar_ani = 0;
		this->venit_anual = nullptr;
		this->costuriOperationale = 0;
		this->tip = false;
	}
	Companie(const char* _denumireCompanie, int _numar_ani,int* _venit_anual, int _costuriOperationale, bool _tip)
	{
		if (_denumireCompanie == nullptr) {
			cout << "\nEroare la constructia numelui.";
			this->denumireCompanie = nullptr;
		}
		else
		{
			this->denumireCompanie = new char[strlen(_denumireCompanie) + 1];
			strcpy_s(this->denumireCompanie, strlen(_denumireCompanie)+1, _denumireCompanie);

		}
		if (_numar_ani > 0) {
			this->numar_ani = _numar_ani;
			this->venit_anual = new int[numar_ani];
			for (int i = 0; i < this->numar_ani; i++)
			{
				this->venit_anual[i] = _venit_anual[i];

			}
		}

		else
		{
			this->numar_ani = 0;
			this->venit_anual = nullptr;
		}
		if (_costuriOperationale > 0) this->costuriOperationale = _costuriOperationale;
		else this->costuriOperationale = 0;

		this->tip = _tip;


	}
	void faliment(int x)
	{
		bool risc = false;
		for (int i = 0; i < x; i++)
		{
			if (this->venit_anual[i] <= this->costuriOperationale)
				risc = true;
		}
		if (!risc)
		{
			cout << "\nFirma nu este in postura de a da faliment in " << x << " ani.";

		}
		else
		{
			cout << "\nFirma este in postura de a da faliment in " << x << " ani.";

		}
	}
	void set_venit_anual(int *venit, int _numar_ani)
	{
		if (_numar_ani > 0 || venit!=nullptr) {
			this->numar_ani = _numar_ani;
			this->venit_anual = new int[this->numar_ani];
			for (int i = 0; i < this->numar_ani; i++)
			{
				if (venit[i] < 0)
					this->venit_anual[i] = venit[i];
			}
		}
	}

	void afisare()
	{
		cout << "\nApelul functiei de afisare.";
		cout << "\nDenumire companie: " << this->denumireCompanie;
		cout << "\nNumar ani: " << this->numar_ani;
		cout << "\nCosturi operationale: " << this->costuriOperationale;
		cout << "\nTip companie: " << (this->tip ? "Privat" : "Public");
		int venit_total = 0;
		for (int i = 0; i < this->numar_ani; i++)
		{
			venit_total += this->venit_anual[i];
		}
		cout << "\nVenit total: " << venit_total;
		cout << "\nAfisarea s-a finalizat!";
		
	}
	friend void modificare_vector(Companie& c, int venit_nou);
	friend istream& operator>>(istream& is, Companie& c)
	{
		cout << "\nIntroduceti denumirea companiei: ";
		is >> c.denumireCompanie;
		cout << "\nIntroduceti numarul de ani: ";
		is >> c.numar_ani;
		c.venit_anual = new int[c.numar_ani];
		cout << "\nIntroduceti elementele vectorului de venituri anuale: ";
		for (int i = 0; i < c.numar_ani; i++)
		{
			cout << "\nVenitul in anul " << i + 1 << ":";
			is >> c.venit_anual[i];

		}
		cout << "\nIntroduceti costurile operationale: ";
		is >> c.costuriOperationale;
		
		cout << "\nIntroduceti tipul companiei (0 - Stat/1 - Buget): ";
		is >> boolalpha >> c.tip;




	}


	~Companie()
	{
		if (this->denumireCompanie != nullptr)
		{
			delete[] this->denumireCompanie;
			this->denumireCompanie = nullptr;
		}
		if (this->venit_anual != nullptr)
		{
			delete[] this->venit_anual;
			this->venit_anual = nullptr;
		}
	}

};

void modificare_vector(Companie& c, int venit_nou)
{
	int* copie_venit;
	if (venit_nou > 0)
	{
		copie_venit = new int[c.numar_ani];
		for (int i = 0; i < c.numar_ani; i++)
		{
			copie_venit[i] = c.venit_anual[i];

		}
		delete[] c.venit_anual;
		c.venit_anual = new int[c.numar_ani + 1];
		for (int i = 0; i < c.numar_ani; i++)
		{
			c.venit_anual[i] = copie_venit[i];

		}
		{
			c.venit_anual[c.numar_ani] = venit_nou;
			c.numar_ani++;


			delete[] copie_venit;
		}

	}
	cout << "\nVector nou: ";
	for (int i = 0; i < c.numar_ani; i++)
	{
		cout << c.venit_anual[i] << " ";
	}
}
int main()
{
	int vector_venit[] = { 200, 600 };
	Companie c("IBM", 2, vector_venit, 120, true);
	c.afisare();
	c.faliment(2);
	modificare_vector(c, 400);



}