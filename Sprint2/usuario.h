#ifndef USUARIO_H
#define USUARIO_H
#include <cstdio>
#include <string>
#include <vector>
#include "administradorUsuario.h"
using namespace std;

class Usuario{
    private:
        string nombre_;
        int id_;
        string correo_;
        string contra_;
        int limiteTiempo_;
        list <Usuario> listaUsuarios_;
        vector<int>limiteRecursos_;
        int tipoUsu_;
    public:
        Usuario(int id,string nombre,string correo, string contra){id_=id;nombre_=nombre;correo_=correo;contra_=contra;tipoUsu_=0;};
        string getNombre(){return nombre_;};
        void setNombre(string nombre){nombre_=nombre;};
        int getId(){return id_;};
        void setId(int id){id_=id;};
        string getCorreo(){return correo_;};
        void setCorreo(string correo){correo_=correo;};
        int getLimiteTiempo(){return limiteTiempo_;};
        vector<int> getLimiteRecursos(){return limiteRecursos_;};
        int getTipoUsu(){return tipoUsu_;};
        void setTipoUsu(int tipo){tipoUsu_=tipo;};
        void mostrarUsuarios();
        void cargarfichero();
        void crearUsu();
        int comprueba_correo(string correo);
};
#endif