#include "Exercito.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

Exercito::Exercito(const std::string &nome) {
    this->nome = nome;
    this->vitorias = 0;
    this->derrotas = 0;
    this->empates = 0;
}

void Exercito::adicionarUnidade(std::unique_ptr<Unidade> unidade) {
    if (unidade) {
        this->unidades.push_back(std::move(unidade));
    }
}

std::string Exercito::getResultados() const {
    return "Vitórias: " + std::to_string(vitorias) +
           ", Empates: " + std::to_string(empates) +
           ", Derrotas: " + std::to_string(derrotas);
}

void Exercito::imprimeUnidades() const {
    for (const auto &unit : this->unidades) {
        unit->print();
    }
}

// Getters e Setters de suporte para simulação
const std::string &Exercito::getNome() const { return this->nome; }

const std::vector<std::unique_ptr<Unidade>> &Exercito::getUnidades() const {
    return this->unidades;
}

std::vector<std::unique_ptr<Unidade>> &Exercito::getUnidades() {
    return this->unidades;
}

void Exercito::registrarVitoria() { this->vitorias++; }
void Exercito::registrarDerrota() { this->derrotas++; }
void Exercito::registrarEmpate() { this->empates++; }

int Exercito::getVitorias() const { return this->vitorias; }
int Exercito::getDerrotas() const { return this->derrotas; }
int Exercito::getEmpates() const { return this->empates; }
int Exercito::getPontos() const { return (this->vitorias * 3) + this->empates; }
