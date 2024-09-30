#include <iostream>
#include "SitioWeb.h"
#include "BookMark.h"
#include "Pestana.h"
#include "Navegador.h"
#include "Controladora.h"
#include "FileManager.h"
int main() {

	Controladora* control = new Controladora();
	control->menuPrincipal();
	system("pause");
	system("cls");

	
	//Navegador* nav = new Navegador();

	//Pestana* pes = new Pestana();
	//Pestana* pes2 = new Pestana();

	//SitioWeb* site = new SitioWeb("URLA", "A", "a");
	////SitioWeb* site2 = new SitioWeb("URLB", "B", "b");
	//SitioWeb* site3 = new SitioWeb("URLC", "C", "c");
	//SitioWeb* site4 = new SitioWeb("URLD", "D", "d");
	//pes->insertarSitio(site);
	//pes->insertarSitio(site2);
	//pes2->insertarSitio(site3);

	//std::cout << pes2->mostrarSitioActual();

	//std::string filename = "sitios.dat";
	//std::ofstream out(filename, std::ios::binary);
	//std::ifstream in(filename, std::ios::binary);
	/*site->guardarArchivo(filename, *site);
	SitioWeb siteNew;
	siteNew.cargarArchivo(filename, siteNew);
	std::cout << siteNew.toString();*/

	//pes->mostrarTodoHistorial();
	//pes->guardarArchivo(out);
	/*Pestana pesNew;
	pesNew.cargarArchivo(in);
	pesNew.mostrarTodoHistorial();*/
	
	/*
	pes2->cambiaAIncognito();

	std::cout << pes2->mostrarSitioActual();

	pes2->insertarSitio(site4);

	std::cout << pes2->mostrarSitioActual();

	pes2->regresarHistorial();

	pes2->cambiarANormal();

	pes2->mostrarTodoHistorial();

	if (site4->getAgregadoEnIncognito()==true){
		std::cout << "bien\n";
	}
	else {
		std::cout << "mal\n";
	}*/

	return 0;
}