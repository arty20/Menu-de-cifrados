#include <iostream> 
#include <string.h> 
#include <cmath> 
#include <fstream>
#include <sstream>
using namespace std;


//Cifrado cesar
void Cesar(char Archivo[100]) 
{ 
	int n,i;
		char cadena[128];
        // Crea un fichero de salida
        fstream fs ("cesar.txt"); 
		cout<<"Cifrado Cesar"<<endl;
			fs.close();	
		// Lee el fichero	
  		fstream fe("cesar.txt");
  		// Crea un fichero de salida
  		ofstream fa ("cesar2.txt");
		cout << "Introduce el numero de desplazamiento deseado" << endl; 
   		cin >> n; 
  		fe.getline(Archivo,100);
    for (int i = 0; i < Archivo[i]; i++) { 
        if (Archivo[i] >= 'a' && Archivo[i] <= 'z') { 
            if (Archivo[i] + n > 'z') { 
                Archivo[i] = 'a' - 'z' + Archivo[i] + n - 1; 
                fa<<Archivo[i];
            } else if (Archivo[i] + n < 'a') { 
                Archivo[i] = 'z' - 'a' + Archivo[i] + n + 1; 
            } else { 
                Archivo[i] += n; 
                fa<<Archivo[i];
            } 
        } else if (Archivo[i] >= 'A' && Archivo[i] <= 'Z') { 
            if (Archivo[i] + n > 'Z') { 
                Archivo[i] = 'A' - 'Z' + Archivo[i] + n - 1; 
                fa<<Archivo[i];
            } else if (Archivo[i] + n < 'A') { 
                Archivo[i] = 'Z' - 'A' + Archivo[i] + n + 1;
				fa<<Archivo[i]; 
            } else { 
                Archivo[i] += n; 
                fa<<Archivo[i];
            } 
        } 
    } 
    
} 
//Funcion descodificar Cifrado Cesar
void desC(char Archivo[100]) 
{ 
		int n,i;
		char cadena[128];
        
		// Leer el fichero	
  		fstream fe("cesar2.txt");
  		// Crea un fichero de salida
  		ofstream fa ("cesar3.txt");
		cout << "Introduce el numero de casillas a retroceder" << endl; 
   		cin >> n; 
  		fe.getline(Archivo,100);
    for (int i = 0; i < Archivo[i]; i++) { 
        if (Archivo[i] >= 'a' && Archivo[i] <= 'z') { //Rango de minusculas 
            if (Archivo[i] - n > 'z') { 
                Archivo[i] = 'a' + 'z' - Archivo[i] - n +1; 
                fa<<Archivo[i];
            } else if (Archivo[i] - n < 'a') { 
                Archivo[i] = 'z' + 'a' - Archivo[i] - n +1; 
                fa<<Archivo[i];
            } else { 
                Archivo[i] -= n; 
                fa<<Archivo[i];
            } 
        } else if (Archivo[i] >= 'A' && Archivo[i] <= 'Z') { //Rango de Mayusculas
            if (Archivo[i] - n > 'Z') { 
                Archivo[i] = 'A' + 'Z' - Archivo[i] - n + 1; 
                 fa<<Archivo[i];
            } else if (Archivo[i] - n < 'A') { 
                Archivo[i] = 'Z' + 'A' - Archivo[i] - n + 1; 
                 fa<<Archivo[i];
            } else { 
                Archivo[i] -= n; 
                fa<<Archivo[i];
            } 
        } 
    } 
	
  	
  	
  	
} 



//Declaramos nuestro metodo que nos permitira codificar  en codigo ascci el mensaje que tenga escrito un fichero
//pasandole como parametro un arreglo de tipo char.
void CodiAscci(char Archivo[200])

