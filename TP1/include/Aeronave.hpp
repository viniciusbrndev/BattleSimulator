#pragma once

#include "Unidade.hpp"

#include <string>

class Aeronave : public Unidade {
private:
    int manobrabilidade;  // Agilidade da aeronave (30 a 70)
    int alcance;          // Distância de operação da aeronave (20 a 50)

public:
    // Construtor: sorteia poderAtaque, manobrabilidade e alcance nas faixas do enunciado
    Aeronave();

    // Destrutor (sobrescreve o destrutor virtual da base)
    ~Aeronave() override;

    // Poder de ataque final:
    // ((poderAtaque*5) + (manobrabilidade*3) + (alcance*2)) / 10
    int getPoderAtaque() const override;

    // Sorteia novamente os atributos e poder da aeronave
    void sortearAtributos() override;

    // Retorna "Aeronave"
    std::string getTipo() const override;
};