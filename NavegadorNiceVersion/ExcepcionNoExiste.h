#pragma once
#include <exception>
#include <string>

class ExcepcionNoExiste : public std::exception {
private:
    std::string mensaje;

public:
    ExcepcionNoExiste (const std::string& msg) : mensaje(msg) {}

    virtual const char* what() const noexcept {
        return mensaje.c_str();
    }
};