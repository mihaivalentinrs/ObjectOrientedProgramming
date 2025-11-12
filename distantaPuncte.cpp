#include <iostream>
#include <math.h>
using namespace std;

//o clasa care 
// utilizeaza abstractizare si encapsulare 
// defineste un tip abstract de data
class Puncte {
private:
	float x;
	float y;

public:
	Puncte()
	{
		this->x = 0.0;
		this->y = 0.0;
	}
	Puncte(float a, float b)
	{
		this->x = a;
		this->y = b;
	}
	//creez setter si getter pentru x si y
	void set_x(float a)
	{
		
		this->x = a;
	}

	void set_y(float b)
	{
		this->y = b;
	}

	float get_x()
	{
		return this->x;
	}
	float get_y()
	{
		return this->y;

	}

	
	friend istream& operator>>(istream& is, Puncte& p)
	{
		
			cout << "\nX: ";
			is >> p.x;
			cout << "\nY: ";
			is >> p.y;
			return is;
		
	}
	friend ostream& operator<<(ostream& os, Puncte& p)
	{
		
			cout << "\nX: ";
			os << p.x;
			cout << "\nY: ";
			os << p.y;
			return os;
		
	}
	friend float distantaPuncte(Puncte& a, Puncte& b);



};
float distantaPuncte(Puncte& a, Puncte& b)
{
	float distanta = 0;
	float distanta_finala = 0;
	//dist = radical(sum(xi-yi)^2)
	distanta = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	distanta_finala = sqrt(distanta);
	return distanta_finala;

}
int main()
{
	cout << "\nSe vor introduce doua puncte pentru a le calcula distanta!";
	Puncte a;
	Puncte b;
	cout << "\nIntroduceti datele necesare calcularii distantei: ";
	cout << "\nIntroduceti datele pentru primul set de puncte.";
	cin >> a;
	cout << "\nIntroduceti datele pentru al doilea set de puncte. ";
	cin >> b;
	cout << "\nDistanta dintre cele doua puncte: ";
	float distanta = distantaPuncte(a, b);
	cout << distanta;



	// de supraincarcat operatorul cu ostream si friend




	return 0;
}