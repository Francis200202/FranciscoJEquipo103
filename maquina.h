#ifndef MAQUINA_H
#define MAQUINA_H
#include <iostream>
#include <cstdio>
#include <list>
#include "reserva.h"
using namespace std;
class Maquina{
    private:
        list <Maquina> listaMaquinas_;
        int id_;
        int nucleos_;
        int memoria_;
    public:
        Maquina(int id, int nucleos, int memoria){id=id_; nucleos=nucleos_;memoria=memoria_};
        int getId(){return id_;};
        void setId(int id){id_=id;};
        int getNucleos(){return nucleos_;};
        void setNucleos(int nucleos){nucleos_=nucleos;};
        int getMemoria(return memoria_);
        void setMemoria(int memoria){memoria_=memoria;};
};

#endif