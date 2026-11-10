#include "Campanha.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>

void Campanha::addExercito(std::shared_ptr<Exercito> exercito) {
    if (exercito != nullptr) {
        exercitos.push_back(std::move(exercito));
    }
}

void Campanha::simularBatalhas() {
    if (exercitos.size() < 2) {
        std::cout << "Nao existem exercitos suficientes para a batalha.\n";
        return;
    }
    int diaAtual = 1;
    int mesAtual = 1;

    // Gerar partidas de ida e volta
    for (size_t i = 0; i < exercitos.size(); ++i) {
        for (size_t j = 0; j < exercitos.size(); ++j) {
            if (i == j) continue;

            Date data(diaAtual, mesAtual, 2026);

            auto batalha = std::make_unique<Batalha>(data, exercitos[i], exercitos[j]);

            batalha->ataqueExercitoA();
            batalha->ataqueExercitoB();

            batalhas.push_back(std::move(batalha));

            diaAtual++;
            if (diaAtual > 28) {
                diaAtual = 1;
                mesAtual++;
            }
        }
    }
}

void Campanha::gerarTabelaDePosicoes(const std::string& arquivo) {
    // Ordena os exercitos por pontuação (e vitórias em caso de empate)
    std::vector<std::shared_ptr<Exercito>> tabela = exercitos;
    std::sort(tabela.begin(), tabela.end(), [](const std::shared_ptr<Exercito>& a, const std::shared_ptr<Exercito>& b) {
        if (a->getPontos() != b->getPontos()) {
            return a->getPontos() > b->getPontos();
        }
        return a->getVitorias() > b->getVitorias();
    });

    // Escolhe a saida: tela ou arquivo
    std::ofstream saida;
    if (!arquivo.empty()) {
        saida.open(arquivo);
    }
    std::ostream& out = arquivo.empty() ? std::cout : saida;

    out << "------- Tabela de Posicoes -------" << std::endl;
    int posicao = 1;
    for (const auto& e : tabela) {
        out << posicao << ". " << e->getNome() << " - " << e->getPontos()
            << " pontos - " << e->getResultados() << std::endl;
        posicao++;
    }
}

void Campanha::mostrarUnidadeMaisDestrutiva() const {
    int maxDestruicoes = -1;
    std::string melhorTipo;
    std::string nomeExercito;

    for (const auto& e : exercitos) {
        for (const auto& u : e->getUnidades()) {
            if (u->getDestruicoes() > maxDestruicoes) {
                maxDestruicoes = u->getDestruicoes();
                melhorTipo = u->getTipo();
                nomeExercito = e->getNome();
            }
        }
    }

    if (maxDestruicoes >= 0) {
        std::cout << "Unidade mais destrutiva: " << melhorTipo
                  << " do exercito " << nomeExercito << " com "
                  << maxDestruicoes << " destruicoes" << std::endl;
    }
}