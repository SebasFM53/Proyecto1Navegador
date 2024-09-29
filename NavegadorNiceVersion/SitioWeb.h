#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

class SitioWeb {
private:
	std::string dominio;
	std::string URL;
	std::string titulo;
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

	// Destructor

	virtual ~SitioWeb();

	void guardarArchivo(std::ofstream& out) const;
	void cargarArchivo(std::ifstream& in);

};

//std::ostream& operator<<(std::ostream& os, SitioWeb& sitio) {
//	os << sitio.toString();
//	return os;
//}
