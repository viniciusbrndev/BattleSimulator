#pragma once

#include "Unidade.hpp"

#include <string>

class Veiculo : public Unidade {
private:
    int blindagem;       // Resistência do veículo (30 a 70)
    int potenciaDeFogo;  // Capacidade de fogo do veículo (20 a 50)

public:
    // Construtor: sorteia poderAtaque, blindagem e potenciaDeFogo nas faixas do enunciado
    Veiculo();

    // Destrutor (sobrescreve o destrutor virtual da base)
    ~Veiculo() override;

    // Poder de ataque final:
    // ((poderAtaque*5) + (blindagem*4) + (potenciaDeFogo*1)) / 10
    int getPoderAtaque() const override;

    // Sorteia novamente os atributos e poder do veículo
    void sortearAtributos() override;

    // Retorna "Veiculo"
    std::string getTipo() const override;
};