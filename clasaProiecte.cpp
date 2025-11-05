#include <iostream>
#include <istream>
using namespace std;
enum CategorieProiect
{
	IT, Management, ResurseUmane
};
class Proiecte {
private:

	char* denumireProiect;
	int nrMembri;
	int nrEtape;
	int* bugetEtape;
	bool tipProiect;
	CategorieProiect catP;
public:
	Proiecte()
	{
		this->denumireProiect = new char[8];
		strcpy_s(this->denumireProiect, strlen("Anonim") + 1, "Anonim");
		this->nrMembri = 0;
		this->nrEtape = 0;
		this->bugetEtape = nullptr;
		this->tipProiect = false;
		this->catP = CategorieProiect::IT;

	}
	Proiecte(char* _denumireProiect, int _nrMembri, int _nrEtape, int* _bugetEtape, bool _tipProiect, CategorieProiect _catP)
	{
		if (_denumireProiect != nullptr && strlen(_denumireProiect) > 2)
		{
			this->denumireProiect = new char[strlen(_denumireProiect) + 1];
			strcpy_s(this->denumireProiect, strlen(_denumireProiect) + 1, _denumireProiect);
		}
		else
		{
			this->denumireProiect = new char[8];
			strcpy_s(this->denumireProiect, strlen("Anonim") + 1, "Anonim");
		}
		if (_nrMembri < 0) 
		{
			this->nrMembri = 0;

		}
		else {
			this->nrMembri = _nrMembri;
		}
		if (_nrEtape < 0 || _bugetEtape==nullptr)
		{
			this->nrEtape = 0;
			this->bugetEtape = nullptr;
		}
		else
		{
			this->nrEtape = _nrEtape;
			this->bugetEtape = new int[this->nrEtape];
			for (int i = 0; i < this->nrEtape; i++)
			{
				if (_bugetEtape[i] > 0)
					this->bugetEtape[i] = _bugetEtape[i];
				else
					this->bugetEtape[i] = 0;
			}
		}
		this->tipProiect = _tipProiect;
		this->catP = _catP;
	}
	void const afisare_Proiecte()
	{
		cout << "\nApelul functiei de afisare!\n";
		cout << "\nDenumirea Proiectului: " << this->denumireProiect << " ";
		cout << "\nNumarul de membri: " << this->nrMembri << " ";
		cout << "\nNumarul de etape: " << this->nrEtape << " ";
		int buget_total = 0;
		for (int i = 0; i < this->nrEtape; i++)
		{
			buget_total += this->bugetEtape[i];
		}
		cout << "\nBugetul total pentru toate etapele: " << buget_total << " ";
		cout << "\nTipul proiectului: " << (this->tipProiect ? "Stat" : "Privat");
		cout << "\nCategoria - departamentul proiectului: ";

		switch (this->catP) {
		case IT: cout << "IT"; break;
		case Management: cout << "Management"; break;
		case ResurseUmane: cout << "Resurse Umane"; break;
		}
		cout << "\n";


	}
	void set_numar_membri(int _nrMembri)
	{
		if (_nrMembri > 0)
			this->nrMembri = _nrMembri;
		else
			this->nrMembri = 0;

	}
	int get_numar_membri()
	{
		int copie = this->nrMembri;
		return copie;
	}
	int get_numar_etape()
	{
		if (this->nrEtape > 0)
			return this->nrEtape;
	}
	int* get_buget_etape()
	{
		if (this->bugetEtape != nullptr) {
			int* copie_buget;
			copie_buget = new int[this->nrEtape];
			for (int i = 0; i < this->nrEtape; i++)
			{
				copie_buget[i] = this->bugetEtape[i];

			}
			return copie_buget;
		}
		else
			return nullptr;

	}

