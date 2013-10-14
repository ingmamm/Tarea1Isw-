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
void integrar(char* cadena);
void integrarDesdeHasta(char* cadena,int lI,int lS);


int main(int argc, char** argv)       ///argv[0][0] argv[1][0] argv[2][0]
{
    char * cadena = *argv;
    
    
    
    if (argc <= 1)  //si no tiene parametros imprime la ayuda
    {
      cout<<"error"; 
      error();
    }
    else
    {


                char simbolo = cadena[0];

                if(simbolo == '-')
                {

                            simbolo = cadena[1];


                            if(simbolo=='i' &&  argc ==3)
                            {
                                  
                                  string str = cadena;
                                  int indice = str.find("x");
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
void integrar(string funcion)
{
	stringstream result;
	int pos = funcion.find('x');
	if(pos < funcion.length())
	{
		float cons = getCons(funcion);
		int expo = getExpo(funcion);
		expo += 1;
		if (expo < 0 && cons < 0)
		{
			expo *= -1 ; cons *= -1;
		}
		result << cons <<"/" << expo <<"*x^" << expo ;
	}
	else
		result << atoi(funcion.c_str()) << "*x";
	
        cout<< "La funcion "<< funcion << "integrada es " << result.str();
        
}

int getExpo(string polinomio)
{
	string expo = "";
	int pos= polinomio.find("^");
	//se busca el ^, de ah� en adelante ser� el n�mero del exponente
	if(pos < polinomio.length())
	{
		expo = polinomio.substr(pos+1,polinomio.length());
		return atoi(expo.c_str());
	}
	else
		//si no contiene ^ entonces el exponente es 1
		return 1;
}

float getCons(string polinomio)
{
	string cons;
	int pos = polinomio.find("*");
	if (pos < polinomio.length())
	{
		//se obtiene el substring desde el inicio hasta donde llega el por
		// 123412*x...
		cons = polinomio.substr(0,pos);
        
        // Ahora compruebo si hay un /, indicando una division
        pos = cons.find("/");
        if(pos < cons.length()) // Encontre una division, realizarla!
        {
            float numerador = atoi(cons.substr(0, pos).c_str());
            int denominador = atoi(cons.substr(pos + 1, cons.length()).c_str());
            return numerador / denominador;
        }
        else
            return atoi(cons.c_str());
	}
	else
	{
		//puede que sea x^i o -x^i,  hay que capturar el - si fuera negativo
		if (polinomio[0] == '-')
			return -1;
		return 1;
	}
}