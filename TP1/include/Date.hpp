#pragma once

#include <string>

class Date {
  public:
    // Construtor padrão inicializando com data base (01/01/2026)
    Date() : dia(1), mes(1), ano(2026) {}

    // Construtor parametrizado com validação de dia e mês
    Date(int dia, int mes, int ano);

    // Retorna a data formatada no padrão DD/MM/AAAA
    std::string formatarData() const;

  private:
    int dia = 1;
    int mes = 1;
    int ano = 2026;
};
