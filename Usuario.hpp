#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//#include "Publicacion.hpp"

using namespace std;

class Publicacion;

class Usuario{
	private:
		int id;
		string username;
		string contrasena;
		bool esAdmin;
		vector<Publicacion*> publicaciones;
	public:
		Usuario();
		Usuario(int,string,string,bool);
		~Usuario();
		int getID();
		void setID(int);
		string getUser();
		void setUser(string);
		string getPass();
		void setPass(string);
		bool getAdmin();
		void setAdmin(bool);
		vector<Publicacion*> getPublicaciones();
		void setPublicaciones(vector<Publicacion*>);
		void guardarUsuario(ofstream*);
		Usuario* cargarUsuario(ifstream*);
		void agregarPublicacion(Publicacion*);
		void eliminar(int);
};

#endif