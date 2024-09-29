#include "Vista.h"

int Vista::menuPrincipal()
{
    int opc;
    std::cout << "/////MENU/////\n";
    std::cout << "1. Agregar Pestanha\n";
    std::cout << "2. Ingresar Sitio\n";
    std::cout << "3. Historial de la Pestana\n";
    std::cout << "4. Agregar Sitio Actual a BookMarks\n";
    std::cout << "5. Cambiar Modo de Pestanha \n";
    std::cout << "6. Importar Historial\n";
    std::cout << "7. Exportar Historial\n";
    std::cout << "8. Configuracion de Politicas\n";
    std::cout << "9. Exit\n";
    std::cin >> opc;
    
    system("cls");
    return opc;

}

int Vista::subMenuAgregarPestana(){
    int opc;
    std::cout << "Seleccione el tipo de busqueda que desea agregar:\n";
    std::cout << "1. Busqueda Normal\n";
    std::cout << "2. Busqueda Incognita\n";
    std::cin >> opc;
    system("pause");
    system("cls");
    return opc;
}

std::string Vista::addBookMark(){
    std::string tag;
    std::cout << "Ingrese el tag del sitio que desea guardar en marcadores:\n";
    std::cin >> tag;
    system("pause");
    system("cls");
    return tag;
}

std::string Vista::subMenuAgregarSitio(){
    std::string sitio;
    std::cout << "Ingrese la URL del sitio que desea buscar:\n";
    std::cin >> sitio;
    system("pause");
    system("cls");
    return sitio;
}

std::string Vista::ventanaBuscarSitio()
{
    std::string url;
    std::cout << "Ingrese la direccion URL del sitio web:\n";
    std::cin >> url;
    system("pause");
    system("cls");
    return url;
}

int Vista::menuBookMark()
{
    int opc;
    cout << "MARCADORES" << endl;
    cout << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "1. Crear un marcador del sitio actual" << endl;
    cout << "2. Buscar un SitioWeb por etiqueta" << endl;
    cout << "3. Regresar al menu principal" << endl;
    cin >> opc;
    system("pause");
    system("cls");
    return opc;
}

BookMark* Vista::agregarBookmark()
{
    BookMark* bk;
    SitioWeb* sw = new SitioWeb();
    std::cout << "Ingrese la etiqueta para el marcador:\n";
    std::string tag;
    std::cin >> tag;
    std::cout << "Ingrese el url del Sitio Web para el marcador:\n";
    std::string url;
    std::cin >> url;
    system("pause");
    system("cls");
    bk = new BookMark();
    sw->setURL(url);
    bk->setTag(tag);
    bk->setSitio(sw);
    return bk;
}

string Vista::buscarBookMark()
{
    string tag;
    cout << "Ingrese la etiqueta del Sitio Web" << endl;
    cin >> tag;
    system("pause");
    system("cls");
    return tag;
}

int Vista::configPoliticas()
{
    int opc;
    std::cout << "/////Menu Politicas de Historial/////\n";
    std::cout << "1. Limitar Entradas de Historial\n";
    std::cout << "2. Limpiar Entradas viejas\n";
    std::cout << "3. Salir\n";
    std::cin >> opc;
    system("pause");
    system("cls");
    return opc;
}

void Vista::mensajeError() {
    std::cout << "No hay mas sitios web\n";
}

int Vista::opc1Politicas()
{
    int cant;
    std::cout << "Limitar Entradas de Historial\n";
    std::cout << "Ingrese la cantidad de entradas limite:";
    std::cin >> cant;
    system("pause");
    system("cls");
    return cant;
}

double Vista::opc2Politicas()
{
    double min;
    std::cout << "Limpiar Entradas viejas\n";
    std::cout << "Ingrese el intevalo de tiempo(min):";
    std::cin >> min;
    system("pause");
    system("cls");
    return min;
}

void Vista::noPestanasExistentes(){
    std::cout << "No se han creado pestanhas aun\n";
}

void Vista::noHistorial(){
    std::cout << "Esta pestanha no tiene sitios en el historial\n";
}



void Vista::tagNoExiste(){
    std::cout << "No hay BookMarks con el tag ingresado\n";
    std::cout << "Presione 1 para salir\n";
}

void Vista::mensajeMostrarHistorial(){
    std::cout << " Historial registrado de la pestanha actual:\n\n";
}

int Vista::cambioTipoPestanaAIncognito(){
    int opc;
    std::cout << "/////Cambio Tipo Pestana /////\n";
    std::cout << "1. Cambiar Pestana a Incongnito \n";
    std::cout << "2. Salir\n";
    std::cin >> opc;
    system("pause");
    system("cls");
    return opc;
}

int Vista::cambioTipoPestanaANormal(){
    int opc;
    std::cout << "/////Cambio Tipo Pestana /////\n";
    std::cout << "1. Salir del modo  Incongnito \n";
    std::cout << "2. Salir\n";
    std::cin >> opc;
    system("pause");
    system("cls");
    return opc;
}