{
	//Mediante esta linea de codigo seleccionamos el fichero que deseamos codificar
	
	ifstream fs("Prueba.txt");
	//Creamos un fichero nuevo que por el momento no contiene informacion alguna
	ofstream fa("Prueba2.txt");
	
  	// Accedemos al contenido del archivo que hemos seleccionado y almacenamos su contenido en el arreglo que 
  	//definimos al comienzo de este metodo
  	fs.getline(Archivo,200);
  	
  	//Esta es una simple imprecion en pantalla del arreglo que ya hemos definido 
  	//y el cual al ejecutar el programa nos arrojara el mensaje original puesto que aun no lo hemos codificado.
  	cout<<Archivo<<endl<<endl<<endl;
  	
  	
  	//Mediante este bucle recorreremos coda una de las posiciones de nuestro arreglo con la finalidad
  	//de poder acceder a cada uno de los caracteres que se encuantran alojados en el arreglo
  	for(int i=0;Archivo[i]!=0;i++)
  	{
  		   
  		   //Realizamos una conversion de los caracteres que se encuentran alojados en las posiciones de nuestro arreglo 
  		   //a su valor numerico para enmascarar el contenido original del mensaje
  		   //al mismo tiempo realizamos una impresion en pantalla ya con el mensaje codificado.
  		   cout<<int (Archivo[i])<<" ";	   
  		   
  		   //Utilizamos el objeto que creo el otro fichero y le asignamos el arreglo con el mensaje codificado 
  		   //permitiendonos guardar el nuevo contenido en el nuevo  documento para no afectar el archivo  original.
		   fa<<int(Archivo[i])<<" ";
		   
  	}
  	//cerramos el documento que creamos con su informacion guardada.
  	fa.close();
  	
}


//Declaramos el metodo para codificar el mensaje de un documento txt a clave morse 
void CodiMorse(char Archivo[200])
{
	// creamos un objeto de tipo ifstream y pasamos como parametros el nombre
	//archivo que vamos a codificar.
	ifstream fs("Prueba.txt");
	//Creamos un nuevo fichero
	ofstream fa("Prueba3.txt");
	fs.getline(Archivo,200);
    
	
	cout<<Archivo<<endl<<endl<<endl;
	
	for(int i = 0; Archivo[i] != 0;i++)
   {
       //Con esta sentencia hacemos la comparacion de lo que tiene nuestro arreglo si 
	   //coinciden los valores imprimimos la asignacion en clave morse.	
      
       switch (Archivo[i])
       {
       	 case 48://0
       		cout<<"-----"<<" ";
       		fa<<"-----"<<" ";
       	    	break;
       	 case 49://1
		   cout<<".----"<<" ";
		   fa<<".----"<<" ";
		      break;
		  case 50://2
		  cout<<"..---"<<" ";
		   fa<<"..---"<<" ";
		      break;
		 case 51://3
		  cout<<"...--"<<" ";
		  fa<<"...--"<<" ";
		       break;
		 case 52://4
		  cout<<"....-"<<" ";
		  fa<<"....-"<<" ";
		       break;
		 case 53://5
		  cout<<"....."<<" ";
		  fa<<"....."<<" ";
		        break;
		  case 54://6
		  cout<<"-...."<<" ";
		  fa<<"-...."<<" ";
		        break;
		    case 55://7
			cout<<"--... ";
			fa<<"--... ";
		    	break;
		   case 56://8
			  cout<<"---.. ";
			  fa<<"---.. ";
			      break;
		    case 57://9
		      cout<<"----. ";
			  fa<<"----. ";
			       break;	
		    
		     case 65: case 97:
               
               cout<<".-"<<" ";
               fa<< ".-"<<" ";//A
           // cin>>Archivo[i];
               
                   break;
                  
           case 66: case 98:
               
              cout<< "-..."<<" ";//B
               fa<< "-..."<<" ";
               break;
          
           case 67: case 99:
               
              cout<< "-.-."<<" ";//C
              fa<< "-.-."<<" ";
               break;
          
           case 68: case 100:
          
               cout<< "-.."<<" ";//D
               fa<< "-.."<<" ";
               break;
          
           case 69:  case 101:
          
               cout<< "."<<" ";//E
               fa<< "."<<" ";
               break;
          
           case 70: case 102:
          
               cout<<"..-."<<" ";//F
               fa<<"..-."<<" ";
               break;
          
           case 71: case 103:
          
             cout<< "--."<<" ";//G
               fa<< "--."<<" ";
               break;
          
           case 72: case 104:
          
               cout<< "...."<<" ";//H
               fa<< "...."<<" ";
               break;
          
           case 73: case 105:
          
               cout<< ".."<<" ";//I
                fa<< ".."<<" ";
               break;
          
           case 74: case 106:
          
               cout<< ".---"<<" ";//J
              fa<< ".---"<<" ";
               break;
          
           case 75: case 107:
               
               cout<< "-.-"<<" ";//K
               fa<< "-.-"<<" ";
               break;
          
           case 76: case 108:
          
               cout<< ".-.."<<" ";//L
               fa<< ".-.."<<" ";
               break;
          
           case 77: case 109:
          
              cout<< "--"<<" ";//M
               fa<< "--"<<" ";
               break;
          
           case 78: case 110:
          
               cout<< "-."<<" ";//N
              fa<< "-."<<" ";
               break;
          
           case 79: case 111:
          
               cout<< "---"<<" ";//O
               fa<< "---"<<" ";
               break;
          
           case 80: case 112:
          
               cout<< ".--."<<" ";//P 
               fa<< ".--."<<" ";
               break;
          
           case 81: case 113:
          
               cout<< "--.-"<<" ";//Q
               fa<< "--.-"<<" ";
               break;
          
           case 82: case 114:
          
               cout<< ".-. "<<" ";//R
               fa<< ".-. "<<" ";
               break;
          
           case 83: case 115:
          
               cout<< "..."<<" ";//S
               fa<< "..."<<" ";
               break;
          
           case 84: case 116:
          
               cout<< "-"<<" ";//T
              fa<< "-"<<" ";
               break;
          
           case 85: case 117:
          
               cout<< "..-"<<" ";//U
               fa<< "..-"<<" ";
               break;
          
           case 86: case 118:
          
               cout<< "...-"<<" ";//V
               fa<< "...-"<<" ";
               break;
          
           case 87: case 119:
          
               cout<< ".--"<<" ";//W
               fa<< ".--"<<" ";
               break;
          
           case 88: case 120:
          
               cout<< "-..-"<<" ";//X
               fa<< "-..-"<<" ";
               break;
          
           case 89: case 121:
          
               cout<< "-.--"<<" ";//Y
               fa<< "-.--"<<" ";
               break;
                           
           case 90: case 122:
          
               cout<< "--.."<<" ";//Z
               fa<< "--.."<<" ";
               break;
            default:
               cout<<" ";
               
               break;
   
		 cout<<" "; 
          
        
       }
   
}
//cerramos el nuevo fichero codificado en clave morse
fa.close();
}


