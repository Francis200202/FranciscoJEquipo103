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

void Usuario::mostrarUsuarios(){
	for (list<Usuario>::iterator i = listaUsuarios_.begin(); i != listaUsuarios_.end(); ++i)
   {
      cout<<"Id: "<<i->id_<<"  Nombre: "<<i->nombre_<<"  Correo: "<<i->correo_;
        
      if(i->getTipoUsu()==0){
      	cout<<" ->Usuario"<<endl;
      }
      if(i->getTipoUsu()==1){
      	cout<<" ->Administrador de usuarios"<<endl;
      }
      if(i->getTipoUsu()==2){
      	cout<<" ->Administrador de maquinas"<<endl;
      }
   }
}

void Usuario::cargarfichero(){
    
    ifstream entrada("listaU.txt");
    //Usuario aux;
    
    string id, nombre, contra, correo, tipo;
    int idd, tipoU;
    while(getline(entrada, id,',')){
        //getline() lee del fichero de entrada y lo pone en un string
        // hasta encontrar el delimitador o el final del fichero.
        list<Usuario>::iterator it;
        it = listaUsuarios_.begin();
        getline(entrada, nombre,',');
        getline(entrada, correo,',');
        getline(entrada, contra,',');
        getline(entrada, tipo,'\n');
        idd=stoi(id);
        tipoU=stoi(tipo);
        if(tipoU==0){
            listaUsuarios_.push_back(Usuario(idd, nombre, correo, contra));
            it++;   
        }
        if(tipoU==1){
            listaUsuarios_.push_back(AdministradorUsuario(idd, nombre, correo, contra));
            it++;   
        }
        if(tipoU==2){
            listaUsuarios_.push_back(AdministradorMaquina(idd, nombre, correo, contra));
            it++;   
        }
        
    }
    entrada.close();
}

void Usuario::crearUsu(){
    int id=0, tipoU, comprueba=0;
    string nombre, contra, correo, escribir, idd, tipo;
    cout<<"Introduce los datos del nuevo usuario"<<endl;
    cout<<"Elige el tipo de usuario: \n0.Usuario\n1.Administrador de usuarios\n2.Administrador de maquinas"<<endl;
    cin>>tipoU;
    cout<<"Nombre-> ";
    cin>>nombre;
    while(comprueba==0){
        cout<<"Correo electronico-> ";
        cin>>correo;
        comprueba=comprueba_correo(correo);
        if(comprueba==0){
            cout<<"Este correo ya esta registrado"<<endl;
        }
    }
    cout<<"Contraseña-> ";
    cin>>contra;
    list<Usuario>::iterator ir = listaUsuarios_.end();
    ir--;
    id=ir->id_+1;

    if(tipoU==0){
        setTipoUsu(tipoU);
        listaUsuarios_.push_back(Usuario(id, nombre, correo, contra));  
    }
    if(tipoU==1){
        setTipoUsu(tipoU);
        listaUsuarios_.push_back(AdministradorUsuario(id, nombre, correo, contra));  
    }
    if(tipoU==2){
        setTipoUsu(tipoU);
        listaUsuarios_.push_back(AdministradorMaquina(id, nombre, correo, contra));  
    }

    ofstream f("listaU.txt");
    for(list<Usuario>::iterator i = listaUsuarios_.begin(); i != listaUsuarios_.end(); ++i){
        idd=to_string(i->id_);
        tipo=to_string(i->tipoUsu_);
        escribir=idd+","+i->nombre_+","+i->correo_+","+i->contra_+","+tipo+"\n";
        f.write(escribir.data(), escribir.size());
    }
    f.close();
}

int Usuario::comprueba_correo(string correo){
    for(list<Usuario>::iterator i = listaUsuarios_.begin(); i != listaUsuarios_.end(); ++i){
        if(correo==i->correo_){
            return 0;
        }
    }
    return 1;
}

int Usuario::iniciosesion(){

    string correo, contra;

    cout<<"Inicio de sesion"<<endl;
    cout<<"Email: ";
    cin>>correo;
    cout<<"Password: ";
    cin>>contra;
    for(list<Usuario>::iterator i = listaUsuarios_.begin(); i != listaUsuarios_.end(); ++i){
        if(correo==i->correo_){
            if(contra==i->contra_){
                return i->tipoUsu_;
            }
            else{
                cout<<"Incorrect password"<<endl;
                return -1;
            }
        }
    }
    cout<<"Email no registrado"<<endl;
    return -1;
}

void Maquina::cargarMaquinas(){
    ifstream entr("maquina.txt");
    
    string id, nucleos, memoria;
    int idd, nucleoss, memoriaa;
    while(getline(entr, id,',')){
        //getline() lee del fichero de entrada y lo pone en un string
        // hasta encontrar el delimitador o el final del fichero.
        list<Maquina>::iterator it;
        it = listaMaquinas_.begin();
        getline(entr, nucleos,',');
        getline(entr, memoria,'\n');
        idd=stoi(id);
        nucleoss=stoi(nucleos);
        memoriaa=stoi(memoria);
        listaMaquinas_.push_back(Maquina(idd, nucleoss, memoriaa));
        it++;      
    }
    entr.close();
}


void Maquina::mostrarMaquinas(){
    for (list<Maquina>::iterator i = listaMaquinas_.begin(); i != listaMaquinas_.end(); ++i)
    {
        cout<<"__Maquina "<<i->getId()<<"__"<<endl;
        cout<<"Nucleos: "<<i->nucleos_<<"  Memoria: "<<i->memoria_<<endl;
    }
    cout<<endl;
}
