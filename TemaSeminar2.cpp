#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Avem o lista de prieteni
//Format: Nume + Lista de prenume
//Sa se implementeze functia care primeste colectia 
//de nume si un nume sfant si returnam cate 
//cadouri sa cumparam

void case_sensitive_free(string& nume)
{
	for (int i = 0; i < nume.length(); i++)
	{
		nume[i] = tolower(nume[i]);
	}

}
int main()
{
	int n;
	int numar_cadouri = 0; //initializez numarul de cadouri cu 0

	//numarul de prieteni
	cout << "\nIntroduceti numarul de prieteni: ";
	cin >> n; //numarul de linii din matrice

	string** matrice_nume;
	matrice_nume = new string * [n];

	//vector pentru stocarea dimensiunii fiecarui nume
	int* marime_prenume = new int[n];


	string nume_sfant;
	cout << "Introduceti un nume de sfant: ";
	cin >> nume_sfant;
	case_sensitive_free(nume_sfant);
	//Indice pentru iteratia celui de-al doilea for

   //Primul for pentru a itera fiecare alocare
	for (int i = 0; i < n; i++)
	{
		int nr_prenume;
		cout << "Introduceti numarul de prenume pentru prietenul " << i + 1 << ":";
		cin >> nr_prenume;

		marime_prenume[i] = nr_prenume;
		matrice_nume[i] = new string[nr_prenume + 1];
		//se aloca dinamic fiecare linie din matrice

		cout << "Introduceti numele: ";
		cin >> matrice_nume[i][0];
		for (int j = 1; j <= nr_prenume; j++)
		{
			cout << "Introduceti prenumele " << j << ":";
			cin >> matrice_nume[i][j];

		}
		for (int j = 0; j < nr_prenume; j++) {
			case_sensitive_free(matrice_nume[i][j]);
			if (matrice_nume[i][j] == nume_sfant)
				numar_cadouri++;

		}


	}
	if (numar_cadouri == 1)
		cout << "Este necesar " << numar_cadouri << " cadou de cumparat!" << endl;
	else
	{
		if (numar_cadouri > 1)
			cout << "Sunt necesare " << numar_cadouri << " cadouri de cumparat!" << endl;
		else
			return -1;
	}




	//Al doilea for pentru a dezaloca memoria
	for (int i = 0; i < n; i++)
	{
		delete[] matrice_nume[i];
	}
	delete[] matrice_nume;
	delete[] marime_prenume;

	return 0;
}