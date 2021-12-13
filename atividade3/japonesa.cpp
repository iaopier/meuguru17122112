#include <sstream>
#include "japonesa.hpp"

std::string Japonesa::descricao() const {
    std::ostringstream oss;
    oss << this->m_qtd << "X Comida Japonesa - "
    << this->combinado << ", "
    << this->sushis << " sushis, "
    << this->temakis << " temakis, "
    << this->hots << " hots." << std::endl;
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */

  return oss.str();
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
                        this->combinado = combinado;
                        this->sushis = sushis;
                        this->temakis = temakis;
                        this->hots = hots;
                        this->m_qtd = qtd;
                        this->m_valor_unitario = valor_unitario;
}

int Japonesa::getQuantidade() const{
    return this->m_qtd;
}

float Japonesa::getValorUnidade() const{
    return this->m_valor_unitario;
}