#include "Veiculo.hpp"

// Sorteia o poderAtaque base (40 a 80) na lista de inicialização da base,
// depois sorteia blindagem (30 a 70) e potenciaDeFogo (20 a 50).
Veiculo::Veiculo()
    : Unidade(sorteiaValor(40, 80)),
      blindagem(sorteiaValor(30, 70)),
      potenciaDeFogo(sorteiaValor(20, 50)) {}

// Não há recursos dinâmicos para liberar
Veiculo::~Veiculo() {}

// Aplica a fórmula do veículo. O resultado fica entre 0 e 100
// (mínimo 34 e máximo 73 com as faixas dadas), usando divisão inteira.
int Veiculo::getPoderAtaque() const {
    return ((poderAtaque * 5) + (blindagem * 4) + (potenciaDeFogo * 1)) / 10;
}

// Sorteia novamente os atributos do veículo para uma nova batalha
void Veiculo::sortearAtributos() {
    poderAtaque = sorteiaValor(40, 80);
    blindagem = sorteiaValor(30, 70);
    potenciaDeFogo = sorteiaValor(20, 50);
}

// Identifica o tipo da unidade para impressão e relatórios
std::string Veiculo::getTipo() const {
    return "Veiculo";
}