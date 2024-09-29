#include "FileManager.h"

FileManager::FileManager(Navegador* navegador, BookMarkList* marcadores) : nav(navegador), marks(marcadores) {
    this->sitios = cargarSitios("sites.csv");

}

FileManager::FileManager(std::list<SitioWeb*> sitios, Navegador* navegador, BookMarkList* marcadores) : sitios(sitios), nav(navegador),
marks(marcadores) {  
}

FileManager::~FileManager()
{
    for (auto sitio : sitios) {
        delete sitio;
    }
    sitios.clear();
}

std::list<SitioWeb*> FileManager::cargarSitios(const std::string& filename) {
    std::list<SitioWeb*> sitios;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Error al abrir el archivo: " << filename << std::endl;
        return sitios;
    }

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string url, domain, title;

        if (std::getline(std::getline(iss, url, ','), domain, ',') && std::getline(iss, title, ',')) {
            SitioWeb* sitio = new SitioWeb(domain, url, title);
            sitios.push_back(sitio);
        }
    }

    file.close();
    return sitios;
}

SitioWeb* FileManager::checkURL(std::string url) {
    for (auto sitioWeb : sitios) {
        if (sitioWeb->getURL() == url) {
            //std::cout << "URL found: " << sitioWeb->getURL() << std::endl;
            //std::cout << "Title: " << sitioWeb->getTitulo() << std::endl;
            return sitioWeb;
        }
        else {
            std::cout << "404 - Not Found" << std::endl;
            return nullptr;
        }
    }
}

void FileManager::guardarNavegador(const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);
    if (!out.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar el navegador: " << filename << std::endl;
        return;
    }

    nav->guardarArchivo(out);
    out.close();
}

void FileManager::cargarNavegador(const std::string& filename) {
    nav->cargarArchivo("navegador.dat");
}

void FileManager::guardarBookmarks(const std::string& filename) {
    marks->guardarArchivo("marcadores.dat");
}

void FileManager::cargarBookmarks(const std::string& filename) {
    marks->cargarArchivo("marcadores.dat");
}

std::list<SitioWeb*> FileManager::getSitios() {
    return sitios;
}
