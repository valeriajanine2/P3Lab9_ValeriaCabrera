#include "Usuario.hpp"

Usuario::Usuario(){
	//constructor vacio
}

Usuario::Usuario(int id, string username, string contrasena, bool esAdmin){
	this->id=id;
	this->username=username;
	this->contrasena=contrasena;
	this->esAdmin=esAdmin;
}

Usuario::~Usuario(){
	//destructor
	/*for(int i = 0; i < this->publicaciones.size(); i++){
		delete this->publicaciones.at(i);
	}*/
	
}

int Usuario::getID(){
	return this->id;
}

void Usuario::setID(int id){
	this->id=id;
}

string Usuario::getUser(){
	return this->username;
}

void Usuario::setUser(string username){
	this->username=username;
}

string Usuario::getPass(){
	return this->contrasena;
}

void Usuario::setPass(string contrasena){
	this->contrasena=contrasena;
}

bool Usuario::getAdmin(){
	return this->esAdmin;
}

void Usuario::setAdmin(bool esAdmin){
	this->esAdmin=esAdmin;
}

vector<Publicacion*> Usuario::getPublicaciones(){
	return this->publicaciones;
}

void Usuario::setPublicaciones(vector<Publicacion*> publicaciones){
	this->publicaciones=publicaciones;
}

void Usuario::guardarUsuario(ofstream* escribir){
	Usuario* u = new Usuario(this->id,this->username,this->contrasena,this->esAdmin);
	escribir->write((char *) &u, sizeof(Usuario*));
}

Usuario* Usuario::cargarUsuario(ifstream* leer){
	Usuario* u = new Usuario();
	leer->read((char * ) &u, sizeof(Usuario*));
	return u;
}

void Usuario::agregarPublicacion(Publicacion* p){
	this->publicaciones.push_back(p);
}

void Usuario::eliminar(int index){
	this->publicaciones.erase(this->publicaciones.begin() + index);
}
