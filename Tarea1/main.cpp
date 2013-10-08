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
#include <ctime>
#include <fstream>
#include <string.h>



using namespace std;

void acercaDe();
void error();
void integrar(char cadena);
void integrarDesdeHasta(char cadena);

int main(int argc, char** argv)
{
    cout<<"hola mundo";
   if (argc < 1)  //si no tiene parametros imprime la ayuda
    {
      error();
    }
        else
            {

               
                char simbolo = argv[1][0];

                if(simbolo == '-')
                {

                     simbolo = argv[1][1];


                            if(simbolo=='i' && argc==2)
                                 {
                                integrar(argv[2][0]);

                                 }


                            if(simbolo=='g' && argc==4)
                                {
                                
                                    integrarDesdeHasta(); 
                                }


                            if(simbolo=='v')
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
            <<"\t                   Miguel Maraboli Mendez.\n";
           

}
void error(){
            cout<<"\nSin Parametros.\n";


}
void integrar(char cadena){
    

}
void integrarDesdeHasta(char cadena){
    

}