//Metodo de decodificacion clave morse
void Dec(char Archivo[200])
{
	//Seleccionamos el Fichero con e mensaje codificado
	ifstream f("Prueba3.txt");
	//obtenemos el contenido y lo almacenamos en un arreglo
	f.getline(Archivo,200);
	//imprimimos el contenido del arreglo y nos muestra el mensaje codificado
	cout<<Archivo<<endl;
	//Nos sirve para llevar una secuencia de caracteres
 string e;
 //instringstream es una clase de secuencia de entrada para operar en cadenas de texto
 //le pasamos como parametro nuestro arreglo 
 istringstream i(Archivo);
 
//declaramos un ciclo mientras para obtener los caracteres de nuestro arreglo
 while ( getline(i, e, ' ') ){
 	//Comparamos la cadena con la funcion strcmp para determinar si hay un caracter parecido
   //y con la funcion c_str nos devuelve un puntero en el arreglo para determinar donde se encontro la coincidencia
   // cuando el valor llega a nulo imprime en la posicion de señalo el puntero el caracter que le hemos designado.  
  if(strcmp(e.c_str(),".-")== 0)
   cout << "A"<<" ";
  else if(strcmp(e.c_str(),"-...")== 0)
   cout << "B"<<" ";
  else if(strcmp(e.c_str(),"-.-.")== 0)
   cout << "C"<<" ";
  else if(strcmp(e.c_str(),"-..")== 0)
   cout << "D"<<" ";
  else if(strcmp(e.c_str(),".")== 0)
   cout << "E"<<" ";
  else if(strcmp(e.c_str(),"..-.")== 0)
   cout << "F"<<" ";
  else if(strcmp(e.c_str(),"--.")== 0)
   cout << "G"<<" ";
  else if(strcmp(e.c_str(),"....")== 0)
   cout << "H"<<" ";
  else if(strcmp(e.c_str(),"..")== 0)
   cout << "I"<<" ";
  else if(strcmp(e.c_str(),".---")== 0)
   cout << "J"<<" ";
  else if(strcmp(e.c_str(),"-.-")== 0)
   cout << "K"<<" ";
  else if(strcmp(e.c_str(),".-..")== 0)
   cout << "L"<<" ";
  else if(strcmp(e.c_str(),"--")== 0)
   cout << "M"<<" ";
  else if(strcmp(e.c_str(),"-.")== 0)
   cout << "N"<<" ";
  else if(strcmp(e.c_str(),"---")== 0)
   cout << "O"<<" ";
  else if(strcmp(e.c_str(),".--.")== 0)
   cout << "P"<<" ";
  else if(strcmp(e.c_str(),"--.-")== 0)
   cout << "Q"<<" ";
  else if(strcmp(e.c_str(),".-.")== 0)
   cout << "R"<<" ";
  else if(strcmp(e.c_str(),"...")== 0)
   cout << "S"<<" ";
  else if(strcmp(e.c_str(),"-")== 0)
   cout << "T"<<" ";
  else if(strcmp(e.c_str(),"..-")== 0)
   cout << "U"<<" ";
  else if(strcmp(e.c_str(),"...-")== 0)
   cout << "V"<<" ";
  else if(strcmp(e.c_str(),".--")== 0)
   cout << "W"<<" ";   
  else if(strcmp(e.c_str(),"-..-")== 0)
   cout << "X"<<" ";
  else if(strcmp(e.c_str(),"-.--")== 0)
   cout << "Y"<<" ";
  else if(strcmp(e.c_str(),"--..")== 0)
   cout << "Z"<<" ";  
   else if(strcmp(e.c_str(),"-----")==0)
   cout <<"0"<<" ";
   else if(strcmp(e.c_str(),".----")==0)
   cout <<"1"<<" ";
    
   else if(strcmp(e.c_str(),"..---")==0)
   cout <<"2"<<" "; 
   else if(strcmp(e.c_str(),"...--")==0)
   cout <<"3"<<" "; 
   else if(strcmp(e.c_str(),"....-")==0)
   cout <<"4"<<" "; 
   else if(strcmp(e.c_str(),".....")==0)
   cout <<"5"<<" ";
   else if(strcmp(e.c_str(),"-....")==0)
   cout <<"6"<<" ";
   else if(strcmp(e.c_str(),"--...")==0)
   cout <<"7"<<" ";
   else if(strcmp(e.c_str(),"---..")==0)
   cout <<"8"<<" ";
   else if(strcmp(e.c_str(),"----.")==0)
   cout <<"9"<<" ";
     
 }
 
}



