#pragma once
#include<iostream>
#include<sstream>
#include"SitioWeb.h"

class BookMark {
private:
	SitioWeb* pinned;
	std::string tag;
public:


	BookMark(SitioWeb*, std::string t);
	BookMark();


	SitioWeb* getSitio();
	std::string getTag();


	void setSitio(SitioWeb*);
	void setTag(std::string);

	std::string toString();

	std::string entireToString();

	void guardarArchivo(std::ofstream& out) const;
	void cargarArchivo(std::ifstream& in);
};