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