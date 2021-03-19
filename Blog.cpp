#include "Blog.hpp"

Blog::Blog(){
	//constructor vacio
}

Blog::Blog(string nombre){
	this->nombre=nombre;
}

Blog::~Blog(){
	//destructor
}

vector<Usuario*> Blog::getUsuarios(){
	return this->usuarios;
}

void Blog::setUsuarios(vector<Usuario*> usuarios){
	this->usuarios=usuarios;
}

void Blog::verPublicaciones(){
	
}

bool Blog::compare(Publicacion* first, Publicacion* second){
	return true;
}

void Blog::cargarArchivos(string a, string b){
	
}

void Blog::escribirUsuarios(string user){
	
}

void Blog::escrbirPublicaciones(string a){
	
}
