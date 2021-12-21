#ifndef MAQUINA_H
#define MAQUINA_H
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;
class Maquina{
    private:
        list <Maquina> listaMaquinas_;
        int id_;
        int nucleos_;
        int memoria_;
    public:
        friend class Reserva;
        Maquina(int id, int nucleos, int memoria){id_=id; nucleos_=nucleos;memoria_=memoria;};
        int getId(){return id_;};
        void setId(int id){id_=id;};
        int getNucleos(){return nucleos_;};
        void setNucleos(int nucleos){nucleos_=nucleos;};
        int getMemoria(){return memoria_;};
        void setMemoria(int memoria){memoria_=memoria;};
        void cargarMaquinas();
        void mostrarMaquinas();
        void elegirMaquina(int idUsu);
};

#endif