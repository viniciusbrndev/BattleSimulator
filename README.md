# Sistema de Simulação de Batalhas Estratégicas em C++ (POO)

![C++23](https://img.shields.io/badge/C%2B%2B-23-blue.svg)
![Build](https://img.shields.io/badge/build-Makefile-brightgreen.svg)
![Clang](https://img.shields.io/badge/compiler-Clang%2021%20%7C%20GCC%2015-violet.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

Este repositório contém o código-fonte, a documentação e os scripts de compilação do **Sistema de Simulação de Batalhas Estratégicas**, um protótipo de jogo militar orientado a objetos com motor de simulação por turnos automatizados.

Trabalho prático desenvolvido para a disciplina **BCC 138 — Programação Orientada a Objetos** do Departamento de Computação (DECOM/ICEB) da **Universidade Federal de Ouro Preto (UFOP)**.

---

## 👨‍💻 Autores

- **Kaio Alves Simões**
- **Luiz Henrique Silva Sampaio**
- **Victor Kangussu**
- **Vinícius Brandão**

**Professor Orientador:** Prof. Guillermo Camara Chavez

---

## 📐 Estrutura do Projeto e Tecnologias

- **Linguagem:** C++ (Padrão **ISO C++23**)
- **Compiladores:** Clang++ (v21.1+) / GCC (v15.3+)
- **Sinalizadores de Rigor:** `-std=c++23 -Wall -Wextra -Wpedantic`
- **Automação de Build:** GNU Make
- **Paradigma:** Programação Orientada a Objetos (Herança, Polimorfismo Dinâmico via `vtable`, Abstração, Encapsulamento, RAII e STL)

### 📁 Organização dos Diretórios

```text
.
├── Makefile                # Script de compilação modular e automatizada
├── src/                    # Código-fonte principal (.hpp e .cpp)
│   ├── Date.hpp / .cpp     # Encapsulamento de datas (DD/MM/AAAA)
│   ├── Unidade.hpp / .cpp  # Classe Abstrata base
│   ├── Infantaria.hpp/.cpp # Subclasse especializada (Força / Velocidade)
│   ├── Veiculo.hpp / .cpp  # Subclasse especializada (Blindagem / Potência)
│   ├── Aeronave.hpp / .cpp # Subclasse especializada (Manobrabilidade / Alcance)
│   ├── Exercito.hpp / .cpp # Agregador de unidades (unique_ptr)
│   ├── Batalha.hpp / .cpp  # Orquestrador de confrontos e baixas
│   ├── Campanha.hpp / .cpp # Torneio todos-contra-todos e ranking
│   └── main.cpp            # Ponto de entrada (cenário de teste)
├── obj/                    # Objetos compilados intermediários (.o e .d)
└── build/                  # Executável gerado (game)
```

---

## 🏗️ Destaques da Arquitetura e Modelagem POO

### 1. Hierarquia Polimórfica de Unidades (`vtable`)
A classe abstrata `Unidade` força a implementação do método virtual puro `getPoderAtaque()`, permitindo que cada classe filha calcule seu poder dinamicamente:

```cpp
// Unidade.hpp - Classe base abstrata
class Unidade {
protected:
    int poderAtaque;
    int destruicoes{0};
public:
    virtual ~Unidade() = default; // Destrutor virtual essencial (RAII)
    virtual int getPoderAtaque() const = 0;
    virtual void sortearAtributos() = 0;
    virtual std::string getTipo() const = 0;
    void somaDestruicao() { destruicoes++; }
    int getDestruicoes() const { return destruicoes; }
};
```

### 2. Ponderação Particular de Poder por Classe Concreta

#### 🪖 Infantaria (Teto teórico: ~53)
$$\text{Poder}_{\text{Infantaria}} = \left\lfloor \frac{(\text{poderAtaque} \times 5) + (\text{forca} \times 3) + (\text{velocidade} \times 2)}{10} \right\rfloor$$

#### 🚜 Veículo (Teto teórico: ~73)
$$\text{Poder}_{\text{Veiculo}} = \left\lfloor \frac{(\text{poderAtaque} \times 5) + (\text{blindagem} \times 4) + (\text{potenciaDeFogo} \times 1)}{10} \right\rfloor$$

#### ✈️ Aeronave (Teto teórico: ~76)
$$\text{Poder}_{\text{Aeronave}} = \left\lfloor \frac{(\text{poderAtaque} \times 5) + (\text{manobrabilidade} \times 3) + (\text{alcance} \times 2)}{10} \right\rfloor$$

```cpp
// Veiculo.cpp - Sobrescrita do cálculo com ponderação própria
int Veiculo::getPoderAtaque() const {
    return (poderAtaque * 5 + blindagem * 4 + potenciaDeFogo * 1) / 10;
}
```

### 3. Gerenciamento Moderno de Memória (RAII & Smart Pointers)
Para eliminar vazamentos de memória (*memory leaks*) sem a necessidade de chamadas manuais à primitiva `delete`, a aplicação utiliza ponteiros inteligentes da STL:

```cpp
// Exercito.hpp - Posse exclusiva das unidades via unique_ptr
class Exercito {
private:
    std::string nome;
    std::vector<std::unique_ptr<Unidade>> unidades; // Move ownership
    int vitorias{0}, derrotas{0}, empates{0};
public:
    void adicionarUnidade(std::unique_ptr<Unidade> u) {
        unidades.push_back(std::move(u));
    }
};

// Campanha.hpp - Compartilhamento seguro de exércitos entre batalhas
class Campanha {
private:
    std::vector<std::shared_ptr<Exercito>> exercitos;
    std::vector<std::unique_ptr<Batalha>> batalhas;
};
```

### 4. Ordenação Composta com Lambdas da STL
A classificação final na tabela de posições é calculada dinamicamente ordenando o contêiner via `std::sort` com critérios encadeados:

```cpp
// Campanha.cpp - Ordenação por Pontos -> Vitórias
std::sort(tabela.begin(), tabela.end(), 
    [](const std::shared_ptr<Exercito>& a, const std::shared_ptr<Exercito>& b) {
        if (a->getPontos() != b->getPontos()) {
            return a->getPontos() > b->getPontos();
        }
        return a->getVitorias() > b->getVitorias();
    });
```

---

## ⚡ Como Compilar e Executar

### Pré-requisitos
- Compilador C++23 (`clang++` $\ge 18$ ou `g++` $\ge 13$)
- `make`

### Compilação Automatizada
```bash
# Compilar o executável no diretório build/game
make

# Limpar artefatos compilados (.o, .d e binários)
make clean

# Recompilar do zero
make re
```

### Compilação Manual Direta
```bash
clang++ -std=c++23 -Wall -Wextra -Wpedantic src/*.cpp -o build/game
```

### Execução
```bash
./build/game
```

---

## 🖥️ Demonstração da Saída do Programa

Ao executar o programa (`./build/game`), o torneio em rodada dupla é simulado e os dados são emitidos no terminal e exportados para o arquivo `tabela.txt`:

```text
--- Unidades do Exercito 1 ---
Infantaria - Poder de Ataque: 43 - Destruicoes: 0
Infantaria - Poder de Ataque: 45 - Destruicoes: 0
Veiculo - Poder de Ataque: 59 - Destruicoes: 0
Veiculo - Poder de Ataque: 45 - Destruicoes: 0
Aeronave - Poder de Ataque: 65 - Destruicoes: 0

------- Tabela de Posicoes -------
1. Exercito 3 - 12 pontos - Vitórias: 4, Empates: 0, Derrotas: 0
2. Exercito 1 - 3 pontos - Vitórias: 1, Empates: 0, Derrotas: 3
3. Exercito 2 - 3 pontos - Vitórias: 1, Empates: 0, Derrotas: 3

Unidade mais destrutiva: Infantaria do exercito Exercito 3 com 4 destruicoes
```

---

## 📄 Licença

Este projeto é disponibilizado sob a licença [MIT](LICENSE).