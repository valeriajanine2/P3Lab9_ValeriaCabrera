#include "Publicacion.hpp"

Publicacion::Publicacion(){
	//constructor vacio
}

Publicacion::Publicacion(int idPublicacion, string titulo, Usuario* autor, string texto, string fechaPublicacion){
	this->idPublicacion=idPublicacion;
	this->titulo=titulo;
	this->autor=autor;
	this->texto=texto;
	this->fechaPublicacion=fechaPublicacion;
}

Publicacion::~Publicacion(){
	//destructor
}

void Publicacion::guardarPublicacion(ofstream* o){
	
}

Publicacion* Publicacion::cargarPublicacion(ifstream* i){
	
}

Usuario* Publicacion::getAutor(){
	return this->autor;
}

string Publicacion::getTitulo(){
	return this->titulo;
}

void Publicacion::setFecha(string fechaPublicacion){
	this->fechaPublicacion=fechaPublicacion;
}

void Publicacion::setID(int idPublicacion){
	this->idPublicacion=idPublicacion;
}

void Publicacion::setTexto(string texto){
	this->texto=texto;
}

void Publicacion::setTitulo(string titulo){
	this->titulo=titulo;
}
