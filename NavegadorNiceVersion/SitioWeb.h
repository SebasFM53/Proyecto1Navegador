#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "ExcepcionNoExiste.h"
class SitioWeb {
private:
	std::string dominio;
	std::string URL;
	std::string titulo;
	bool agregadoIncognito;
public:

	//Constructores
	SitioWeb(std::string d, std::string u, std::string t);
	SitioWeb();

	//Get's
	std::string getDominio();
	std::string getURL();
	std::string getTitulo();

	//Set's
	void setDominio(std::string d);
	void setURL(std::string u);
	void setTitulo(std::string t);

	//Otros metodos
	std::string toString();
	void setAgregadoEnIncognito(bool);
	bool getAgregadoEnIncognito();

	// Destructor

	virtual ~SitioWeb();

	void guardarArchivo(std::string filename, const SitioWeb& sitio);
	void cargarArchivo(std::string filename, SitioWeb& sitio);

};

//std::ostream& operator<<(std::ostream& os, SitioWeb& sitio) {
//	os << sitio.toString();
//	return os;
//}
