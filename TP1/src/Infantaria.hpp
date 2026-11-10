#pragma once

#include "Unidade.hpp"

#include <string>

class Infantaria : public Unidade {
private:
    int forca;       // Força da unidade (20 a 50)
    int velocidade;  // Velocidade da unidade (10 a 40)

public:
    // Construtor: sorteia poderAtaque, forca e velocidade nas faixas do enunciado
    Infantaria();

    // Destrutor (sobrescreve o destrutor virtual da base)
    ~Infantaria() override;

    // Poder de ataque final:
    // ((poderAtaque*5) + (forca*3) + (velocidade*2)) / 10
    int getPoderAtaque() const override;

    // Sorteia novamente os atributos e poder da infantaria
    void sortearAtributos() override;

    // Retorna "Infantaria"
    std::string getTipo() const override;
};