#include <iostream>
#include <vector>
#include<string>

using namespace std;

class Dispositivo
{
public:
  friend class Control;

protected:
  bool encendido = false;
  string nombre;
};


class Bulb: public Dispositivo 
{
public:
    Bulb(){};
	Bulb(string _color):color(_color){}

	friend class Control;
  
private:
  string color;
};

class Fan: public Dispositivo
{
public:
    Fan(){};
	Fan(int _maximo_nivel): maximo_nivel(_maximo_nivel){}
private:
	int nivel = 0, maximo_nivel;
};


class Control{
  vector<Dispositivo*> dispositivos;
  public:
  	Control(){
      dispositivos[0] = new Bulb();
      dispositivos[1] = new Bulb();
      dispositivos[2] = new Bulb();
      dispositivos[3] = new Fan();
    };
  
  	void Prender(int number){
      dispositivos[number]->encendido = true;
    }

    void isOn(int number){
        cout << dispositivos[number]->encendido;
    }
};