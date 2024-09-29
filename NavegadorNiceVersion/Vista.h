#pragma once
#include <iostream>
#include "Controladora.h"
class Vista
{

public:
	static int menuPrincipal();
	static int subMenuAgregarPestana();
	static std::string subMenuAgregarSitio();
	static std::string addBookMark();
	static std::string ventanaBuscarSitio();
	static int menuBookMark();
	static BookMark* agregarBookmark();
	static std::string buscarBookMark();
	static int configPoliticas();
	static void mensajeError();
	static int opc1Politicas();
	static double opc2Politicas();
	
	static void noPestanasExistentes();
	static void noHistorial();

	static void tagNoExiste();
};

