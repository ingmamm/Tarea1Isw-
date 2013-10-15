/*
 * File:   main.cpp
 * Author: Samsung
 *
 * Created on 7 de octubre de 2013, 09:35 PM
 */

   /*-----------------------------------------------*
     |     Ingenieria en Software                    |
     |                                               |
     |     Integrantes: Adrian Gutierrez             |
     |                                               |
     |                 Miguel Maraboli Mendez        |
     |                                               |
     |                 Valery Soto Lastra            |
     |                                               |
     *-----------------------------------------------*/

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstring>
#include <cstdlib>



using namespace std;

void acercaDe();
void error();
void integrar(string polinomio);
int getExpo(string polinomio);
float obtenerCoef(string cadena);
int obtenerExp(string cadena);

void integrarDesdeHasta(char* cadena,int lI,int lS);


int main(int argc, char** argv)   
{
    char * cadena = *argv; //Se transfiere a una cadena, para trabajar con nombre generico
    
    
    
    if (argc <= 1)  //si no tiene parametros imprime la ayuda
    {
      cout<<"error"; 
      error();
    }
    else
    {


                char simbolo = cadena[0]; 

                if(simbolo == '-') //comparacion del inicio del comando
                {

                            simbolo = cadena[1];


                            if(simbolo=='i' &&  argc ==3) //verificamos si el comando corresponde a la integral
                            {
                                  
                                  string str = cadena;
                                  int indice = str.find("x"); //se busca la primera x del polinomio como pivote para sacar substring de polinomio
                                  string polinomio= str.substr(indice, str.length()-1);
                                  
                                  cout<<"va a integrar."<<"\n \n";
                                  integrar(polinomio);
                            }

                            if(simbolo=='v'&& argc==2)
                            {
                                
                                     acercaDe();  //procedimiento acerca de
                            }

                }
    }
    return 0;
}



void acercaDe()
{
        time_t tSac = time(NULL);  // instante actual

        struct tm* pt1 = localtime(&tSac);
        cout << "\n\n\t\tHora actual = " << pt1->tm_hour << ":" << pt1->tm_min << ":"
                       << pt1->tm_sec << endl;
        cout << "\t\tFecha actual= " << pt1->tm_mday << "-" << pt1->tm_mon+1 << "-"
                       << pt1->tm_year+1900 << endl;

        cout<< "\n\n\t\tHora de compilacion: " __TIME__<<endl;
        cout<< "\n\t\tFecha de compilacion: " __DATE__<<endl;
        cout<< "\n\t\tVersion de la aplicacion: v1.0"<<endl;
        cout<< "\n\t\tVersion del compilador GCC: " __VERSION__;


        cout<<"\n\n\t\tIntegrantes: Adrian Gutierrez .\n"
            <<"\t\t             Miguel Maraboli Mendez.\n"
            <<"\t\t             Valery Soto Lastra.\n";


}
void error(){
            
    cout<<"\nSin Parametros.\n";


}
void integrar(string polinomio)
{
	string integral;
	int pivote = polinomio.find("+");
        
        string subpoli = polinomio.substr(0,pivote);
        
        cout<< "La funcion "<< polinomio << "integrada es ";
        
	while (pivote != -1)
	{
		float coeficiente = obtenerCoef(subpoli);
		int exponente = obtenerExp(subpoli);
		exponente += 1;
		if (exponente < 0 && coeficiente < 0)
		{
			exponente *= -1 ; coeficiente *= -1;
		}
		cout<< "(" << coeficiente  << "/" << exponente << ")" << "*x^" << exponente ;
                
                if(pivote != -1)
                {
                        string aux = polinomio.substr(pivote,polinomio.length());
                        pivote = aux.find("+");
                        subpoli = aux.substr(0,pivote);
                        cout<< " + ";
                }
	}
        
}

int obtenerExp(string cadena)
{
	string exp ;
        int exponente;
	int posicion= cadena.find("^");
	
	if(posicion !=std::string::npos )
	{
		exp = cadena.substr(posicion+1,cadena.length());
		exponente = atoi(exp.c_str());
	}
	else
        {
		//si no contiene ^ entonces el exponente es 1
		exponente= 1;
        }
        return exponente;
}

float obtenerCoef(string cadena)
{
	string coeficiente;
        float coef;
	int posicion = cadena.find("*");
	if (posicion !=std::string::npos)
	{
		
		coeficiente = cadena.substr(0,posicion);
        
        
        posicion = coeficiente.find("/");
        if(posicion !=std::string::npos) 
        {
            float numerador = atoi(coeficiente.substr(0, posicion).c_str());
            float denominador = atoi(coeficiente.substr(posicion + 1, coeficiente.length()).c_str());
            coef = numerador / denominador;
        }
        else
            coef = atoi(coeficiente.c_str());
	}
	else
	{
		
		
		coef = 1;
	}
        return coef;
}