void Prueba(int Archivo1[200])
{
int c;
	
	cout<<"Ingresa la palabra"<<" ";
	

	
	for(int i=0;i<200;i++)
	{
		
		cin>>c;
		Archivo1[i]=c;
		cout<<char(Archivo1[i])<<" ";
	}	
}



//Metodo principal
int main (){
	int Archivo1[200];
	char Archivo[200];
	int op;
	do{
	
		char Archivo[100];
		cout<<"Cifrado"<<endl;
		cout<<"1.Cesar"<<endl;
		cout<<"2.Decifrar Cesar"<<endl;
		cout<<"Codificacion"<<endl;
		cout<<"3.ASCII"<<endl;
		cout<<"4.Decifrar ASCII"<<endl;
		cout<<"5.Morse"<<endl;
		cout<<"6.Decifrar Morse"<<endl;
		cout<<"7.Salir"<<endl;
		cout<<"Elige la opcion deseada"<<endl;
	    cout<<"\n"<<"\n";
		cin>>op;
		cout<<"\n";
	 
		switch(op)
		{
			case 1:
				Cesar(Archivo);
  			break;
  		
			case 2:
				desC(Archivo);
			break;
			case 3:
				CodiAscci(Archivo);
				break;
			case 4:
			    Prueba(Archivo1);
			    
				break;
			case 5:
			   CodiMorse(Archivo);
			   break;
			case 6:
			    Dec(Archivo);
				break;   		
            case 7:
            	cout<<"Adios :)";
            	break;

	}
	cout<<"\n"<<"\n";
	}while(op!=7);
}



