#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>
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
    Reserva r(0,0,0,0,0);
    cout<<"Inicio de sesion"<<endl;
    cout<<"Email: ";
    cin>>correo;
    cout<<"Password: ";
    cin>>contra;
    for(list<Usuario>::iterator i = listaUsuarios_.begin(); i != listaUsuarios_.end(); ++i){
        if(correo==i->correo_){
            if(contra==i->contra_){
                r.id(i->id_);
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

void Maquina::elegirMaquina(int idUsu){
    Reserva r(0,0,0,0,0);
    int maquina, nucleos, memoria, enc=-1, fallo=-1;
    while(enc==-1 || fallo==-1){
        cout<<"\nElige una maquina: ";
        cin>>maquina;
        for (list<Maquina>::iterator i = listaMaquinas_.begin(); i != listaMaquinas_.end(); ++i){
            if(i->id_==maquina){
                enc=0;
                cout<<"Indica los nucleos que quiere reservar:"<<endl;
                cin>>nucleos;
                if(nucleos>i->nucleos_ || nucleos<0){
                    cout<<"Esta maquina no dispone de "<<nucleos<<" nucleos"<<endl;
                    fallo=-1;
                }
                else{
                    fallo=0;
                    cout<<"Indica la memoria que quiere reservar:"<<endl;
                    cin>>memoria;
                    if(memoria>i->memoria_ || memoria<0){
                        cout<<"Esta maquina no dispone de "<<memoria<<" Mb de memoria"<<endl;
                        fallo=-1;
                    }
                    else{
                        r.setM(maquina);
                        r.setN(nucleos);
                        r.setMEM(memoria);
                        i->nucleos_=i->nucleos_-nucleos;
                        i->memoria_=i->memoria_-memoria;
                    }
                }
            }
        }
        if(enc==-1){
            cout<<"La maquina elegida no existe, elige una maquina existente"<<endl;
        }
    }

}

void Reserva::cargarReservas(){
    ifstream e("reservas.txt");
    
    string id, idu, maquina, nucleos, memoria;
    int idd, iduu, maquinaa, nucleoss, memoriaa;
    while(getline(e, id,',')){
        //getline() lee del fichero de entrada y lo pone en un string
        // hasta encontrar el delimitador o el final del fichero.
        list<Reserva>::iterator it;
        it = listaReservas_.begin();
        getline(e, idu,',');
        getline(e, maquina,',');
        getline(e, nucleos,',');
        getline(e, memoria,'\n');
        idd=stoi(id);
        iduu=stoi(idu);
        maquinaa=stoi(maquina);
        nucleoss=stoi(nucleos);
        memoriaa=stoi(memoria);
        listaReservas_.push_back(Reserva(idd, iduu, maquinaa, nucleoss, memoriaa));
        it++;      
    }
    e.close();
}


void Reserva::reserva(int idRR, int idUU, int MM, int NN, int MEMM){
    string idR, idU, M, N, MEM, escribir;
    listaReservas_.push_back(Reserva(idRR, idUU, MM, NN, MEMM));

    ofstream ff("reservas.txt");
    for(list<Reserva>::iterator i = listaReservas_.begin(); i != listaReservas_.end(); ++i){
        idR=to_string(i->idR_);
        idU=to_string(i->idUsu_);
        M=to_string(i->maquina_);
        N=to_string(i->nucleo_);
        MEM=to_string(i->memoria_);

        escribir=idR+","+idU+","+M+","+N+","+MEM+"\n";
        ff.write(escribir.data(), escribir.size());
    }
    ff.close();

}
