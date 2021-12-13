#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include <cstdio>
#include <list>
#include "administradorUsuario.h"
#include "usuario.h"
#include "administradorMaquina.h"
#include "maquina.h"
using namespace std;
class Reserva{
    private:
        list <Reserva> listaReservas_;
        int idR_;
        Maquina maquina_;
        vector<int> Recursos_;
        Usuario usuario_;
        int tiempo_;
    public:
        Reserva(int idR, Maquina maquina, vector<int> Recursos, Usuario usuario);
        int getId(){return idR_;};
        void setId(int id){idR_=id;};
        vector<int> getRecursos(){return Recursos_;};
        void setRecursos(vector<int> Recursos){Recursos_=Recursos;};
        Usuario getUsuario(){return usuario_;};
        void setUsuario(Usuario usuario){usuario_=usuario;};
};

#endif