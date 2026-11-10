#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

#include "Aeronave.hpp"
#include "Campanha.hpp"
#include "Exercito.hpp"
#include "Infantaria.hpp"
#include "Veiculo.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Adicionando exercitos
    auto e1 = std::make_shared<Exercito>("Exercito 1");
    auto e2 = std::make_shared<Exercito>("Exercito 2");
    auto e3 = std::make_shared<Exercito>("Exercito 3");

    // Exercito 1
    // preenchendo com 2 infantarias, 2 veiculos e 1 aeronave
    e1->adicionarUnidade(std::make_unique<Infantaria>());
    e1->adicionarUnidade(std::make_unique<Infantaria>());
    e1->adicionarUnidade(std::make_unique<Veiculo>());
    e1->adicionarUnidade(std::make_unique<Veiculo>());
    e1->adicionarUnidade(std::make_unique<Aeronave>());

    // Exercito 2
    // preenchendo com 2 infantarias, 2 veiculos e 1 aeronave
    e2->adicionarUnidade(std::make_unique<Infantaria>());
    e2->adicionarUnidade(std::make_unique<Infantaria>());
    e2->adicionarUnidade(std::make_unique<Veiculo>());
    e2->adicionarUnidade(std::make_unique<Veiculo>());
    e2->adicionarUnidade(std::make_unique<Aeronave>());

    // Exercito 3
    // preenchendo com 2 infantarias, 2 veiculos e 1 aeronave
    e3->adicionarUnidade(std::make_unique<Infantaria>());
    e3->adicionarUnidade(std::make_unique<Infantaria>());
    e3->adicionarUnidade(std::make_unique<Veiculo>());
    e3->adicionarUnidade(std::make_unique<Veiculo>());
    e3->adicionarUnidade(std::make_unique<Aeronave>());

    // Adicionando exercitos na campanha criada
    Campanha campanha;
    campanha.addExercito(e1);
    campanha.addExercito(e2);
    campanha.addExercito(e3);

    // Demonstrando a impressao de unidades
    std::cout << "--- Unidades do Exercito 1 ---" << std::endl;
    e1->imprimeUnidades();
    std::cout << std::endl;

    // Simular as batalhas
    campanha.simularBatalhas();

    // Exibe a tabela de posicoes na tela e salva em arquivo
    campanha.gerarTabelaDePosicoes();
    campanha.gerarTabelaDePosicoes("tabela.txt");
    std::cout << std::endl;

    // Exibe a unidade mais destrutiva
    campanha.mostrarUnidadeMaisDestrutiva();

    return 0;
}

