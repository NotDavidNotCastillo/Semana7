#include <iostream>
#include <fstream>
#include <string>
// INTERCAMBIO DE DATOS
using namespace std;

int main() {
    // Procesos con archivos
    // Abrir archivo
    string nombreArchivo;

    cout << "Introduzca el nombre del archivo a crear: ";
    cin >> nombreArchivo;

    ofstream archivo(nombreArchivo.c_str(), ios::out | ios::app);

    if (!archivo) {
        cout << "Error, no se pudo abrir el archivo " << endl;
        return -1;
    } // verificacion del archivo

    // Guardar la información
    int idCliente = 0;
    string nombre, apellido;
    double ingreso;

    cout << "Intro. id cliente (0 para terminar): ";
    cin >> idCliente;

    while (idCliente > 0) {
        cout << "Introduce nombre: ";
        cin >> nombre;
        cout << "Introduce apellido: ";
        cin >> apellido;
        cout << "Introduce ingreso: ";
        cin >> ingreso;

        // Guardar datos en archivo
        archivo << idCliente << " "
                << nombre << " "
                << apellido << " "
                << ingreso << endl;

        cout << "Intro. id cliente (0 para terminar): ";
        cin >> idCliente;
    } // fin while

    // Cerrar archivo
    archivo.close();

    cout << "\nOperación finalizada con éxito.\n\n";

    return 0;
} // Fin del main
