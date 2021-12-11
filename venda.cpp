#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <algorithm>

void Venda::adicionaCelular(const Celular &celular) {
    m_celulares.emplace_back(celular);
}

void Venda::ordena() {
    // TODO: Implemente este metodo
    // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
    // a fabricante antes do modelo do celular
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
            celular.valor = celular.valor - desconto;
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
        std::cout << celular.valor << celular.fabricante << std::endl;
    }
    // TODO: Implemente este metodo.
    /**
     * Aqui voce tera que imprimir a lista de celulares em estoque com as
     * restricoes descritas no enunciado do problema. Notem no exemplo que a
     * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
     * apenas um item em estoque de determinado modelo de celular, voce tera que
     * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
     * celulares com pelo menos um item em estoque deverao ser exibidos.
     */
}
