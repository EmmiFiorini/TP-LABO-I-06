#pragma once
#pragma once
#ifndef CHABILIDADES_H
#define CHABILIDADES_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

//declaro mi enum de combate, para utilizarlo en mi funcion entrenar

class cHabilidades
{
protected:
    unsigned int ataque;
    unsigned int defensa; //valor del 0 al 100, se obtiene con el m�todo entrenar habilidades
    unsigned int salud;//valor del 0 al 100. por cada combate perdido baja 50 puntos. Al llegar al 0 se llama a funcion baja en la clase correspondiente


public:
    cHabilidades(const cHabilidades& otrasHabilidades); //constructor x copia

    cHabilidades();

    cHabilidades(unsigned int ataque, unsigned int defensa, unsigned int salud);

    virtual ~cHabilidades() {}; //destructor virtual xq es una clase virtual pura

    /*El usuario elige si entrenar defensa o ataque, dependiendo lo que elija se le suma +10 puntos por cada entrenamiento.
    Sirve para dragon y/o vikingo*/
    void entrenar(bool habilidadaAentrenar);

    void curandero();

    unsigned int get_salud() { return this->salud; }
    unsigned int get_ataque() { return this->ataque; }
    unsigned int get_defensa() { return this->defensa; }

    void set_salud(unsigned int nuevaSalud) {
        this->salud = nuevaSalud;
    }

    virtual void nivel() = 0;//funcion virtual pura
    virtual void faltanteNuevoNivel() = 0;
    
    int formaDeAtaque();
};

#endif

