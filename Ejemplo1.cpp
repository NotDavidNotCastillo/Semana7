#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string nombreArchivo;
    bool encontrado = false;

    cout << "Introduzca el nombre del archivo a abrir: ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo.data(), ios::in);

    if(!archivo){
        cout << "Error. No se pudo abrir el archivo." << endl;
        system("pause");
        return -1;
    } //Verificacion del archivo
        
    // 2. Leer la informacion

    int idCliente = 0;
    char nombre[20], apellido[20];
    double ingreso;

    cout << '\n' 
    << setw(10) << "Codigo"
    << setw(15) << "Nombre"
    << setw(15) << "Apellido"
    << setw(15) << "Ingreso L."
    << fixed << setprecision(2)
    << endl;

    int i=0;
    for (; i<55 ; i++)
        cout << '=';
    
    cout << endl;

    archivo >> idCliente >> nombre >> apellido >> ingreso;

    while (!archivo.eof()){
        cout << setw(10) << idCliente 
        << left << setw(15) << nombre
        << setw(15) << apellido
        << right << setw(15) << ingreso
        << endl;

        archivo >> idCliente >> nombre >> apellido >> ingreso;
    } // End while

    // 3. Close file
    archivo.close();
    
    cout << "\nOperacion finalizada con exito\n\n";

    system("pause");
    return 0;
}