#include "Controladora.h"

Controladora::Controladora()
{
	this->navegadorWeb = new Navegador();
	this->listaBookmarks = new BookMarkList();
	this->fileMan = new FileManager(navegadorWeb, listaBookmarks);
	limiteEntradas = 10;
}

void Controladora::menuPrincipal()
{
	int opc;

	do {
		cout << "==========================================================\n";
		cout << "\n";
		cout << navegadorWeb->mostrarPestana();
		cout << "\n";
		cout << "==========================================================\n";
		cout << "\n";
		opc = Vista::menuPrincipal();
		/*if (GetAsyncKeyState(VK_UP) & 0x8000) {
			navegadorWeb->siguientePestana();

		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			navegadorWeb->pestanaAnterior();

		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			navegadorWeb->getPestana()->regresarHistorial();

		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			navegadorWeb->getPestana()->adelantarHistorial();

		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			break;
		}*/
		switch (opc) {
		case 1:
			agregarPestanha();
			system("cls");
			break;
		case 2:
			if (navegadorWeb->empty()==false) {
				agregarSitioWeb();
			}
			else
				Vista::noPestanasExistentes();
			system("pause");
			//system("pause");
			//system("cls");
			break;
		case 3:
			if (navegadorWeb->empty()== false) {
				if (navegadorWeb->getPestana()->conteoSitios()<1){
					Vista::noHistorial();
					system("pause");
				}
				else {
					mostarHistorialPestActual();
					system("pause");
				}
			}
			else
				Vista::noPestanasExistentes();
			system("pause");
			//system("pause");
			//system("cls");
			break;
		case 4:
			marcadores();
			//system("pause");
			//system("cls");
			break;
		case 5:
			importar();
			//system("pause");
			//system("cls");
			break;
		case 6:
			exportar();
			//system("pause");
			//system("cls");
			break;
		case 7:
			configuracion();
			//system("pause");
			//system("cls");
			break;
		case 8:
			exit(0);
			//system("pause");
			//system("cls");
			break;

		
		}


	} while (opc != 9);

}

void Controladora::agregarPestanha(){
	int opc;
	do {
		cout << "==========================================================\n";
		cout << "\n";
		cout << navegadorWeb->mostrarPestana();
		cout << "\n";
		cout << "==========================================================\n";
		cout << "\n";
		Pestana* pes = new Pestana();
		pes->setNumPestana(navegadorWeb->getPestanas().size()+1);
		opc = Vista::subMenuAgregarPestana();
		if (opc == 1 || opc == 2) {
			switch (opc) {
			case 1:
				navegadorWeb->agregarPestana(pes);
				break;
			case 2:
				navegadorWeb->agregarPestana(pes);
				break;
			}
		}
		else
			delete pes;
	} while (opc!=1 && opc!=2);
}

void Controladora::agregarSitioWeb() {
	bool existSite = false;
	std::string URL;
	do {
		cout << "==========================================================\n";
		cout << "\n";
		cout << navegadorWeb->mostrarPestana();
		cout << "\n";
		cout << "==========================================================\n";
		cout << "\n";
		URL = Vista::subMenuAgregarSitio();
		SitioWeb* site = fileMan->checkURL(URL);
		if (site == nullptr) {
			existSite = false;
			delete site;
		}
		else {
			navegadorWeb->getPestana()->insertarSitio(site);
			existSite = true;
		}

		} while (existSite == false);
	}

void Controladora::mostarHistorialPestActual(){
	navegadorWeb->getPestana()->mostrarTodoHistorial();
}



void Controladora::addtoBookMark(){
	std::string tagg = Vista::addBookMark();
	SitioWeb* site = navegadorWeb->getPestana()->getSitioActualPestActual();
	BookMark* bK = new BookMark(site, tagg);
	listaBookmarks->addBookMark(bK);
}

void Controladora::busquedas()
{
}

void Controladora::marcadores()
{
	bool flag = false;
	int opc;
	string tagAux;
	do {
		opc = Vista::menuBookMark();
		switch (opc) {
		case 1:
			addtoBookMark();
			break;
		case 2:
			do{
				tagAux = Vista::buscarBookMark();
				if (listaBookmarks->getBookMark(tagAux) != nullptr) {
					cout << (listaBookmarks->getBookMark(tagAux))->toString();
					flag = true;
				}
				else {
					
					Vista::tagNoExiste();
					
					bool flag = false;
				}
			} while (flag == false);
			break;
		case 3:
			break;
		}

	} while (opc != 3);
	
}

void Controladora::nuevaPestana()
{
	Pestana* pestanaNueva = new Pestana();
	pestanaNueva->setNumPestana((navegadorWeb->getPestanas().size()) + 1);
	navegadorWeb->agregarPestana(pestanaNueva);
	//delete pestanaNueva;
}

void Controladora::Historial()
{
	//FALTA
}

void Controladora::incognito()
{
	if (navegadorWeb->getPestanas().empty()) {
		nuevaPestana();
	}
	this->navegadorWeb->getPestana()->setIncognito(true);
}

void Controladora::exportar()
{
	fileMan->guardarNavegador("navegador.dat");
	fileMan->guardarBookmarks("marcadores.dat");
}

void Controladora::importar()
{
	fileMan->cargarNavegador("navegador.dat");
	fileMan->cargarBookmarks("marcadores.dat");
}

void Controladora::configuracion()
{
	int opc;
	do {
		opc = Vista::configPoliticas();
		switch (opc) {
		case 1:
			limitarEntradas();
			system("pause");
			system("cls");
			break;
		case 2:
			limpiarEntradasViejas();
			system("pause");
			system("cls");
			break;
		case 3:
			break;
		}

	} while (opc != 3);


}

void Controladora::limitarEntradas()
{
	int newLimite = Vista::opc1Politicas();
	this->limiteEntradas = newLimite;

}

void Controladora::limpiarEntradasViejas()
{
	double limiteTiempo = Vista::opc2Politicas();

}

