#ifndef PERSONA_H
#define PERSONA_H
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Persona
{
	public:
		Persona();
		Persona(int,string,string,string);
		
		void setNombre(string );
		void setContra(string );
		void setLlave(int );
		void setApellido(string );
		int getLlave();
		string getNombre();
		string getContra();
		string getMensaje(int);
		
		void addMensaje(string );
		
	
		
		~Persona();
	protected:
	private :
		int llave;
		string nombre;
		string apellido;
		string contra;
		vector<string>Mensajes;
};

#endif
