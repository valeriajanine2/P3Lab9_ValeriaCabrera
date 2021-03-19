#ifndef BLOG_H
#define BLOG_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Usuario.hpp"
#include "Publicacion.hpp"

using namespace std;

class Blog{
	private:
		string nombre = "YouBl0g";
		vector<Usuario*> usuarios;
	public:
		Blog();
		Blog(string);
		~Blog();
		vector<Usuario*> getUsuarios();
		void setUsuarios(vector<Usuario*>);
		void verPublicaciones();
		bool compare(Publicacion*,Publicacion*);
		void cargarArchivos(string,string);
		void escribirUsuarios(string);
		void escrbirPublicaciones(string);
};

#endif