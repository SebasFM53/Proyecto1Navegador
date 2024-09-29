#include "Navegador.h"


Navegador::Navegador() {
    if (pestanas.empty() == false) {
        iterador = pestanas.begin();
    }
}

Navegador::Navegador(std::list<Pestana*> pests) {
    pestanas = pests;
}

void Navegador::setPestanas(std::list<Pestana*> pests) {
    pestanas = pests;

}

std::list<Pestana*> Navegador::getPestanas() {
    return pestanas;
}

Pestana* Navegador::getPestana() {
    return (*iterador);
}

std::string Navegador::mostrarPestana() {
    std::stringstream s;
    if (pestanas.empty()) {
        s << "     No se han ingresado busquedas\n";
    }
    else {
        s << "     "<<(*iterador)->mostrarSitioActual() << "\n";
    }
    return s.str();
}

void Navegador::agregarPestana(Pestana* pest) {
    pestanas.push_front(pest);
    iterador = pestanas.begin();
}

bool Navegador::siguientePestana() {
    //if (iterador == pestanas.end()) {
    //    std::cout << "No hay mas pestanas en el historial. \n";
    //}
    //else {
    //    if (!pestanas.empty()) {
    //        iterador++;
    //        //std::cout << mostrarPestana();
    //    }
    //}
    if (pestanas.empty()) {
        std::cerr << "No hay pestanas en el historial.\n";
        return false;
    }

    if (iterador == pestanas.begin()) {
        std::cout << "Esta es la ultima pestana.\n";
        return false;
    }

    --iterador;
    std::cout << mostrarPestana() << std::endl;
    return true;
}

bool Navegador::pestanaAnterior() {
    /*if (pestanas.empty()) {
        std::cerr << "No hay pestañas en el historial.\n";
        return false;
    }

    if (iterador == pestanas.begin()) {
        std::cout << "Esta es la primera pestaña.\n";
        return false;
    }

    --iterador;
    std::cout << mostrarPestana() << std::endl;
    return true;*/
    if (pestanas.empty()) {
        std::cerr << "No hay pestanas en el historial.\n";
        return false;
    }

    ++iterador;
    if (iterador == pestanas.end()) {
        iterador = pestanas.begin();
    }

    std::cout << mostrarPestana() << std::endl;
    return true;
}

bool Navegador::empty(){
    if (pestanas.empty()) {
        return true;
    }
    else
        return false;
}

Navegador::~Navegador()
{
}


void Navegador::guardarArchivo(std::ofstream& out) const {
    size_t size = pestanas.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const Pestana* pestaña : pestanas) {
        if (pestaña->getIncognito()) {
            continue;
        }
        pestaña->guardarArchivo(out);
    }
}

void Navegador::cargarArchivo(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (in.is_open()) {
        size_t size;
        in.read(reinterpret_cast<char*>(&size), sizeof(size));
        pestanas.clear();

        for (size_t i = 0; i < size; ++i) {
            Pestana* pestaña = new Pestana();
            pestaña->cargarArchivo("navegador.dat");
            pestanas.push_back(pestaña);
        }

        in.close();
    }
    else {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
    }
}
