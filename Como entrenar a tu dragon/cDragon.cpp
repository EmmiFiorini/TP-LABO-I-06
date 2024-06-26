#include "cDragon.h"

cDragon::~cDragon() {

}
//aparece en el main
cDragon::cDragon(string nombre, string caracteristica, tamanio tamanyoDragon, string color, bool estado, string level, unsigned int ataque, unsigned int defensa, unsigned int salud) : cHabilidades(ataque, defensa, salud)
{
    this->nombre = nombre;
    this->caracteristica = caracteristica;
    this->tam = tamanyoDragon;
    this->color = color;
    this->estado = estado;
    this->level = level;
}

void cDragon::print() //aparece en cAdministradora::switch_menu y en cJinete::entrenarDragon
{
    cout << to_string() << endl;
    faltanteNuevoNivel();
}

string cDragon::to_string() { //aparece en el metodo de arriba
    stringstream ss;
    ss << "Tu dragon: " << nombre << "\t Salud: " << salud << "\t Ataque: " << ataque << "\t Defensa: " << defensa << endl;
    cout << "\n" << endl;
    return ss.str();
}

void cDragon::faltanteNuevoNivel() //aparece en el metodo print()
{
    cout << "El nivel actual de tu dragon es: " << this->level << endl;
    int n = 0;
    if (ataque < 100) {
        if (ataque <= 30) {
            n = 31 - ataque;
        }
        if (ataque > 30 && ataque <= 60) {
            n = 61 - ataque;
        }
        if (ataque > 60 && ataque < 100) {
            n = 100 - ataque;
        }
        cout << "Le falta aumentar su ataque en " << n << " puntos para llegar al siguiente nivel!" << endl;
    }
    else {
        cout << "Ya estas en el maximo nivel!" << endl;
    }
}

void cDragon::nivel() //se usa en el metodo cJinete::entrenarDragon
{
    if (ataque <= 30) {
        this->level = "1: morder";
    }
    if (ataque > 30 && ataque <= 60) {
        this->level = "2: alas";
    }
    if (ataque > 60 && ataque<100) {
        this->level = "3: garras";
    }
    if (ataque >= 100)
        this->level = "4: fuego";
}


cDragon::cDragon() : cHabilidades() {//constructor nulo
    this->nombre = "";
    this->caracteristica = "";
    this->tam = tamanio::desconocido;
    this->color = "";
    this->estado = false;
    this->level = "";
}