	void adaugareEtapa(int _bugetEtapaNoua)
		//numar etape - 5
	{	//maresti alocarea cu unu  - 1 2 3 7 8
		//vrei sa adaugi 7
		int* copieBugete;
		copieBugete = new int[this->nrEtape];
		for (int i = 0; i < this->nrEtape; i++)
		{
			copieBugete[i] = this->bugetEtape[i];
		}
		delete[] this->bugetEtape;
		this->bugetEtape = new int[this->nrEtape + 1];
		
		for (int i = 0; i <this->nrEtape; i++)
		{
			this->bugetEtape[i] = copieBugete[i];
		}
		this->bugetEtape[this->nrEtape] = _bugetEtapaNoua;
		this->nrEtape++;

		cout << "\nNoul vector de bugete: ";
		for (int i = 0; i < this->nrEtape; i++)
		{
			cout << this->bugetEtape[i] << " ";
			
		}
		cout << "\n";
		delete[] copieBugete;
	}
	friend void verificareAdaugareEtapa(Proiecte& p);
	friend istream& operator>>(istream& os, Proiecte& p)
	{
		cout << "\nIntroduceti denumirea proiectului: ";
		char buffer[100];
		os >> buffer;

		// Dezalocă memoria veche și alocă nouă
		if (p.denumireProiect != nullptr) {
			delete[] p.denumireProiect;
		}
		
		p.denumireProiect = new char[strlen(buffer) + 1];
		strcpy_s(p.denumireProiect, strlen(buffer) + 1, buffer);
		cout << "\nIntroduceti numarul de membri: ";
		os >> p.nrMembri;
		cout << "\nIntroduceti numarul de etape: ";
		os >> p.nrEtape;
		p.bugetEtape = new int[p.nrEtape];
		for (int i = 0; i < p.nrEtape; i++)
		{
			cout << "\nIntroduceti bugetul pentru etapa " << i + 1 << ":";
			os >> p.bugetEtape[i];
		}
		cout << "\nIntroduceti tipul de proiect (True - Stat/False - Privat).";
		os >>boolalpha>> p.tipProiect;
		int categ;
		cout << "\nIntroduceti departamentul proiectului(0 - IT/1 - Management/2 - Resurse Umane): ";
		os >>categ;
		p.catP = static_cast<CategorieProiect>(categ);
		return os;
	}
	~Proiecte()
		
	{
		if (this->denumireProiect != nullptr)
		{
			delete[] this->denumireProiect;
			this->denumireProiect = nullptr;
		}
		if (this->bugetEtape != nullptr)
		{
			delete[] this->bugetEtape;
			this->bugetEtape = nullptr;
		}
	}

};
//Să se implementeze o funcție globală care să verifice dacă o nouă etapă poate fi adăugată ca ultimă etapă a unui vector de
//bugete.
void verificareAdaugareEtapa(Proiecte& p)
{
	bool adaugare = false;
	if (p.bugetEtape[p.nrEtape - 1] == 0)
		adaugare = false;
	else
		adaugare = true;

	if (adaugare)
		cout << "\nAdaugarea unei noi etape este posibila!";
	else
		cout << "\nAdaugarea unei noi etape nu este posibila.";

	cout << "\n";
}

int main()
{
	/*int bugetEtape[] = {4, 5, 6, 7};
	char denumire[] = {"Anonim"};
	Proiecte p(denumire, 5, 4, bugetEtape, false, IT);
	
	p.adaugareEtapa(200);
	p.afisare_Proiecte();
	verificareAdaugareEtapa(p);*/
	
	Proiecte* p;
	int nr_obiecte;
	int bugetNou = 0;
	cout << "\nIntroduceti numarul de obiecte: ";
	cin >> nr_obiecte;
	p = new Proiecte[nr_obiecte];
	for (int i = 0; i < nr_obiecte; i++)
	{
		cin >> p[i];
		int nr_etape = p[i].get_numar_etape();
		int* vector = p[i].get_buget_etape();
		for (int i = 0; i < nr_etape; i++)
		{
			cout << "Elementul " << i + 1 << " din vectorul returnat de functie: \n" << vector[i]<<" "<<endl;

		}
		p[i].afisare_Proiecte();
		cout << "\nIntroduceti bugetul etapei noi pentru verificarea functiilor: ";
		cin >> bugetNou;
		p[i].adaugareEtapa(bugetNou);
		verificareAdaugareEtapa(p[i]);
	}

	delete[] p;

	return 0;
}