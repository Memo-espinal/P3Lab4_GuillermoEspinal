#include "Persona.h"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string Persona::getContra(){
	return contra ;
}
string Persona::getNombre(){
	return nombre ;
}
int Persona::getLlave(){
	return llave ;
}
string Persona::getMensaje(int posicion){

	
}
void Persona::addMensaje(string mensaje ){
	Mensajes.push_back(mensaje);
}


Persona::Persona()
{
}
Persona::Persona(int M_llave , string M_nombre,string M_contra,string M_apellido){
	vector<string>Mensajes;
	llave=M_llave;
	nombre=M_nombre;
	contra=M_contra;
	apellido=M_apellido;
	
}

Persona::~Persona()
{
}
