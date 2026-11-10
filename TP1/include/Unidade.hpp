#pragma once

#include <string>

// Classe abstrata que representa uma unidade militar genérica.
// Classe base para Infantaria, Veiculo e Aeronave.
class Unidade {
protected:
    // Poder de ataque base (sorteado pela subclasse)
    int poderAtaque;

    // Sorteia um inteiro aleatório no intervalo [minimo, maximo].
    static int sorteiaValor(int minimo, int maximo);

private:
    int destruicoes;  // Quantidade de oponentes destruídos em batalha

public:
    // Construtor: recebe o poder de ataque base e zera as destruições
    explicit Unidade(int poderAtaque);

    // Destrutor virtual: necessario para destruir objetos derivados
    // corretamente através de ponteiros Unidade*
    virtual ~Unidade();

    // Retorna o poder de ataque final (0 a 100).
    // Virtual puro: cada subclasse aplica sua própria fórmula.
    virtual int getPoderAtaque() const = 0;

    // Sorteia novamente os atributos e o poder da unidade para uma nova batalha
    virtual void sortearAtributos() = 0;

    // Retorna o nome do tipo da unidade
    // Usado na impressão das unidades do exército.
    virtual std::string getTipo() const = 0;

    // Imprime informações da unidade
    virtual void print() const;

    // Soma uma destruicao ao registro da unidade
    void somaDestruicao();

    // Retorna o total de destruicoes da unidade
    int getDestruicoes() const;
    
};