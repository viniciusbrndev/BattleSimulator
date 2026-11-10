#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Unidade.hpp"

class Exercito {
  private:
    std::string nome;                              // Nome de identificação do exército
    std::vector<std::unique_ptr<Unidade>> unidades; // Coleção de unidades com posse exclusiva (smart pointers)
    int vitorias;                                  // Total de vitórias obtidas
    int derrotas;                                  // Total de derrotas sofridas
    int empates;                                   // Total de empates ocorridos

  public:
    // Construtor: inicializa o exército com o nome especificado e zera o histórico
    explicit Exercito(const std::string &nome = "Exercito");
    
    // Destrutor padrão: unique_ptr cuida automaticamente da desalocação das unidades
    ~Exercito() = default;

    // Adiciona uma nova unidade ao exército transferindo sua posse
    void adicionarUnidade(std::unique_ptr<Unidade> unidade);

    // Retorna string formatada com o histórico de resultados: Vitórias: X, Empates: Y, Derrotas: Z
    std::string getResultados() const;

    // Imprime todas as unidades pertencentes ao exército
    void imprimeUnidades() const;

    // Retorna o nome do exército
    const std::string &getNome() const;

    // Retorna a lista de unidades (versão somente leitura)
    const std::vector<std::unique_ptr<Unidade>> &getUnidades() const;

    // Retorna a lista de unidades (versão modificável para sorteio de poderes)
    std::vector<std::unique_ptr<Unidade>> &getUnidades();

    // Incrementa o número de vitórias
    void registrarVitoria();

    // Incrementa o número de derrotas
    void registrarDerrota();

    // Incrementa o número de empates
    void registrarEmpate();

    // Retorna a quantidade de vitórias
    int getVitorias() const;

    // Retorna a quantidade de derrotas
    int getDerrotas() const;

    // Retorna a quantidade de empates
    int getEmpates() const;

    // Retorna a pontuação total (Vitória = 3 pts, Empate = 1 pt, Derrota = 0 pts)
    int getPontos() const;
};
