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
    //cout<<"hola mundo"; era para la suerte nomas
    
    
   if (argc <= 1)  //si no tiene parametros imprime la ayuda
    {
      cout<<"error"; 
      error();
    }
        else
            {


                char simbolo = argv[1][0];

                if(simbolo == '-')
                {

                     simbolo = argv[1][1];


                            if(simbolo=='i' &&  argc ==3)
                                 {
                                
                                  cout<<"va a integrar.";
                                  integrar( &argv[2][0]);

                                 }


                            if(simbolo=='g' && argc==5)
                                {
                                int lI,lS;
                                char *cadena;
                               
                                cadena=&argv[3][0];
                                lI=atoi(cadena);
                                cadena=&argv[4][0];
                                lS=atoi(cadena);
                                
                                if(lS<0 || lI<0){
                                  cout<<"\t\nLos limites deben ser mayor o igual a cero"<<endl;    
                                }
                                else{
                                        // integrarDesdeHasta(&argv[2][1],lI,lS);
                                        }
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
void integrar(char* cadena){

    vector <string> monomios;     
    string polinomio = cadena;
    string subcadena;
    int largo,posicion=0;
    do{
        
        
            posicion = polinomio.find('+');
            
            if(posicion !=std::string::npos )
            {
                largo = polinomio.length();
                subcadena = polinomio.substr(0,posicion);
                monomios.push_back(subcadena);
                cout<<subcadena<<endl;
                polinomio = polinomio.substr(posicion+1,largo);
                posicion=0;
            }
        else
            {
                subcadena = polinomio.substr(0,largo);
                monomios.push_back(subcadena);
                cout<<subcadena<<endl;
                largo=0;
            }
            

    //cout<<subcadena<<endl;
    //cout<<polinomio;
    }while(largo!=0);
//Tira un error, pero se que vamos por buen camino, almenos la primera subcadena funciona...

}
    
      

void integrarDesdeHasta(char* cadena,int lI,int lS){
    


}
