#include "BookMarkList.h"

BookMarkList::BookMarkList() {
	//	this->marcadores = cargarArchivo("marcadores.dat");
}

BookMarkList::BookMarkList(std::vector<BookMark*> favs) {
	marcadores = favs;
}


bool BookMarkList::addBookMark(BookMark* fav) {
	if (fav->getSitio() == nullptr) {
		return false;
	}
	else {
		marcadores.insert(marcadores.begin(), fav);
		return true;
	}
}

BookMark* BookMarkList::getBookMark(std::string tag) {
	for (int i = 0; i < marcadores.size(); i++) {
		if (marcadores.at(i)->getTag() == tag) {
			return marcadores.at(i);
		}
		else
			return nullptr;
	}
	
}

std::vector<BookMark*> BookMarkList::getMarcadores()
{
	return marcadores;
}

std::string BookMarkList::toString() {
	std::stringstream s;
	for (int i = 0; i < marcadores.size(); i++) {
		if (i > 5) {
			s << "\n";
		}
		s << marcadores.at(i)->toString() << "  ";
	}
	return s.str();
}

std::string BookMarkList::toStringList(){
	std::stringstream s;
	for (int i = 0; i < marcadores.size(); i++) {
		s << "\n";
		s << marcadores.at(i)->entireToString() << "  \n";
	}
	return s.str();
}

bool BookMarkList::deleteBooKMark(std::string tag) {
	for (int i = 0; i < marcadores.size(); i++) {
		if (marcadores.at(i)->getTag() == tag) {
			delete marcadores.at(i);
			marcadores.erase(marcadores.begin() + i);
			return true;
		}
	}
	return false;
}

void BookMarkList::guardarArchivo(const std::string& filename) const {
	std::ofstream out(filename, std::ios::binary);
	if (out.is_open()) {
		size_t size = marcadores.size();
		out.write(reinterpret_cast<const char*>(&size), sizeof(size));

		for (const BookMark* bookmark : marcadores) {
			if (bookmark) {
				bookmark->guardarArchivo(out);
			}
		}
		out.close();
	}
}

void BookMarkList::cargarArchivo(const std::string& filename) {
	std::ifstream in(filename, std::ios::binary);
	if (in.is_open()) {
		marcadores.clear();
		size_t size;
		in.read(reinterpret_cast<char*>(&size), sizeof(size));

		for (size_t i = 0; i < size; ++i) {
			BookMark* bookmark = new BookMark();
			bookmark->cargarArchivo(in);
			marcadores.push_back(bookmark);
		}
		in.close();
	}
}

int BookMarkList::conteoBookMarks(){
	return marcadores.size();
}
