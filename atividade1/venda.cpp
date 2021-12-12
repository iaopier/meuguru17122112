#include "venda.hpp"

#include <iostream>
#include <algorithm>
#include <regex>

void Venda::adicionaCelular(const Celular &celular) {
    m_celulares.emplace_back(celular);
}

void Venda::ordena() {
    m_celulares.sort();
}

void Venda::recarregaEstoque(int cod, int qtd) {
    for (auto &celular: m_celulares) {
        if (celular.cod == cod) {
            celular.qtd = qtd;
        }
    }
}

void Venda::efetuaVenda(int cod, int qtd) {
    for (auto &celular: m_celulares) {
        if (celular.cod == cod && celular.qtd >= qtd) {
            celular.qtd = celular.qtd - qtd;
        }
    }
}

void Venda::aplicaDesconto(const std::string &fabricante, float desconto) {
    for(auto &celular:m_celulares){
        celular.fabricante.erase(std::remove_if(celular.fabricante.begin(),celular.fabricante.end(), ::isspace),celular.fabricante.end());
        std::string fabricanteComparados;
        fabricanteComparados.assign(fabricante);
        std::remove_if(fabricanteComparados.begin(), fabricanteComparados.end(), ::isspace);
        if(celular.fabricante.compare(fabricanteComparados) == 0){
            celular.valor = celular.valor - (celular.valor*desconto/100);
        }
    }
}

void Venda::removeModelo(int cod) {
    Celular c = Celular();
    c.cod = cod;
    m_celulares.remove(c);
}

void Venda::imprimeEstoque() const {
    for(auto &celular:m_celulares){
        if(celular.qtd != 0){
            std::string restantes;
            if(celular.qtd > 1){
                restantes = "restantes";
            }else{
                restantes = "restante";
            }
            std::string fabricante = std::regex_replace(celular.fabricante, std::regex("^ +| +$|( ) +"), "$1");
            char cor[sizeof celular.cor] ={};
            celular.cor.copy(cor,sizeof celular.cor);
            cor[0] = toupper(cor[0]);
            std::cout << fabricante <<" " << celular.modelo << ","
                      << celular.armazenamento << "," << celular.memoria << ","
                      << celular.peso << "," << cor << ","
                      << celular.qtd << " " << restantes << ", R$ " << celular.valor
                      << std::endl;
        }

    }
}


