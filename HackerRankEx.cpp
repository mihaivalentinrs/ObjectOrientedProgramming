#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
protected:
    string name;
    int age;
    
public:
    
    Person()
    {
        this->name = "Anonim";
         this->age = 0;       

    }
    Person(string _name, int _age)
    {
        if (size(_name)>=1 && size(_name)<=100)
            this->name = _name;
        else
            this->name = "Anonim";
        if (_age >0 && _age <=80)
            this->age = _age;
        else
            this->age = 0;
      
    }
    virtual void getdata() = 0;
    virtual void putdata() = 0;
    
    virtual ~Person() {}

};
class Professor : public Person {
private:
    int publications;
    int cur_id;
    static int val;


public:
    Professor():Person(), publications(0), cur_id(++val){}
    
    Professor(string name, int age, int _publications): Person(name, age)
    {
        
        if (_publications >= 1 && _publications<=1000)
            this->publications = _publications;
        else
            this->publications = 0;

        this->cur_id = ++val;

    }

    void getdata() override
    {
        cin >> this->name;
        cin >> this->age;
        cin >> this->publications;
       
    }

    void putdata() override
    {
        cout << "\nName: " << this->name;
        cout << "\nAge: " << this->age;
        cout << "\nPublications: " << this->publications;
        cout << "\nCurrent id: " << this->cur_id;
        
    }


};
int Professor::val = 0;

class Student : public Person {
private:
    int marks[6];
    int cur_id;
    static int val;
    
public:
    Student() :Person(), cur_id(++val) {
        for (int i = 0; i < 6; i++)
            this->marks[i] = 0;
    }
    Student(string name, int age, int _marks[6]):Person(name, age)
    {
        
        for (int i = 0; i < 6; i++)
        {
            if (_marks[i] >= 0 && _marks[i] <= 100)
                this->marks[i] = _marks[i];
        }
        this->cur_id = ++val;
    }
    int marksSum() const
    {   
        int sum = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += marks[i];
        }
        return sum;
    }
    void getdata() override
    {
        cin >> this->name;
        cin >> this->age;
        for (int i = 0; i < 6; i++)
        {
            cout << "Mark " << i + 1 << ":";
            cin >> this->marks[i];
        }

    }

    void putdata() override
    {
        cout << "\nName: " << this->name;
        cout << "\nAge: " << this->age;
        cout << "\nMarks sum: " << marksSum();
        cout << "\nCurrent id: " << this->cur_id;

    }

};
int Student::val= 0;
int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
