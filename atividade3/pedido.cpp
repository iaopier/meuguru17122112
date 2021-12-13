#include <sstream>
#include <cstring>
#include "pedido.hpp"

Pedido::~Pedido() {

    for(auto produto : m_produtos) {
        delete produto;
    }
}

void Pedido::setEndereco(const std::string &endereco) {
    this->m_endereco = endereco;

}

float Pedido::calculaTotal() const {
    double total = 0.0;
    for (auto produto: this->m_produtos) {
        if(std::strcmp(typeid(*produto).name(),typeid(Pizza).name()) == 0){
            Pizza* p = dynamic_cast<Pizza*>(produto);
            total = total + p->getValorUnidade() * p->getQuantidade();
        }else if(std::strcmp(typeid(*produto).name(),typeid(Hamburguer).name()) == 0){
            Hamburguer* j = dynamic_cast<Hamburguer*>(produto);
            total = total + j->getValorUnidade() * j->getQuantidade();
        }else if(std::strcmp(typeid(*produto).name(),typeid(Japonesa).name()) == 0){
            Japonesa* j = dynamic_cast<Japonesa*>(produto);
            total = total + j->getValorUnidade() * j->getQuantidade();
        }
    }

    return total;
}

void Pedido::adicionaProduto(Produto *p) {
    this->m_produtos.emplace_back(p);

}

std::string Pedido::resumo() const {
    std::ostringstream oss;
    for (auto produto: m_produtos) {
        oss << produto->descricao();
    }
    oss << "Endereco: " << this->m_endereco << std::endl;
    return oss.str();
}