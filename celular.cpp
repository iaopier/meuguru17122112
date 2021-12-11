#include "celular.hpp"

// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.

Celular::Celular(std::string pmodelo,
                 std::string pfabricante,
                 int parmazenamento,
                 int pmemoria,
                 double ppeso,
                 std::string pcor,
                 int pqtd,
                 float pvalor){
                 this->modelo = pmodelo;
                 fabricante = pfabricante;
                 armazenamento = parmazenamento;
                 memoria = pmemoria;
                 peso = ppeso;
                 cor = pcor;
                 qtd = pqtd;
                 valor = pvalor;
}

bool Celular::operator<(const Celular& other) {
  // TODO: Implemente este metodo.
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular

  return false;
}
