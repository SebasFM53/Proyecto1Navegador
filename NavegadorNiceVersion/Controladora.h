#pragma once
#include <iostream>
#include "Navegador.h"
#include "Vista.h"
#include "FileManager.h"
#include "BookMarkList.h"
#include <windows.h>

using namespace std;


class Controladora
{
private:
	Navegador* navegadorWeb;
	BookMarkList* listaBookmarks;
	FileManager* fileMan;
	int limiteEntradas;

public:
	Controladora();
	void menuPrincipal();
	void agregarPestanha();
	void agregarSitioWeb();
	void mostarHistorialPestActual();
	void addtoBookMark();



	void busquedas();
	void marcadores();
	void nuevaPestana();
	void Historial();
	void filtrar();
	void incognito();
	void exportar();
	void importar();
	void configuracion();
	void limitarEntradas();
	void limpiarEntradasViejas();
	void flechas();
	void cambioModalidadPestana();

};

