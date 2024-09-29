#pragma once
#include <fstream>
#include "BookMarkList.h"
#include "SitioWeb.h"
#include <list>
#include "Navegador.h"
class FileManager
{
private:
    std::list<SitioWeb*> sitios;
    Navegador* nav;
    BookMarkList* marks;
public:
    FileManager(Navegador* navegador, BookMarkList* marcadores);
    FileManager(std::list<SitioWeb*> sitios, Navegador* navegador, BookMarkList* marcadores);
    ~FileManager();
    static std::list<SitioWeb*> cargarSitios(const std::string& filename);
    SitioWeb* checkURL(std::string url);

    void guardarNavegador(const std::string& filename);
    void cargarNavegador(const std::string& filename);

    void guardarBookmarks(const std::string& filename);
    void cargarBookmarks(const std::string& filename);

    std::list<SitioWeb*> getSitios();

};

