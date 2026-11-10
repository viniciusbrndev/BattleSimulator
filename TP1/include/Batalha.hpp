#pragma once

#include <memory>
#include <string>

#include "Date.hpp"
#include "Exercito.hpp"

class Batalha {
  private:
    Date data;                            // Data em que a batalha ocorre
    std::shared_ptr<Exercito> exercitoA;  // Ponteiro compartilhado para o exército A
    std::shared_ptr<Exercito> exercitoB;  // Ponteiro compartilhado para o exército B
    int resultadoA;                       // Soma dos poderes de ataque das unidades de A
    int resultadoB;                       // Soma dos poderes de ataque das unidades de B

  public:
    // Construtor: recebe a data do confronto e os dois exércitos participantes
    Batalha(const Date &data, std::shared_ptr<Exercito> exercitoA, std::shared_ptr<Exercito> exercitoB);
    ~Batalha() = default;

    // Simula o ataque do exército A, sorteando os poderes das unidades e calculando resultadoA
    void ataqueExercitoA();

    // Simula o ataque do exército B, sorteando os poderes das unidades e calculando resultadoB
    void ataqueExercitoB();

    // Determina o vencedor da batalha e atualiza o histórico e destruições
    void determinarVencedor();

    // Retorna string no formato: Nome do Exército A 0 x 0 Nome do Exército B
    std::string getResultado() const;
};
