#include <iostream>
#include "SitioWeb.h"
#include "BookMark.h"
#include "Pestana.h"
#include "Navegador.h"
#include "Controladora.h"
#include "FileManager.h"
int main() {

	Controladora* control = new Controladora();
	control->menuPrincipal();
	system("pause");
	system("cls");

	
	

	return 0;
}