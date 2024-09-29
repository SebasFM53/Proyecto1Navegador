#pragma once
#include"BookMark.h"
#include<iostream>
#include<sstream>
#include<vector>

class BookMarkList {
private:
	std::vector<BookMark*> marcadores;
	std::vector<BookMark*>::iterator iterador;
public:
	BookMarkList();
	BookMarkList(std::vector<BookMark*>);


	bool addBookMark(BookMark*);

	BookMark* getBookMark(std::string);
	std::vector<BookMark*> getMarcadores();
	std::string toString();

	std::string toStringList();

	bool deleteBooKMark(std::string);

	void guardarArchivo(const std::string& filename) const;
	void cargarArchivo(const std::string& filename);

	int conteoBookMarks();
};