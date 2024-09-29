#pragma once
#include"SitioWeb.h"
//#include"Vista.h"
#include <list>
#include<iostream>
#include <sstream>

class Pestana {
private:
	std::list<SitioWeb*> historial;
	std::list<SitioWeb*>::iterator iterador;
	int numPestana;
	bool incognito;
public:
	Pestana();
	Pestana(int);
	Pestana(SitioWeb* site);
	Pestana(bool inc);


	int getNumPestana()const;
	bool getIncognito()const;
	std::list<SitioWeb*>& getHistorial();
	void setHistorial(std::list<SitioWeb*>);

	void setNumPestana(int);
	void setIncognito(bool);

	std::string mostrarSitioActual();

	void insertarSitio(SitioWeb* sitio);

	void adelantarHistorial();

	void regresarHistorial();

	virtual ~Pestana();

	void eliminarMasReciente();

	int conteoSitios();

	void ultimoElemento();
	void primerElemento();

	void mostrarTodoHistorial();

	void guardarArchivo(std::ofstream& out) const;
	void cargarArchivo(const std::string& filename);


	void cambiaAIncognito();
	void cambiarANormal();

	SitioWeb* getSitioActualPestActual();






};