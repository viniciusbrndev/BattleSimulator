#include "Infantaria.hpp"

// Sorteia o poderAtaque base (30 a 60) na lista de inicialização da base,
// depois sorteia forca (20 a 50) e velocidade (10 a 40).
Infantaria::Infantaria()
    : Unidade(sorteiaValor(30, 60)),
      forca(sorteiaValor(20, 50)),
      velocidade(sorteiaValor(10, 40)) {}

// Não há recursos dinâmicos para liberar
Infantaria::~Infantaria() {}

// Aplica a fórmula da infantaria. O resultado fica entre 0 e 100
// (mínimo 23 e máximo 53 com as faixas dadas), usando divisão inteira.
int Infantaria::getPoderAtaque() const {
    return ((poderAtaque * 5) + (forca * 3) + (velocidade * 2)) / 10;
}

// Sorteia novamente os atributos de infantaria para uma nova batalha
void Infantaria::sortearAtributos() {
    poderAtaque = sorteiaValor(30, 60);
    forca = sorteiaValor(20, 50);
    velocidade = sorteiaValor(10, 40);
}

// Identifica o tipo da unidade para impressão e relatórios
std::string Infantaria::getTipo() const {
    return "Infantaria";
}