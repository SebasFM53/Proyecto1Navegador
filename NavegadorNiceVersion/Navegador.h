#pragma once
#include "Pestana.h"
#include <iostream>
#include <sstream>
#include <list>
#include "BookMarkList.h"

class Navegador {
private:
	std::list <Pestana*> pestanas;
	std::list <Pestana*>::iterator iterador;

public:
	
	Navegador();
	Navegador(std::list<Pestana*>);

	void setPestanas(std::list<Pestana*>);

	std::list<Pestana*> getPestanas();

	Pestana* getPestana();

	std::string mostrarPestana();

	void agregarPestana(Pestana* pest);

	bool siguientePestana();

	bool pestanaAnterior();

	bool empty();

	virtual ~Navegador();

	

	void guardarArchivo(std::ofstream& out) const;
	void cargarArchivo(const std::string& filename);

};