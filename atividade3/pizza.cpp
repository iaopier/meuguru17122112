#include <sstream>
#include "pizza.hpp"

std::string Pizza::descricao() const {
    std::ostringstream oss;
    oss << this->m_qtd << "X Pizza " << this->sabor << ", " << this->pedacos << " pedacos";
    if(this->borda_recheada)
        oss << " e borda rechada." << std::endl;
    else
        oss << " sem borda rechada." << std::endl;
  return oss.str();
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
                this->sabor = sabor;
                this->pedacos = pedacos;
                this->borda_recheada = borda_recheada;
                this->m_qtd = qtd;
                this->m_valor_unitario = valor_unitario;
}

int Pizza::getQuantidade() const{
    return this->m_qtd;
}

float Pizza::getValorUnidade() const{
    return this->m_valor_unitario;
}






