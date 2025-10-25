#include <iostream>
using namespace std;

//o clasa care 
// utilizeaza abstractizare si encapsulare 
// defineste un tip abstract de data
class distantaPuncte {
	private:
	float x;
	float y;

public:
	distantaPuncte()
	{
		this->x = 0.0;
		this->y = 0.0;
	}
	distantaPuncte(float a, float b)
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

};
int main()
{
	distantaPuncte a(1.0, 2.0);
	distantaPuncte b(2.4, 4.5);
	cout << "Punctele initializate: " << a << b;
	// de supraincarcat operatorul cu ostream si friend
	



	return 0;
}