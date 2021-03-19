#ifndef PUBLICACION_H
#define PUBLICACION_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Publicacion{
	private:
		int idPublicacion;
		string titulo;
		Usuario* autor;
		string texto;
		string fechaPublicacion;
	public:
		void guardarPublicacion(ifstream*);
		Publicacion* cargarPublicacion(ifstream*);
};

#endif