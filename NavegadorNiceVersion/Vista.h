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

	static void historialIncognito();


	static void tagNoExiste();

	static void mensajeMostrarHistorial();

	static int cambioTipoPestanaAIncognito();

	static int cambioTipoPestanaANormal();

	static int subMenuHistorial();
	static std::string ventanaFiltro();

	static void noSitioPestActual();

	static void incognitoBookMark();
};

