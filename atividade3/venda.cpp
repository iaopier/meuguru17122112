#include "venda.hpp"
#include <iomanip>
#include <iostream>
Venda::~Venda() {
    for(auto pedido: m_pedidos){
        delete(pedido);
    }

}

void Venda::adicionaPedido(Pedido* p) {
    m_pedidos.emplace_back(p);

}

void Venda::imprimeRelatorio() const {
    int contador = 0;
    double total = 0.0;
    for(auto pedido : this->m_pedidos){
        std::cout << "Pedido " << contador + 1 << std::endl;
        std::cout << pedido->resumo();
        contador++;
        total = total + pedido->calculaTotal();
    }
    std::cout << "Relatorio de vendas" << std::endl;
    std::cout << "Total de Vendas: R$ " << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << "Total de Pedidos: " << contador;

}