#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //Processo con archivos
    //1. Abrir
    string nombreArchivo;
    bool encontrado = false;

    cout << "Introduzca el nombre del archivo: ";
    cin >> nombreArchivo;

    ifstream archivo( nombreArchivo.data(), ios::in );

    if(!archivo){
        cout << "Error.\n No se pudo encontrar/abrir el archivo." << endl;
        system("pause");
        return -1;
    }// Verifamos el archivo

    // 2. leemos la informacion
    int idCliente=0, idBuscar=0;
    char nombre[20], apellido[20];
    double ingreso;

    cout << "Buscar cliente.\nID: ";
    cin >> idBuscar;

    cout<< '\n' 
    << setw(10) << "Codigo"
    << setw(15) << "Nombre"
    << setw(15) << "Apellido"
    << setw(15) << "Ingreso L."
    << fixed << setprecision(2) << endl;
    
    int i=0;
    for(; i<55 ; i++)
        cout << '=';
    cout << endl;

    archivo >> idCliente >> nombre >> apellido >> ingreso;

    while(!archivo.eof()){
        if(idCliente == idBuscar){
            encontrado = true;
            cout << setw(10) << idCliente
            << left << setw(15) << nombre
            << setw(15) << apellido
            << right << setw(15) << ingreso
            << endl;
        }

        archivo >> idCliente 
                >> nombre
                >> apellido
                >> ingreso;
    } // Fin de while

    if(!encontrado){
        cout << "Cliente no encontrado...\n";
    }

    // 3. Cerrar
    cout<< "\nOperacion Finalizada con exito \n\n";

    system("pause");
    return 0;
}