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
#include "maquina.h"
#include "reserva.h"
using namespace std;

int main(){
	Usuario s(0,"","","");
	Maquina m(0,0,0);
	int opt=0, tipoU=-1, idUsu, M, N, MEM;
	Reserva r(0,idUsu,M,N,MEM);
	s.cargarfichero();
	m.cargarMaquinas();
	r.cargarReservas();
	while(tipoU==-1){
		tipoU=s.iniciosesion();
	}
	idUsu=r.getidUsu();
	cout<<"idusu:"<<idUsu<<endl;
	
	if(tipoU==0){
		cout<<"\n__Accedido al programa como usuario__\n"<<endl;
		while(opt!=2){
		
			cout<<"1. Hacer reserva"<<endl;
			cout<<"2. Cerrar sesion"<<endl;
			cin>>opt;

			switch(opt){
				case 1:
					m.mostrarMaquinas();
					m.elegirMaquina(idUsu);
					M=r.getM();
					N=r.getN();
					MEM=r.getMEM();
					r.reserva(0,idUsu,M,N,MEM);
					//reserva
					break;
				case 2:
					cout<<"Sesion cerrada"<<endl;
					break;
				default:
					cout<<"Error, elige una opcion"<<endl;
			};
		}
	}
	if(tipoU==1){
		cout<<"\n__Accedido al programa como administrador de usuarios__\n"<<endl;
		while(opt!=3){
		
			cout<<"1. Crear usuario"<<endl;
			cout<<"2. Hacer reserva"<<endl;
			cout<<"3. Cerrar sesion"<<endl;
			cin>>opt;

			switch(opt){
				case 1:
					s.crearUsu();
					s.mostrarUsuarios();
					break;
				case 2:
					m.mostrarMaquinas();
					m.elegirMaquina(idUsu);
					M=r.getM();
					N=r.getN();
					MEM=r.getMEM();
					cout<<"memoriia:"<<MEM<<endl;
					r.reserva(0,idUsu,M,N,MEM);
					//reserva
					break;
				case 3:
					cout<<"Sesion cerrada"<<endl;
					break;
				default:
					cout<<"Error, elige una opcion"<<endl;
			};
		}
	}
	if(tipoU==2){
		cout<<"\n__Accedido al programa como administrador de maquinas__\n"<<endl;
		while(opt!=2){
		
			cout<<"1. Hacer reserva"<<endl;
			cout<<"2. Cerrar sesion"<<endl;
			cin>>opt;

			switch(opt){
				case 1:
					m.mostrarMaquinas();
					m.elegirMaquina(idUsu);
					M=r.getM();
					N=r.getN();
					MEM=r.getMEM();
					r.reserva(0,idUsu,M,N,MEM);
					//reserva
					break;
				case 2:
					cout<<"Sesion cerrada"<<endl;
					break;
				default:
					cout<<"Error, elige una opcion"<<endl;
			};
		}
	}
	
}