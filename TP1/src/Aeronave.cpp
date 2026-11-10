#include "Aeronave.hpp"

// Sorteia o poderAtaque base (50 a 90) na lista de inicialização da base,
// depois sorteia manobrabilidade (30 a 70) e alcance (20 a 50).
Aeronave::Aeronave()
    : Unidade(sorteiaValor(50, 90)),
      manobrabilidade(sorteiaValor(30, 70)),
      alcance(sorteiaValor(20, 50)) {}

// Não há recursos dinâmicos para liberar
Aeronave::~Aeronave() {}

// Aplica a fórmula da aeronave. O resultado fica entre 0 e 100
// (mínimo 38 e máximo 76 com as faixas dadas), usando divisão inteira.
int Aeronave::getPoderAtaque() const {
    return ((poderAtaque * 5) + (manobrabilidade * 3) + (alcance * 2)) / 10;
}

// Sorteia novamente os atributos da aeronave para uma nova batalha
void Aeronave::sortearAtributos() {
    poderAtaque = sorteiaValor(50, 90);
    manobrabilidade = sorteiaValor(30, 70);
    alcance = sorteiaValor(20, 50);
}

// Identifica o tipo da unidade para impressão e relatórios
std::string Aeronave::getTipo() const {
    return "Aeronave";
}