#include "SitioWeb.h"

SitioWeb::SitioWeb(std::string d, std::string u, std::string t) {
    dominio = d;
    URL = u;
    titulo = t;
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

SitioWeb::~SitioWeb() { }


void SitioWeb::guardarArchivo(std::ofstream& out) const {
    size_t domainLength = dominio.size();
    size_t urlLength = URL.size();
    size_t titleLength = titulo.size();

    out.write(reinterpret_cast<const char*>(&domainLength), sizeof(domainLength));
    out.write(dominio.c_str(), domainLength);
    out.write(reinterpret_cast<const char*>(&urlLength), sizeof(urlLength));
    out.write(URL.c_str(), urlLength);
    out.write(reinterpret_cast<const char*>(&titleLength), sizeof(titleLength));
    out.write(titulo.c_str(), titleLength);
}

void SitioWeb::cargarArchivo(std::ifstream& in) {
    size_t domainLength;
    size_t urlLength;
    size_t titleLength;

    in.read(reinterpret_cast<char*>(&domainLength), sizeof(domainLength));
    dominio.resize(domainLength);
    in.read(&dominio[0], domainLength);

    in.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
    URL.resize(urlLength);
    in.read(&URL[0], urlLength);

    in.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength));
    titulo.resize(titleLength);
    in.read(&titulo[0], titleLength);
}
