#include "SitioWeb.h"

SitioWeb::SitioWeb(std::string d, std::string u, std::string t) {
    dominio = d;
    URL = u;
    titulo = t;
    agregadoIncognito = false;
}

SitioWeb::SitioWeb() {
}

std::string SitioWeb::getDominio()
{
    return dominio;
}

std::string SitioWeb::getURL()
{
    return URL;
}

std::string SitioWeb::getTitulo()
{
    return titulo;
}

void SitioWeb::setDominio(std::string d) {
    dominio = d;
}

void SitioWeb::setURL(std::string u) {
    URL = u;
}

void SitioWeb::setTitulo(std::string t) {
    titulo = t;
}

std::string SitioWeb::toString() {
    std::stringstream s;
    s << "URL: " << URL << std::endl;
    //s << dominio << std::endl;
    s << "Nombre: " << titulo << std::endl;
    return s.str();
}

void SitioWeb::setAgregadoEnIncognito(bool x){
    agregadoIncognito = x;
}

bool SitioWeb::getAgregadoEnIncognito()
{
    return agregadoIncognito;
}

SitioWeb::~SitioWeb() { }

void SitioWeb::guardarArchivo(std::string filename, const SitioWeb& sitio) {
    std::ofstream out;
    out.open(filename, std::ios::binary | std::ios::app);
    if (!out.is_open()) {
        std::cout << "Error al abrir el archivo '" << filename << "'";
        exit(EXIT_FAILURE);
    }
    out.write((char*)&sitio, sizeof(sitio));

    out.close();
}

void SitioWeb::cargarArchivo(std::string filename, SitioWeb& sitio) {
    std::ifstream out;
    out.open(filename, std::ios::binary);

    if (!out.is_open()) {
        std::cout << "Error al abrir el archivo '" << filename << "'";
        exit(EXIT_FAILURE);
    }

    out.read((char*)&sitio, sizeof(sitio));

    out.close();
}
