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
    friend class Control;
private:
	int nivel = 0, maximo_nivel;
};


class Control{
  vector<Dispositivo*> dispositivos;
  public:
  	Control(){
      dispositivos.push_back(new Bulb("red"));
      dispositivos.push_back(new Bulb("amarillo"));
      dispositivos.push_back(new Bulb("azul"));
      dispositivos.push_back(new Fan(4));
    };
  
  	void Presionar(int number){
      dispositivos[number]->encendido = !dispositivos[number]->encendido;
    }

    void isOn(int number){
        cout << dispositivos[number]->encendido << endl;
    }
};