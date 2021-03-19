#ifndef PUBLICACION_H
#define PUBLICACION_H
#include <iostream>
#include <string>
#include <fstream>
#include "Usuario.hpp"

using namespace std;

class Publicacion{
	private:
		int idPublicacion;
		string titulo;
		Usuario* autor;
		string texto;
		string fechaPublicacion;
	public:
		Publicacion();
		Publicacion(int,string,Usuario*,string,string);
		~Publicacion();
		void guardarPublicacion(ofstream*);
		Publicacion* cargarPublicacion(ifstream*);
};
#endif