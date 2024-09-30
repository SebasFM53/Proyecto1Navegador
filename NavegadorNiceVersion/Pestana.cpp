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
        s << (*iterador)->toString() << "\n";
    }
    return s.str();
}

void Pestana::insertarSitio(SitioWeb* sitio) {
 

    if (incognito==true ) {
        if (!historial.empty()){
            // Si estamos en modo incognito y ya hay sitios en el historial, eliminamos el más reciente
            if (getSitioActualPestActual()->getAgregadoEnIncognito() == true) {
                eliminarMasReciente();
            }
        }
        sitio->setAgregadoEnIncognito(true);
    }

    // Insertamos el nuevo sitio
    historial.push_front(sitio);
    iterador = historial.begin();  // Actualizamos el iterador para que apunte al nuevo sitio

}

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
           // std::cout << mostrarSitioActual();
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
           // std::cout << mostrarSitioActual();
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

        // Eliminamos el primer elemento del historial
        historial.erase(historial.begin());

        // Si la lista no está vacía, actualizamos el iterador
        if (!historial.empty()) {
            iterador = historial.begin();
        }
        else {
            // Si el historial está vacío, ponemos el iterador en `end()`, indicando que no apunta a ningún elemento
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
    if (incognito==true){
        std::cout << "Pestanha incognita, no hay historial por mostrar\n";
    }
    else {
        for (std::list<SitioWeb*>::iterator it = historial.begin(); it != historial.end(); ++it) {
            std::cout << (*it)->toString();
        }
    }
}

void Pestana::guardarArchivo(std::ofstream& out) const {
    size_t size = historial.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (SitioWeb* sitio : historial) {
        sitio->guardarArchivo("sitios.dat", *sitio);
    }
}

void Pestana::cargarArchivo(std::ifstream& in) {
    if (!in.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    size_t size;
    if (!in.read(reinterpret_cast<char*>(&size), sizeof(size))) {
        std::cerr << "Error al leer el tamaño del historial." << std::endl;
        return;
    }

    historial.clear();

    // Cargar sitios web del historial
    for (size_t i = 0; i < size; ++i) {
       // SitioWeb* sitio = new SitioWeb();
        SitioWeb sitio;
        sitio.cargarArchivo("sitios.dat", sitio);
        historial.push_front(&sitio);
    }
}

void Pestana::cambiaAIncognito(){
    setIncognito(true);
}

void Pestana::cambiarANormal() {
    if (incognito && !historial.empty()) {
        // Verificamos nuevamente que la lista no esté vacía antes de proceder
        SitioWeb* sitioActual = historial.front(); // Obtener el primer sitio web
        if (sitioActual != nullptr && sitioActual->getAgregadoEnIncognito() == true) {
            delete sitioActual; // Liberar la memoria del sitio
            historial.pop_front(); // Eliminar el primer sitio del historial
        }
    }
    incognito = false; // Cambiar al modo normal
}



SitioWeb* Pestana::getSitioActualPestActual(){
    if (historial.empty() == false) {
        return (*iterador);
    }
    else
        return nullptr;
}

void Pestana::mostrarHistorialFiltrado(std::string filtro)
{
    if (incognito == true) {
        std::cout << "Pestanha incognita, no hay historial por mostrar\n";
    }
    else {
        for (std::list<SitioWeb*>::iterator it = historial.begin(); it != historial.end(); ++it) {
            if (((*it)->getTitulo().find(filtro) != std::string::npos)|| ((*it)->getURL().find(filtro) != std::string::npos)) {
                std::cout << (*it)->toString();
            }
        }
    }

}
