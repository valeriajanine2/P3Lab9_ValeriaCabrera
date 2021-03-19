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

void Usuario::guardarUsuario(ofstream* s){
	
}

Usuario* Usuario::cargarUsuario(ifstream* i){
	
}
