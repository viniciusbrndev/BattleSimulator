#pragma once

#include <vector>
#include <string>

#include "Batalha.hpp"
#include "Exercito.hpp"

class Campanha {
private:
    std::vector<std::unique_ptr<Batalha>> batalhas;   // Batalhas criadas e geridas exclusivamente pela campanha
    std::vector<std::shared_ptr<Exercito>> exercitos; // Exércitos participantes da campanha

public:
    Campanha() = default;
    ~Campanha() = default;

    // Adiciona um exército participante à campanha
    void addExercito(std::shared_ptr<Exercito> exercito);

    // Simula todos os confrontos em turno e returno (ida e volta)
    void simularBatalhas();

    // Gera a tabela de classificação exibindo em tela ou salvando em arquivo se o caminho for fornecido
    void gerarTabelaDePosicoes(const std::string& nomeArquivo = "");

    // Identifica e exibe no console a unidade com o maior número de destruições
    void mostrarUnidadeMaisDestrutiva() const;
};


