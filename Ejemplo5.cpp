//Import libraries
#include <cstdlib>
#include <iostream> 
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Definiendo Variables necesarias

string nombre, auxnombre, semestre, edad, auxsemestre, auxedad;
int clave=0, auxclave=0;
char grupo[10], auxgrupo[10];
char opca;
bool encontrado = false;

void altas(){
    //Variables de biblioteca fstream para el manejo de archivos
    ofstream escritura;
    ifstream consulta;

    do{
        escritura.open("alumnos.txt",ios::out | ios::app);
        consulta.open("alumnos.txt",ios::in);
        
        if(escritura.is_open() && consulta.is_open()){
            bool repetido = false;

            cout << "\n";
            cout << "\tIngresa la clave del alumno: ";
            cin >> auxclave;

            consulta >> clave;

            while(!consulta.eof()){
                consulta >> nombre >> semestre >> grupo >> edad; 
                if (auxclave == clave){
                    cout << "\t\tYa existe la clave del alumno...\n";
                    repetido = true;
                    break;
                }
                consulta >> clave;
            }

            if (repetido == false){
                cout << "\tIngresa el nombre del alumno:   ";
                cin >> nombre;
                
                cout << "\tIngresa el semestre del alumno:   ";
                cin >> semestre;

                cout << "\tIngresa el grupo del alumno:   ";
                cin >> grupo;

                cout << "\tIngresa la edad del alumno:   ";
                cin >> edad;

                //Escribiendo los datos capturados por el usuario

                escritura << auxclave << " " << nombre << " " <<
                            semestre << " " << grupo << " " <<
                            edad << " " << endl;
                cout << "\n\tRegistro agregado...\n";
            }

            cout << "\n\tDeseas ingresar otro alumno? (s/n):";
            cin >> opca;

        } else {
            cout << "El archivo no se pudo abrir.\n";
        }

        escritura.close();
        consulta.close();
    } while (opca == 'S' or opca =='s');
    
}

void bajas(){
    ofstream aux;
    ifstream lectura;

    encontrado = false;

    aux.open("auxiliar.txt" , ios::out);
    lectura.open("alumnos.txt",ios::in);

    if(aux.is_open() && lectura.is_open()){
        cout << "\n";
        cout << "\tIngresa la clave del alumno que deseas eliminar: ";
        cin >> auxclave;

        lectura >> clave;

        while (!lectura.eof()){
            lectura >> nombre >> semestre >> grupo >> edad ;

            if ( auxclave == clave){
                encontrado = true;

                cout << "\n";
                cout << "\tClave:   " << clave << endl;
                cout << "\tNombre:  " << nombre << endl;
                cout << "\tSemestre:    "<< semestre << endl;
                cout << "\tGrupo:   "<< grupo << endl;
                cout << "\tEdad:    "<< edad << endl;
                cout << "\t_______________________________________\n";
                cout << "\tRealmente desea eliminar el registro actual? (s/n)"<<endl;
                cin >> opca;

                if(opca == 's' || opca == 'S'){
                    cout << "\n\n\t\t\tRegistro eliminado..." << endl;
                } else {
                    aux << clave << " " << nombre << " " << semestre << " "
                        << grupo << " " << edad << endl;
                }

            } else {
                aux << clave << " " << nombre << " " << semestre << " "
                    << grupo << " " << edad << endl;
            }
            lectura >> clave;
        }
    } else {
        cout << "\n\tEl archivo no se pudo abrir \n";
    }

    if (encontrado == false)    {
        cout << "\n\tNo se encontro ningun registro con la clave..." << endl;
    }

    aux.close();
    lectura.close();

    remove("alumnos.txt");
    rename ("auxiliar.txt", "alumnos.txt");
}

void consultas(){
    //Lectura de archivos
    ifstream lectura;
    lectura.open("alumnos.txt",ios::out | ios::in);
    if(lectura.is_open()){
        //Leyendo y mostrando cada campo del archivo
        lectura >> clave;
        while (!lectura.eof()){
            lectura >> nombre >> semestre 
                    >> grupo >> edad ;
            cout << "\n";
            cout << "\tClave:   " << clave << endl;
            cout << "\tNombre:   " << nombre << endl;
            cout << "\tSemestre:   " << semestre << endl;
            cout << "\tGrupo:   " << grupo << endl;
            cout << "\tEdad:   " << edad << endl;
            lectura >> clave;
            cout << "\t_____________________\n";
        }   
    } else {
        cout << "El archivo no se pudo abrir\n";
    }
    lectura.close();
}

