#include "Batalha.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

#include "Date.hpp"
#include "Exercito.hpp"

Batalha::Batalha(const Date &data, std::shared_ptr<Exercito> exercitoA, std::shared_ptr<Exercito> exercitoB)
    : data(data), exercitoA(std::move(exercitoA)), exercitoB(std::move(exercitoB)), resultadoA(0), resultadoB(0) {
    if (!this->exercitoA || !this->exercitoB) {
        throw std::invalid_argument("NÃO FOI POSSÍVEL INICIAR A BATALHA");
    }
}

void Batalha::ataqueExercitoA() {
    resultadoA = 0;
    for (auto &unidade : this->exercitoA->getUnidades()) {
        unidade->sortearAtributos();
        resultadoA += unidade->getPoderAtaque();
    }
}

void Batalha::ataqueExercitoB() {
    resultadoB = 0;
    for (auto &unidade : this->exercitoB->getUnidades()) {
        unidade->sortearAtributos();
        resultadoB += unidade->getPoderAtaque();
    }
    determinarVencedor();
}

void Batalha::determinarVencedor() {
    if (resultadoA > resultadoB) {
        exercitoA->registrarVitoria();
        exercitoB->registrarDerrota();
    } else if (resultadoB > resultadoA) {
        exercitoB->registrarVitoria();
        exercitoA->registrarDerrota();
    } else {
        exercitoA->registrarEmpate();
        exercitoB->registrarEmpate();
    }

    size_t minUnits = std::min(exercitoA->getUnidades().size(), exercitoB->getUnidades().size());
    for (size_t k = 0; k < minUnits; ++k) {
        int poderA = exercitoA->getUnidades()[k]->getPoderAtaque();
        int poderB = exercitoB->getUnidades()[k]->getPoderAtaque();
        if (poderA > poderB) {
            exercitoA->getUnidades()[k]->somaDestruicao();
        } else if (poderB > poderA) {
            exercitoB->getUnidades()[k]->somaDestruicao();
        }
    }
}

std::string Batalha::getResultado() const {
    return this->exercitoA->getNome() + " " +
           std::to_string(this->resultadoA) + " x " +
           std::to_string(this->resultadoB) + " " +
           this->exercitoB->getNome();
}
