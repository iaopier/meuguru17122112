#include <sstream>
#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
    std::ostringstream oss;
    oss << this->m_qtd << "X Hamburguer " << this->tipo << ", ";
    if(this->artesanal)
        oss << " artesanal." << std::endl;
    else
        oss << " simples." << std::endl;
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */

  return oss.str();
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
                            this->tipo = tipo;
                            this->artesanal = artesanal;
                            this->m_qtd = qtd;
                            this->m_valor_unitario = valor_unitario;
}



int Hamburguer::getQuantidade() const{
    return this->m_qtd;
}

float Hamburguer::getValorUnidade() const{
    return this->m_valor_unitario;
}
