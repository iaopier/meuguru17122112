#include <tuple>
#include "celular.hpp"

int Celular::id = 0;

Celular::Celular(std::string pmodelo,
                 std::string pfabricante,
                 int parmazenamento,
                 int pmemoria,
                 double ppeso,
                 std::string pcor,
                 int pqtd,
                 float pvalor){
                 modelo = pmodelo;
                 fabricante = pfabricante;
                 armazenamento = parmazenamento;
                 memoria = pmemoria;
                 peso = ppeso;
                 cor = pcor;
                 qtd = pqtd;
                 valor = pvalor;
                 cod = Celular::id + 1;
                 Celular::id = cod;
}

bool Celular::operator<(const Celular& other) {
    return std::tie(other.fabricante,other.modelo) > std::tie(this->fabricante,this->modelo);
}

bool Celular::operator==(const Celular &other) {
    if(other.cod == this->cod)
        return true;
    return false;
}
