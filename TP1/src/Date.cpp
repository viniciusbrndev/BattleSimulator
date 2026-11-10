#include "Date.hpp"

#include <format>
#include <string>

Date::Date(int dia, int mes, int ano) {
    if (dia < 1 || dia > 31) {
        throw std::string("Invalid date");
    }

    if (mes < 1 || mes > 12 || (mes == 2 && dia > 28)) {
        throw std::string("Invalid date");
    }

    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

std::string Date::formatarData() const {
    return std::format("{:02}/{:02}/{}", this->dia, this->mes, this->ano);
}