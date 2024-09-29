#include "Pestana.h"


Pestana::Pestana() {

    numPestana = 0;
    incognito = false;
    if (historial.empty() == false) {
        iterador = historial.begin();
    }
}

Pestana::Pestana(int num) {
    numPestana = num;
    incognito = true;
}

Pestana::Pestana(SitioWeb* site) {
    numPestana = 0;
    incognito = true;
    historial.push_back(site);
}

Pestana::Pestana(bool inc){
    incognito = inc;
}

int Pestana::getNumPestana() const {
    return numPestana;
}

bool Pestana::getIncognito() const {
    return incognito;
}

std::list<SitioWeb*>& Pestana::getHistorial()
{
    return this->historial;
}

void Pestana::setHistorial(std::list<SitioWeb*> hist) {
    historial = hist;
}

void Pestana::setNumPestana(int num) {
    numPestana = num;
}

void Pestana::setIncognito(bool incg) {

    incognito = incg;
}

std::string Pestana::mostrarSitioActual() {
    std::stringstream s;
    if (historial.empty()) {
        s << "No se han ingresado Sitios\n";
    }
    else {
        std::cout << "PESTANA " << getNumPestana() << std::endl;
        s << (*iterador)->toString() << "\n";
    }
    return s.str();
}

void Pestana::insertarSitio(SitioWeb* sitio) {
    /*if (incognito == false) {
        historial.push_front(sitio);
        iterador = historial.begin();
    }
    else {
        eliminarMasReciente();
        historial.push_front(sitio);
        iterador = historial.begin();
    }*/

    if (incognito && !historial.empty()) {
        // Si estamos en modo incognito y ya hay sitios en el historial, eliminamos el más reciente
        delete* historial.begin();
        historial.erase(historial.begin());
    }

    // Insertamos el nuevo sitio
    historial.push_front(sitio);
    iterador = historial.begin();  // Actualizamos el iterador para que apunte al nuevo sitio

}

/*void Pestana::adelantarHistorial() {

    if (incognito==true){
        std::cout << "Pestanha incognita, no hay historial por mostrar\n";
    }
    else {
        if (!historial.empty()) {
            if (iterador == historial.begin()) {
                std::cout << "Este es el sitios mas recientemente registrado en el historial\n";
            }
            else {
                iterador--;
                std::cout << mostrarSitioActual();
            }
        }
    }
}

void Pestana::regresarHistorial(){
    if (incognito==true){
        std::cout << "Pestanha incognita, no hay historial por mostral\n";
    }
    else {
        if (!historial.empty()) {
            if (iterador == historial.end()) {
                std::cout << "No existen mas sitios registrados en el historial\n";
            }
            else {
                iterador++;
                std::cout << mostrarSitioActual();
            }
        }
    }
}*/


void Pestana::regresarHistorial() {
    if (incognito) {
        std::cout << "Pestana incognita, no hay historial por mostrar\n";
    }
    else {
        if (iterador == historial.end() || std::next(iterador) == historial.end()) {
            std::cout << "No existen mas sitios registrados en el historial\n";
        }
        else {
            iterador++;
            std::cout << mostrarSitioActual();
        }
    }
}

void Pestana::adelantarHistorial() {
    if (incognito) {
        std::cout << "Pestana incognita, no hay historial por mostrar\n";
    }
    else {
        if (iterador == historial.begin()) {
            std::cout << "Este es el sitio mas reciente registrado en el historial\n";
        }
        else {
            iterador--;
            std::cout << mostrarSitioActual();
        }
    }
}


Pestana::~Pestana()
{
}

void Pestana::eliminarMasReciente() {
    if (!historial.empty()) {
        // Liberamos la memoria del sitio más reciente
        SitioWeb* sitioAEliminar = *historial.begin();
        delete sitioAEliminar;  // Eliminamos el objeto que el iterador apunta

        // Eliminamos el iterador del historial
        historial.erase(historial.begin());


        // Actualizamos el iterador si la lista no está vacía
        if (!historial.empty()) {
            iterador = historial.begin();
        }
        else {
            iterador = historial.end();
        }
    }
}

int Pestana::conteoSitios()
{
    return historial.size();
}

void Pestana::ultimoElemento() {
    if (iterador == historial.end()) {
        std::cout << "Si es el ultimo\n";
    }
    else {
        std::cout << "No es el ultimo\n";
    }
}

void Pestana::primerElemento() {
    if (iterador == historial.begin()) {
        std::cout << "Si es el primero\n";
    }
}

void Pestana::mostrarTodoHistorial() {
    for (std::list<SitioWeb*>::iterator it = historial.begin(); it != historial.end(); ++it) {
        std::cout<<(*it)->toString();
    }
}


void Pestana::guardarArchivo(std::ofstream& out) const {
    size_t size = historial.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const SitioWeb* sitio : historial) {
        sitio->guardarArchivo(out);
    }
}

void Pestana::cargarArchivo(const std::string& filename) {
    size_t size;
    std::ifstream in(filename, std::ios::binary);
    if (!in.read(reinterpret_cast<char*>(&size), sizeof(size))) {
        std::cerr << "Error al leer el tamaño del historial." << std::endl;
        return;
    }

    historial.clear();

    for (size_t i = 0; i < size; ++i) {
        SitioWeb* sitio = new SitioWeb();
        sitio->cargarArchivo(in);
        historial.push_back(sitio);
    }
}

SitioWeb* Pestana::getSitioActualPestActual(){
    if (historial.empty() == false) {
        return (*iterador);
    }
    else
        return nullptr;
}
