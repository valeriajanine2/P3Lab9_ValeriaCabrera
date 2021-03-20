#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Blog.hpp"
#include "Publicacion.hpp"
#include "Usuario.hpp"

using namespace std;

void imprimirPublicaciones(vector<Publicacion*> lista) {
	for(int i = 0; i < lista.size(); i ++) {
		Publicacion* p = new Publicacion();
		p = lista.at(i);
		Usuario* u = new Usuario();
		u = p->getAutor();
		cout<<i<<") Titulo: "<<p->getTitulo()<<"Autor: "<<u->getUser()<<endl;
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	//contador para el id
	int cont=1;

	Blog* blog = new Blog();
	ifstream* leer = new ifstream("archivo_users.us",ios::binary | ios::in);
	ofstream* escribir;
	//verificar si esta vacio y si no esta se va a crear el archivo
	leer->seekg(0,ios::end);
	if(leer->tellg()==0) {
		leer->close();
	} else {
		leer->close();
		escribir = new ofstream("archivo_users.us",ios::binary | ios::out);
		Usuario* admin = new Usuario(0,"admin","1111",true);
		admin->guardarUsuario(escribir);
		blog->agregarUsuario(admin);
	}

	leer->open("archivo_users.us", ios::binary | ios::in);
	//hacer lo del login
	if(escribir->is_open()) {
		int salir=0;
		while(salir!=2) {

			cout<<"\n1) Log in\n2) Salir"<<endl;
			cout<<"Ingrese la opcion que desea realizar: ";
			cin>>salir;

			if(salir==1) {

				string user, pass;
				cout<<"Bienvenido al blog\nIngrese su username: "<<endl;
				cin>>user;
				cout<<"Ingrese la contrasena: ";
				cin>>pass;

				if(user=="admin" && pass=="1111") {

					//menu del admin
					int adminMenu = 0;
					while(adminMenu!=5) {

						cout<<"1) Agregar Usuario\n2) Eliminar Usuario\n3) Actualizar Contrasena\n4) Ver Publicaciones\n5) Cerrar Sesion\n";
						cout<<"Ingrese la opcion del menu que desea realizar: ";
						cin>>adminMenu;

						switch(adminMenu) {
							case 1: {
								//agregar usuario

								string username, contra;

								cont++;
								cout<<"Ingrese el username: ";
								cin>>username;
								cout<<"Ingrese la contrasena: ";
								cin>>contra;

								Usuario* usuario = new Usuario(cont,username,contra,false);

								blog->agregarUsuario(usuario);


								break;
							}

							case 2: {
								//eliminar usuario
								for(int i = 0; i < blog->getUsuarios().size(); i++) {
									Usuario* u = new Usuario();
									u = blog->getUsuarios().at(i);
									cout<<i<<") "<<"Username: "<<u->getUser()<<" Password: "<<u->getPass()<<endl;
								}

								int index;
								cout<<"Ingrese el indice del usuario que desea eliminar: ";
								cin>>index;

								while(index>blog->getUsuarios().size() || index < 0) {
									cout<<"No hay un usuario con ese indice";
									cout<<"Ingrese el indice del usuario que desea eliminar: ";
									cin>>index;
								}

								blog->eliminarUser(index);

								break;
							}

							case 3: {
								//actualizar contrasena

								string contra;
								Usuario* a = new Usuario();
								a = blog->getUsuarios().at(0);
								cout<<"Ingrese la nueva contrasena: ";
								cin>>contra;

								a->setPass(contra);

								break;
							}

							case 4: {
								//ver publicaciones
								for(int i = 0; i < blog->getUsuarios().size(); i++) {
									Usuario* u = new Usuario();
									u = blog->getUsuarios().at(i);
									imprimirPublicaciones(u->getPublicaciones());
								}

								break;
							}

							case 5: {
								//cerrar sesion

								cout<<"Adios admin";
								user=="";
								pass="";

								break;
							}

						}//fin del switch del menu del admin

					}//fin del while del menu de admin


				} else {

					bool existe = false;
					Usuario* temp = new Usuario();
					//validar si no es admin
					for(int i = 0; i < blog->getUsuarios().size(); i++) {
						Usuario* us = new Usuario();
						us = blog->getUsuarios().at(i);
						if(us->getUser()==user && us->getPass()==pass) {
							existe=true;
							temp = us;
						}
					}

					if(existe) {
						//menu del user
						int userMenu=0;
						while(userMenu!=5) {
							cout<<"1) Ver Publicaciones\n2) Mis Publicaciones\n3) Actualizar Contrasena\n4) Cerrar Sesion"<<endl;
							cout<<"Ingrese el numero de la opcion que desea: ";
							cin>>userMenu;

							switch(userMenu) {
								case 1: {

									//ver publicaciones

									imprimirPublicaciones(temp->getPublicaciones());

									break;
								}

								case 2: {

									//mis publicaciones

									char menu;
									cout<<"a) Agregar Publicacion\nb) Modificar Publicacion\nc) Eliminar Publicacion"<<endl;
									cout<<"Ingrese la opcion que desea realizar: ";
									cin>>menu;
									
									switch(menu) {

										case 'a': {
											//Agregar Publicacion
											const int tam = 2000;
											char texto[tam];
											int id;
											string titulo, fecha;

											cout<<"Ingrese el id de Publicacion: ";
											cin>>id;
											cout<<"Ingrese el titulo: ";
											cin>>titulo;
											cout<<"Escriba su publicacion: ";
											cin.getline(texto,tam);
											cout<<"Ingrese la fecha de publicacion: ";
											cin>>fecha;

											Publicacion* publi = new Publicacion(id,titulo,temp,texto,fecha);

											temp->agregarPublicacion(publi);

											break;
										}

										case 'b': {
											//Modificar Publicacion

											imprimirPublicaciones(temp->getPublicaciones());
											int index;
											cout<<"Ingrese el indice de la publicacion que desea modificar: ";
											cin>>index;

											while(index>temp->getPublicaciones().size() || index<0) {
												cout<<"No existe el indice que ha ingresado"<<endl;
												cout<<"Ingrese el indice de la publicacion que desea modificar: ";
												cin>>index;
											}

											Publicacion* p = new Publicacion();
											p = temp->getPublicaciones().at(index);

											const int tam = 2000;
											char texto[tam];
											int id;
											string titulo, fecha;

											cout<<"Ingrese el nuevo id de Publicacion: ";
											cin>>id;
											cout<<"Ingrese el nuevo titulo: ";
											cin>>titulo;
											cout<<"Escriba su nueva publicacion: ";
											cin.getline(texto,tam);
											cout<<"Ingrese la nueva fecha de publicacion: ";
											cin>>fecha;

											p->setID(id);
											p->setTitulo(titulo);
											p->setTexto(texto);
											p->setFecha(fecha);

											break;
										}

										case 'c': {
											//Eliminar Publicacion

											imprimirPublicaciones(temp->getPublicaciones());

											int index;
											cout<<"Ingrese el indice de la publicacion que desea eliminar: ";
											cin>>index;

											while(index>blog->getUsuarios().size() || index < 0) {
												cout<<"No hay una publicacion con ese indice";
												cout<<"Ingrese el indice de la publicacion que desea eliminar: ";
												cin>>index;
											}

											blog->eliminarUser(index);

											break;
										}

										default: {
											cout<<"La letra que ingreso no es una opcion del menu "<<endl;
											break;
										}

									}//fin del switch del menu secundario de user

									break;
								}

								case 3: {

									//Actualizar Contrasena

									string contra;
									cout<<"Ingrese la nueva contrasena: ";
									cin>>contra;

									temp->setPass(contra);

									break;
								}

								case 4: {

									//Cerrar Sesion
									cout<<"Adios "<<temp->getUser();
									user="";
									pass="";
									userMenu=5;

									break;
								}

								default: {
									cout<<"asegurese de ingresar una de las opciones del menu"<<endl;
									break;
								}
							}//fin del switch del menu
						}//fin del while del menu del user


					} else {

						cout<<"No hay ningun usuario con esas credenciales, consulte al admin"<<endl;

					}//fin del if de cualquier otro usuario

				}//fin del if del login del admin
			}//fin de la opcion del login
		}//fin del while principal


	} else {

	}//fin del is open
	escribir->close();
	delete blog;
	return 0;
}