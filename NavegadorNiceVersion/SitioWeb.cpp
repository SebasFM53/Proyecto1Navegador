#include "SitioWeb.h"
#include <vector>

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


void SitioWeb::guardarArchivo(const std::string& filename) {
    std::ofstream out(filename, std::ios::binary | std::ios::app);
    size_t domainLength = dominio.size();
    size_t urlLength = URL.size();
    size_t titleLength = titulo.size();

    std::vector<char> buffer;
    buffer.resize(sizeof(domainLength) + domainLength + sizeof(urlLength) + urlLength + sizeof(titleLength) + titleLength);

    char* ptr = buffer.data();

    // Copiamos la longitud del dominio
    std::memcpy(ptr, &domainLength, sizeof(domainLength));
    ptr += sizeof(domainLength); // Mover el puntero

    // Copiamos el dominio
    std::memcpy(ptr, dominio.c_str(), domainLength);
    ptr += domainLength; // Mover el puntero

    // Copiamos la longitud de la URL
    std::memcpy(ptr, &urlLength, sizeof(urlLength));
    ptr += sizeof(urlLength); // Mover el puntero

    // Copiamos la URL
    std::memcpy(ptr, URL.c_str(), urlLength);
    ptr += urlLength; // Mover el puntero

    // Copiamos la longitud del título
    std::memcpy(ptr, &titleLength, sizeof(titleLength));
    ptr += sizeof(titleLength); // Mover el puntero

    // Copiamos el título
    std::memcpy(ptr, titulo.c_str(), titleLength);

    // Escribimos el buffer en el archivo
    out.write(buffer.data(), buffer.size());
}

void SitioWeb::cargarArchivo(std::ifstream& in) {
    if (!in.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    // Leer el tamaño total del buffer
    in.seekg(0, std::ios::end); // Mover al final del archivo
    size_t fileSize = in.tellg(); // Obtener el tamaño del archivo
    in.seekg(0, std::ios::beg); // Volver al principio

    // Crear un buffer para almacenar los datos
    std::vector<char> buffer(fileSize);
    in.read(buffer.data(), fileSize); // Leer todo el contenido en el buffer

    // Usar un puntero para navegar a través del buffer
    char* ptr = buffer.data();

    // Leer longitudes
    size_t domainLength;
    std::memcpy(&domainLength, ptr, sizeof(domainLength)); ptr += sizeof(domainLength);

    dominio.resize(domainLength);
    std::memcpy(&dominio[0], ptr, domainLength); ptr += domainLength;

    size_t urlLength;
    std::memcpy(&urlLength, ptr, sizeof(urlLength)); ptr += sizeof(urlLength);

    URL.resize(urlLength);
    std::memcpy(&URL[0], ptr, urlLength); ptr += urlLength;

    size_t titleLength;
    std::memcpy(&titleLength, ptr, sizeof(titleLength)); ptr += sizeof(titleLength);

    titulo.resize(titleLength);
    std::memcpy(&titulo[0], ptr, titleLength); ptr += titleLength;
}
