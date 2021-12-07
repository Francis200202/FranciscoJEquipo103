#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <string>
#include <fstream>
#include "sistema.h"
#include "administradorUsuario.h"
#include "usuario.h"
#include "administradorMaquina.h"
using namespace std;

int main(){
	Usuario s(0,"","","");
	s.cargarfichero();
	int opt;
	while(opt!=2){
		
		cout<<"1. Crear usuario"<<endl;
		cout<<"2. Salir del programa"<<endl;
		cin>>opt;

		switch(opt){
			case 1:
				s.crearUsu();
				s.mostrarUsuarios();
				break;
			case 2:
				//sale del programa
				break;
			default:
				cout<<"Cerrando programa"<<endl;
		};
	}
}