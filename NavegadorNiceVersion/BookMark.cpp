#include "BookMark.h"

BookMark::BookMark(SitioWeb* sitio, std::string t) {
    pinned = sitio;
    tag = t;
}

BookMark::BookMark() {
    pinned = nullptr;
    tag = " ";
}

SitioWeb* BookMark::getSitio()
{
    return pinned;
}

std::string BookMark::getTag()
{
    return tag;
}

void BookMark::setSitio(SitioWeb* sitio) {
    pinned = sitio;
}
                                                    //       NAVEGADOR   
void BookMark::setTag(std::string t) {              // LISTA DE BOOKMARKS SOLO CON TAG
    tag = t;                                           // PESTANHA NO.1
}                                                       // SITIO ACTUAL

std::string BookMark::toString() {
    std::stringstream s;
    if (pinned != nullptr) {
        s << tag << " " ;
    }
    else {
        s << "Error" << " " << std::endl;
    }
    return s.str();
}

std::string BookMark::entireToString(){
    std::stringstream s;
    if (pinned != nullptr) {
        s << tag << " "<< pinned->getTitulo() << "\n";
    }
    else {
        s << "Error" << " " << std::endl;
    }
    return s.str();
}


void BookMark::guardarArchivo(std::ofstream& out) const {
    size_t len = tag.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(tag.c_str(), len);

    if (pinned) {
        pinned->guardarArchivo("marcadores.dat", *pinned);
    }
    else {
        len = 0;
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    }
}

void BookMark::cargarArchivo(std::ifstream& in) {
    size_t len;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    tag.resize(len);
    in.read(&tag[0], len);
    in.read(reinterpret_cast<char*>(&len), sizeof(len));

    if (len > 0) {
        pinned = new SitioWeb();
        pinned->cargarArchivo("marcadores.dat", *pinned);
    }
    else {
        pinned = nullptr;
    }
}