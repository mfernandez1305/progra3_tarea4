#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Trabajo en grupo realizado con Maynor Morales, Iveth Sabillon, Kevin Lanza
//Tomadas algunas anotaciones de http://informatica.uv.es/iiguia/AED/oldwww/2004_05/AED.Tema.07.pdf
//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
      //Tomando ejemplo de http://jsbsan.blogspot.com/2012/01/c-ejemplo-de-guardar-texto-en-un.html
ofstream out(nombre_archivo.c_str());//
out<<num<<endl;//se escribe en el archivo
out.close();//cierra el archivo

}
int leerNumeroTexto(string nombre_archivo)
{
    ifstream archivo (nombre_archivo.c_str());//lee los datos del archivo
    int numero;//se declara la variable numero
    archivo>>numero;//se lee la variable

    return numero;//se devuelve la varible numero
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    //Tomando ejemplo de http://jsbsan.blogspot.com/2012/01/c-ejemplo-de-guardar-texto-en-un.html
    ofstream out(nombre_archivo.c_str());//se escribe el archivo
    out<<str<<endl;//escribe la variable en el archivo
    out.close();//cierra el archivo
}
string leerStringTexto(string nombre_archivo)
{

    ifstream in (nombre_archivo.c_str());//lee el archivo
    string str;//se declara la variable
    in>>str;//se lee la variable

    return str;//se devuelve la variable
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
    //Tomado de explicacion en clase https://github.com/Ceutec/ArchivosBinarios/blob/master/main.cpp
    //y  http://informatica.uv.es/iiguia/AED/oldwww/2004_05/AED.Tema.07.pdf
    // Seccion 7.7
    ofstream out (nombre_archivo.c_str());

    out.write((char *)&num,4);//se la variable num en el archivo
    out.close();//se cierra el archivo
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//lee el archivo
    int num;//se declara la variable
    in.read((char*)&num,4);//se lee el archivo y se convierte la variable int a un char apuntador

    return num;//se devuelve la variable leida
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream out (nombre_archivo.c_str());//se escribe el archivo
    out.write(str.c_str(),4);//se escribe la variable str en el archivo
    out.close();//se cierra el archivo
    //ayuda obtenida de: http://www.cplusplus.com/forum/general/100714/

}
string leerStringBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//se lee el archivo

    char leido[4];//se declara la variable enviandole un parametro
    in.read(leido,4);// se lee la variable char

    return leido; // se devuelve la variable leido

}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{

    ifstream in(nombre_archivo.c_str());//Se lee el archivo
    string palabra;//se declara la variable para luego compararla
    int cant;//se declara la variable int para el limite del ciclo

    for(int i=0;i < cant;i++)//se inicia el ciclo para comparar las palabras
    {
        in>>palabra;//se ingresa la variable para evaluar
        if(palabra == str)//se evalua la comparacion
        {
            return true;//Si la condicion en verdadera devuelve true
        }
    }
    return false;
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{

    //ejercicio que hicimos en clase
    ifstream in(nombre.c_str());//se lee el archivo
    in.seekg(0,ios::end);//se busca la posicion en el archivo
    int tamano = in.tellg();//se declara la variable
    in.seekg(0,ios::beg);

    int mayor = -999;//se declara la variable en la que se asigna el numero mayor
    while(in.tellg()<tamano)//se inicia el ciclo
    {
        int num;//se declara la variable numero
        in.read((char*)&num,4);//se lee la variable
        if(mayor<num)//se evalua si la variable num es mayor que  la variable mayor
            mayor = num;// se igualan las variables
    }
    return mayor;//se devuelve la variable mayor
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
