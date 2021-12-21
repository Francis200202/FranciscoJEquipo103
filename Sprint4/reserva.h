#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include "administradorUsuario.h"
#include "usuario.h"
#include "administradorMaquina.h"
#include "maquina.h"
using namespace std;
class Reserva{
    private:
        list <Reserva> listaReservas_;
        int idUsu_;
        int idR_;
        int maquina_;
        int nucleo_;
        int memoria_;
        int tiempo_;
    public:
        Reserva(int idR, int idUsu, int maquina, int nucleo, int memoria){idR_=idR;idUsu_=idUsu;maquina_=maquina;nucleo_=nucleo;memoria_=memoria;};
        int getId(){return idR_;};
        void setId(int id){idR_=id;};
        void id(int id){idUsu_=id;};
        int getidUsu(){return idUsu_;}
        void setM(int m){maquina_=m;}
        int getM(){return maquina_;};
        void setN(int n){nucleo_=n;}
        int getN(){return nucleo_;};
        void setMEM(int mem){memoria_=mem;}
        int getMEM(){return memoria_;};
        void cargarReservas();
        void reserva(int idRR, int idUU, int MM, int NN, int MEMM);
};

#endif