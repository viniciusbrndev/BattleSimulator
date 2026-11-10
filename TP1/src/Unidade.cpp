#include "Unidade.hpp"

#include <cstdlib>
#include <iostream>

// Inicializa o poder de ataque base e zera o registro de destruições
Unidade::Unidade(int poderAtaque)
    : poderAtaque(poderAtaque), destruicoes(0) {}

// Destrutor virtual (a classe base não possui recursos dinâmicos)
Unidade::~Unidade() {}

// Incrementa o contador de destruições
void Unidade::somaDestruicao() {
    destruicoes++;
}

// Retorna o contador de destruições
int Unidade::getDestruicoes() const {
    return destruicoes;
}

// Imprime informações da unidade
void Unidade::print() const {
    std::cout << getTipo() << " - Poder de Ataque: " << getPoderAtaque()
              << " - Destruicoes: " << destruicoes << std::endl;
}

// Gera um número aleatório em [minimo, maximo] usando std::rand().
int Unidade::sorteiaValor(int minimo, int maximo) {
    return minimo + (std::rand() % (maximo - minimo + 1));
}