void buscar(){
    ifstream lectura; 
    lectura.open("alumnos.txt",ios::out | ios::in);

    encontrado = false;

    if (lectura.is_open()){
        cout << "\n\tIngresa la clave del alumno que busca: ";
        cin >> auxclave;

        lectura >> clave;

        while (!lectura.eof()){
            lectura >> nombre >> semestre 
                    >> grupo >> edad;
            //Comparar cada registro para ver si es encontrado

            if( auxclave == clave ){
                cout << "\n";
                cout << "\tClave:   " << clave << endl;
                cout << "\tNombre:   " << nombre << endl;
                cout << "\tSemestre:   " << semestre << endl;
                cout << "\tGrupo:   " << grupo << endl;
                cout << "\tEdad:   " << edad << endl;
                cout << "\n\t _____________________________\n";
                encontrado = true;
                break;
            }//Fin if
            lectura >> clave;
        } // fin while
        if(encontrado == false){
            cout << "\n\n\tNo hay registros con la clave: " << auxclave 
            << "\n" << endl;
        }
    } else {
        cout << "\n\tAun no se pudo abrir el archivo..." << endl;
    }
    lectura.close();
}

void modificar(){
    ofstream aux;
    ifstream lectura;

    encontrado = false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if(aux.is_open () && lectura.is_open()){
        cout << "\n\tIngresa la clave del alumno que deseas modificar: ";
        cin >> auxclave;
        
        lectura >> clave;
        while (!lectura.eof()){
            lectura >> nombre >> semestre >> grupo >> edad;
            if(auxclave == clave){
                cout << "\n";
                cout << "\tClave:   " << clave << endl;
                cout << "\tNombre:   " << nombre << endl;
                cout << "\tSemestre:   " << semestre << endl;
                cout << "\tGrupo:   " << grupo << endl;
                cout << "\tEdad:   " << edad << endl;

                cout << "\tIngresa de nuevo el nombre del alumno: ";
                cin >> auxnombre;

                cout << "\tIngresa de nuevo el semestre del alumno: ";
                cin >> auxsemestre;

                cout << "\tIngresa de nuevo el grupo del alumno: ";
                cin >> auxgrupo;

                cout << "\tIngresa de neuvo la edad del alumno: ";
                cin >> auxedad;


                aux << clave << " " << auxnombre << " " << auxsemestre << " "
                        << auxgrupo << " " << auxedad << endl;

                encontrado = true;
                cout << "\n\n\t\t\tRegistro modificado...\n\t\t";
            }else{
                aux << clave << " " << nombre << " " << semestre << " "
                        << grupo << " " << edad << endl;
            }
            lectura >> clave;
        }
    } else {
        cout << "\n\tEl archivo no se pudo abrir.\n";
    }
    if (encontrado == false)
    {
        cout << "\n\tNo se encontro ningun registro con la clave\n\n";
    }

    aux.close();
    lectura.close();
    remove("alumnos.txt");
    rename("auxiliar.txt","alumnos.txt");
}

int main() {
    int opc;
    do {
        cout << "Que desea hacer?:\n";
        cout << "1. Agregar alumnos.\n";
        cout << "2. Eliminar alumnos.\n";
        cout << "3. Consultar registros.\n";
        cout << "4. Buscar alumno (con clave).\n";
        cout << "5. Modificar registro.\n";
        cout << "6. Salir\n";
        cin >> opc;

        switch(opc) {
            case 1: 
                altas(); 
                break;
            case 2: 
                bajas(); 
                break;
            case 3: 
                consultas(); 
                break;
            case 4: 
                buscar(); 
                break;
            case 5: 
                modificar(); 
                break;
            case 6: 
                cout << "Saliendo...\n"; 
                break;
            default: 
                cout << "Esa opcion no existe\n"; 
                break;
        }
    } while(opc != 6);

    return 0;
}
