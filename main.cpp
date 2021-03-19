#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Blog.hpp"
#include "Publicacion.hpp"
#include "Usuario.hpp"

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Blog* blog = new Blog();
	ifstream* if_users = new ifstream("archivo_users.us",ios::binary | ios::in);
	
	//verificar si esta vacio y si no esta se va a crear el archivo
	if_users->seekg(0,ios::end);
	if(if_users->tellg()==0){
		if_users->close();
	}else{
		if_users->close();
		ofstream* of_users = new ofstream("archivo_users.us",ios::binary | ios::out);
		Usuario* user = new Usuario(0,"admin","1111",true);
		of_users->write((char *) &user, sizeof(user));
		
	}
	
	//hacer lo del login
	if()
	return 0;
}