#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>

using namespace std;

fstream archivo;

void menuSuma();
void menuResta();
void menuMultiplicacion();
void menuDivision();
void menuCalculadora();
void menuPrincipal();
void conversorNumerico();
void conversorMetrico();
void conversorMasas();
void conversorTemperaturas();
void conversorMonedas();
void potencia();
void factorial();
void metros();
void kilometros();
void millas();
void pulgadas();
void pies();
void gramos();
void kilogramos();
void libras();
void celsius();
void fahrenheit();
void kelvin();
void colon();
void dolar();
void euro();
void leerArchivo();
void escribirArchivo(string dato);
void DaB();
void BaD();
void DaC2();
void C2aD();
void DaI();
void IaD();
void horaSistema();
string Convert (float number);
float auxIEEE(string num1);
float auxBinADec(string num1);

void menuPrincipal(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Menu Principal <<-------" << endl;
  cout << endl <<"Opciones: ";
  cout << endl <<"1. Hora";
  cout << endl <<"2. Operaciones aritmeticas";
  cout << endl <<"3. Conversor Numérico";
  cout << endl <<"4. Conversor Metrico"; 
  cout << endl <<"5. Conversor Masas"; 
  cout << endl <<"6. Conversor Temperaturas"; 
  cout << endl <<"7. Conversor de divisas"; 
  cout << endl <<"8. Salir";
  cout << endl <<"Opcion: ";
  cin >> x;
  
  if(x == '1'){
    horaSistema();
  }
  else if(x == '2'){
    menuCalculadora();
  }
  else if(x == '3'){
    conversorNumerico();
  }
  else if(x == '4'){
    conversorMetrico();
  }
  else  if(x == '5'){
    conversorMasas();
  }
  else  if(x == '6'){
    conversorTemperaturas();
  }
  else  if(x == '7'){
    conversorMonedas();
  }
  else if(x == '8'){
    exit(1);
  }
  else {
    menuPrincipal();
  }
}

void horaSistema(){
  system("clear");
  char y;
  cout << endl <<"------->> Hora del sistema <<-------" << endl; 
  time_t t;
  time(&t);
  cout << "La Hora del Sistema es: " <<ctime(&t);

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna a la hora del sistema"; 
  cout << endl <<"Opcion: ";
  cin >> y;

  if (y == 'E'){
    menuPrincipal();
  }
  else{
    horaSistema();
  }
}

void menuCalculadora(){
    system("clear");
  char x = '0';
  cout << endl <<"------->> Operaciones aritmeticas <<-------" << endl;
  cout << endl <<"Opciones: ";
  cout << endl <<"1. SUMA";
  cout << endl <<"2. RESTA";
  cout << endl <<"3. MULTIPLICACION";
  cout << endl <<"4. DIVISION";
  cout << endl <<"5. POTENCIA";
  cout << endl <<"6. FACTORIAL";
  cout << endl <<"7. Menu Principal"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if(x == '1'){
    menuSuma();
  }
  else if(x == '2'){
    menuResta();
  }

  else if(x == '3'){
    menuMultiplicacion();
  }

  else if(x == '4'){
    menuDivision();
  }
  else if(x == '5'){
    potencia();
  }
  else if(x == '6'){
    factorial();
  }
  else if(x == '7'){
    menuPrincipal();
  }
  else{
    menuCalculadora();
  }
}

void potencia(){
  system("clear");
  float aux, num1, resultado, x, uno = 1;
  char y = '1';
  
  cout << endl <<"------->> Potencia <<-------" << endl;
  cout << endl <<"Digite el numero base: ";
  cin >> num1;

  cout << endl <<"Digite la potencia: ";
  cin >> x;
  
  aux = num1;
  while (x > 1){
    __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (aux)) ;
    num1 = resultado;
    __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (x) : "m" (x), "m" (uno));
  }
  cout << endl <<"El resultado de la potencia es: " <<resultado;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar a las Operaciones aritmeticas ";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al operando de potencias"; 
  cout << endl <<"Opcion: ";
  cin >> y;

  if (y == 'Q'){
    menuCalculadora();
  } 
  else if (y == 'E'){
    menuPrincipal();
  }
  else{
    potencia();
  }
}

void factorial(){
  system("clear");
  float aux, num1, resultado, x = 0, uno = 1;
  char y = '1';

  cout << endl <<"------->> Factorial <<-------" << endl;
  cout << endl <<"Digite el numero: ";
  cin >> num1;

  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (x) : "m" (num1), "m" (uno));
  while (x > 1){
    __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (x )) ;
    num1 = resultado;
    __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (x) : "m" (x), "m" (uno));
  }
  cout << endl <<"El resultado de la factorial es: " <<resultado;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar a las Operaciones aritmeticas ";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al operando de factoriales"; 
  cout << endl <<"Opcion: ";
  cin >> y;

  if (y == 'Q'){
    menuCalculadora();
  } 
  else if (y == 'E'){
    menuPrincipal();
  }
  else{
    factorial();
  }
}

void menuSuma(){
  system("clear");
  char x = '1';
  float num1, num2, suma;

  cout << endl <<"------->> Suma <<-------" << endl;

  cout << endl <<"Digite el primer numero: ";
  cin >> num1;

  cout << endl <<"Digite el Segundo numero: ";
  cin >> num2;

  __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (suma) : "m" (num1), "m" (num2) ) ;

  cout << endl <<"El resultado de la Suma: "<< num1 <<" + "<< num2 << " = "  <<suma;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar a las Operaciones aritmeticas ";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al operando de suma"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    menuCalculadora();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    menuSuma();
  }
}

void menuResta(){
  char x = '1';
  system("clear");
  float num1, num2, resta;

  cout << endl <<"------->> Resta <<-------" << endl;
  cout << endl <<"Digite el primer numero: ";
  cin >> num1;

  cout << endl <<"Digite el Segundo numero: ";
  cin >> num2;

  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (resta) : "m" (num1), "m" (num2));

  cout << endl <<"El resultado de la Resta: "<< num1 <<" - "<< num2 << " = "  <<resta;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar a las Operaciones aritmeticas ";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al operando de resta"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    menuCalculadora();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    menuResta();
  }
}

void menuMultiplicacion(){
  char x = '1';

  system("clear");
  float num1, num2, mul;

  cout << endl <<"------->> Multiplicacion <<-------" << endl;

  cout << endl <<"Digite el primer numero: ";
  cin >> num1;

  cout << endl <<"Digite el Segundo numero: ";
  cin >> num2;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (mul) : "m" (num1), "m" (num2) ) ;

  cout << endl <<"El resultado de la Multiplicacion: "<< num1 <<" * "<< num2 << " = "  <<mul;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar a las Operaciones aritmeticas ";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al operando de multiplicacion";
  cout << endl <<"Opcion: "; 
  cin >> x;

  if (x == 'Q'){
    menuCalculadora();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    menuMultiplicacion();
  }
}

void menuDivision(){
  char x = '1';

  system("clear");
  float num1, num2, resultado;

  cout << endl <<"------->> Division <<-------";

  cout << endl <<"RECUERDE QUE NO FUNCIONA CON LOS NUMEROS RACIONALES"<<endl;

  cout << endl <<"Digite el primer numero: ";
  cin >> num1;

  cout << endl <<"Digite el Segundo numero: ";
  cin >> num2;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (num2) ) ;

  cout << endl <<"El resultado de la division: "<< num1 <<" / "<< num2 << " = "  <<resultado;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar a las Operaciones aritmeticas ";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al operando de division"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    menuCalculadora();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    menuDivision();
  }
}

void conversorMetrico(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Conversor Metrico <<-------" << endl;
  cout << endl <<"Opciones: ";
  cout << endl <<"1. Metros";
  cout << endl <<"2. Kilometros";
  cout << endl <<"3. Millas";
  cout << endl <<"4. Pulgadas";
  cout << endl <<"5. Pies";
  cout << endl <<"6. Menu Principal"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if(x == '1'){
    metros();
  }
  else if(x == '2'){
    kilometros();
  }
  else if(x == '3'){
    millas();
  }
  else if(x == '4'){
    pulgadas();
  }
  else if(x == '5'){
    pies();
  }
  else if(x == '6'){
    menuPrincipal();
  }
  else{
    conversorMetrico();
  }
}

void metros(){
  char x = '0';
  system("clear");
  cout << endl <<"------->> Convertir de Metros a las diferentes longitudes <<-------" << endl; 
  float num1, resultado1, resultado2, resultado3, resultado4, num2 = 1000, num3 = 1600, num4 = 39.37, num5 = 3.28;

  cout << endl <<"Digite la cantidad de metros: ";
  cin >> num1;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  cout << endl <<"La cantidad de metros en Kilometros es: " <<resultado1;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num3) ) ;
  cout << endl <<"La cantidad de metros en Millas es: " <<resultado2;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado3) : "m" (num1), "m" (num4) ) ;
  cout << endl <<"La cantidad de metros en Pulgadas es: " <<resultado3;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado4) : "m" (num1), "m" (num5) ) ;
  cout << endl <<"La cantidad de metros en Pies es: " <<resultado4;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor Metrico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de metros"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMetrico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    metros();
  }
}

void kilometros(){
  char x = '0';
  system("clear");
  cout << endl <<"------->> Convertir de Kilometros a las diferentes longitudes <<-------" << endl; 
  float num1, resultado1, resultado2, resultado3, resultado4, num2 = 1000, num3 = 1.60934, num4 = 39370.1, num5 = 3280.84;
  
  cout << endl <<"Digite la cantidad de Kilometros: ";
  cin >> num1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  cout << endl <<"La cantidad de kilometros en Metros es: " <<resultado1;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num3) ) ;
  cout << endl <<"La cantidad de kilometros en Millas es: " <<resultado2;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado3) : "m" (num1), "m" (num4) ) ;
  cout << endl <<"La cantidad de kilometros en Pulgadas es: " <<resultado3;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado4) : "m" (num1), "m" (num5) ) ;
  cout << endl <<"La cantidad de kilometros en Pies es: " <<resultado4;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor Metrico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de kilometros"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMetrico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    kilometros();
  }
}

void millas(){
  char x = '0';
  system("clear");
  cout << endl <<"------->> Convertir de Millas a las diferentes longitudes <<-------" << endl; 
  float num1, resultado1, resultado2, resultado3, resultado4, num2 = 1609.34, num3 = 1.60934, num4 = 63360, num5 = 5280;

  cout << endl <<"Digite la cantidad de millas: ";
  cin >> num1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  cout << endl <<"La cantidad de millas en Metros es: " <<resultado1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num3) ) ;
  cout << endl <<"La cantidad de millas en Kilometros es: " <<resultado2;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado3) : "m" (num1), "m" (num4) ) ;
  cout << endl <<"La cantidad de millas en Pulgadas es: " <<resultado3;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado4) : "m" (num1), "m" (num5) ) ;
  cout << endl <<"La cantidad de millas en Pies es: " <<resultado4;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor Metrico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de millas"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMetrico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    millas();
  }
}

void pulgadas(){
  char x = '0';
  system("clear");
  cout << endl <<"------->> Convertir de Pulgadas a las diferentes longitudes <<-------" << endl; 
  float num1, resultado1, resultado2, resultado3, resultado4, num2 = 39.37, num3 = 39370, num4 = 63360, num5 = 12;

  cout << endl <<"Digite la cantidad de pulgadas: ";
  cin >> num1;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  cout << endl <<"La cantidad de pulgadas en Metros es: " <<resultado1;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num3) ) ;
  cout << endl <<"La cantidad de pulgadas en Kilometros es: " <<resultado2;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado3) : "m" (num1), "m" (num4) ) ;
  cout << endl <<"La cantidad de pulgadas en Millas es: " <<resultado3;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado4) : "m" (num1), "m" (num5) ) ;
  cout << endl <<"La cantidad de pulgadas en Pies es: " <<resultado4;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor Metrico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de pulgadas"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMetrico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    pulgadas();
  }
}

void pies(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Convertir de Pies a las diferentes longitudes <<-------" << endl;  
  float num1, resultado1, resultado2, resultado3, resultado4, num2 = 3.28084, num3 = 3280.84, num4 = 5280, num5 = 12;

  cout << endl <<"Digite la cantidad de pies: ";
  cin >> num1;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  cout << endl <<"La cantidad de pies en Metros es: " <<resultado1;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num3) ) ;
  cout << endl <<"La cantidad de pies en Kilometros es: " <<resultado2;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado3) : "m" (num1), "m" (num4) ) ;
  cout << endl <<"La cantidad de pies en Millas es: " <<resultado3;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado4) : "m" (num1), "m" (num5) ) ;
  cout << endl <<"La cantidad de pies en Pulgadas es: " <<resultado4;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor Metrico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de pies"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMetrico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    pies();
  }
}

void conversorMasas(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Conversor de Masas <<-------" << endl;
  cout << endl <<"Opciones: ";
  cout << endl <<"1. Gramos";
  cout << endl <<"2. Kilogramos";
  cout << endl <<"3. Libras";
  cout << endl <<"4. Menu Principal"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if(x == '1'){
    gramos();
  }
  else if(x == '2'){
    kilogramos();
  }
  else if(x == '3'){
    libras();
  }
  else if(x == '4'){
    menuPrincipal();
  }
  else{
    conversorMasas();
  }
}

void gramos(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Convertir de Gramos a las diferentes masas <<-------" << endl;    
  float num1, resultado1, resultado2, num2 = 0.001, num3 = 453.592;

  cout << endl <<"Digite la cantidad de gramos: ";
  cin >> num1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  cout << endl <<"La cantidad de gramos en Kilogramos es: " <<resultado1;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num3) ) ;
  cout << endl <<"La cantidad de gramos en Libras es: " <<resultado2;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor de Masa";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de gramos"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMasas();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    gramos();
  }
}

void kilogramos(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Convertir de Kilogramos a las diferentes masas <<-------" << endl;    
  float num1, resultado1, resultado2, num2 = 1000, num3 = 2.20462;

  cout << endl <<"Digite la cantidad de kilogramos: ";
  cin >> num1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  cout << endl <<"La cantidad de kilogramos en Gramos es: " <<resultado1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num3) ) ;
  cout << endl <<"La cantidad de kilogramos en Libras es: " <<resultado2;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor de Masa";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de kilogramos"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMasas();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    kilogramos();
  }
}

void libras(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Convertir de Libras a las diferentes masas <<-------" << endl;  
  float num1, resultado1, resultado2, num2 = 0.453592, num3 = 453.592;

  cout << endl <<"Digite la cantidad de gramos: ";
  cin >> num1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  cout << endl <<"La cantidad de libras en Kilogramos es: " <<resultado1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num3) ) ;
  cout << endl <<"La cantidad de libras en gramos es: " <<resultado2;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor de Masa";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de libras"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMasas();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    libras();
  }
}

void conversorTemperaturas(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Conversor de Temperaturas <<-------" << endl;
  cout << endl <<"Opciones: ";
  cout << endl <<"1. Celsius";
  cout << endl <<"2. Fahrenheit";
  cout << endl <<"3. Kelvin";
  cout << endl <<"4. Menu Principal"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if(x == '1'){
    celsius();
  }
  else if(x == '2'){
    fahrenheit();
  }
  else if(x == '3'){
    kelvin();
  }
  else if(x == '4'){
    menuPrincipal();
  }
  else{
    conversorMasas();
  }
}

void celsius(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Convertir de Celsius a las diferentes temperaturas <<-------" << endl;  
  float num1, resultado1, suma, resultado2, num2 = 1.8, num3 = 32, num4 = 273.15;

  cout << endl <<"Digite la cantidad de celsius: ";
  cin >> num1;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado1) : "m" (num1), "m" (num2) ) ;
  
  __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (suma) : "m" (resultado1), "m" (num3) ) ;           
  cout << endl <<"La cantidad de celsius en Fahrenheit es: " <<suma;

  __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (resultado2) : "m" (num1), "m" (num4) ) ;           
  cout << endl <<"La cantidad de celsius en Kelvin es: " <<resultado2;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor de Temperaturas";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de celsius"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorTemperaturas();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    celsius();
  }
}

void fahrenheit(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Convertir de Fahrenheit a las diferentes temperaturas <<-------" << endl;
  float num1, resultado, resta, suma, num2 = 0.5555, num3 = 32, num4 = 273.15;

  cout << endl <<"Digite la cantidad de fahrenheit: ";
  cin >> num1;

  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (resta) : "m" (num1), "m" (num3) ) ;
  
  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (resta), "m" (num2) ) ;
  cout << endl <<"La cantidad de fahrenheit en Celsius es: " <<resultado;

  __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (suma) : "m" (resultado), "m" (num4) ) ;                    
  cout << endl <<"La cantidad de fahrenheit en Kelvin es: " <<suma;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor de Temperaturas";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de fahrenheit"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorTemperaturas();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    fahrenheit();
  }
}

void kelvin(){
  system("clear");
  cout << endl <<"------->> Convertir de Kelvin a las diferentes temperaturas <<-------" << endl;
  char x = '0';
  float num1, resultado, resta, suma, num2 = 1.8, num3 = 32, num4 = 273.15;

  cout << endl <<"Digite la cantidad de kelvin: ";
  cin >> num1;

  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (resta) : "m" (num1), "m" (num4) ) ;
  cout << endl <<"La cantidad de kelvin en Celsius es: " <<resta;

  __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (resta), "m" (num2) ) ;

  __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (suma) : "m" (resultado), "m" (num3) ) ;                    
  cout << endl <<"La cantidad de kelvin en Fahrenheit es: " <<suma;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al Conversor de Temperaturas";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna el conversor de kelvin"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorTemperaturas();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    kelvin();
  }
}

void conversorNumerico(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Conversor Numerico <<-------" << endl;
  cout << endl <<"Opciones: ";
  cout << endl <<"1. Decimal a Binario";
  cout << endl <<"2. Binario a Decimal";
  cout << endl <<"3. Decimal a Complemetento base 2";
  cout << endl <<"4. Complemento base 2 a Decimal";
  cout << endl <<"5. Decimal a IEEE";
  cout << endl <<"6. IEEE a Decimal"; 
  cout << endl <<"7. Menu Principal";
  cout << endl <<"Opcion: ";
  cin >> x;

  if(x == '1'){
    DaB();
  }
  else if(x == '2'){
    BaD();
  }
  else if(x == '3'){
    DaC2();
  }
  else if(x == '4'){
    C2aD();
  }
  else if(x == '5'){
    DaI();
  }
  else if(x == '6'){
    IaD();
  }
  else if(x == '7'){
    menuPrincipal();
  }
  else{
    conversorMetrico();
  }
}

void DaB(){
  system("clear");
  cout << endl <<"------->> Convertir de Base Decimal a base Binaria <<-------" << endl;
  char x = '0';
  float num1, resta, num2 = 2, aux2, aux3 = 0, dos = 2, uno = 1, cont1 = 0, cont2;
  string numero, aux;

  cout << endl <<"Ingrese un numero: ";
  cin >> num1;

  float aux4 = num1;
  
  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (aux2) : "m" (uno), "m" (dos));
    
  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (aux3) : "m" (aux3), "m" (dos));

  while (num1 >= -2){
    __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (resta) : "m" (num1), "m" (num2));

    num1 = resta;
    resta = 0;
    __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont1) : "m" (cont1), "m" (uno) ) ;
    if(num1 == 0){
      numero = numero + '0';
      num1 = cont1;
      cont1 = 0;
    }
    else if(num1 == 1){
      numero = numero + '1';
      num1 = cont1;
      cont1 = 0;
    }
    else if (num1 == aux2 ){
      numero = numero + '1';
      num1 = -3;
    }
    else if (num1 == aux3 ){
      numero = numero + '0';
      num1 = -3;
    }
  }

  for(cont2 = numero.length() - 1; cont2 >= 0; cont2--){
    aux.append(numero.substr(cont2, 1));
  }
  cout << endl << "El numero " << aux4 << " en binario es " << aux;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al conversor numerico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al conversor de decimal a binario"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorNumerico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    DaB();
  }
}

void BaD(){
  system("clear");
  cout << endl <<"------->> Convertir de base Binaria a base Decimal <<-------" << endl;
  string num1, aux, aux2;
  char x = '0';
  float resultado, resultado2, cont, cont2, cont5 = 0, cont3 = 0, total = 0, uno = 1;

  cout << endl << "Ingrese el numero: ";
  cin >> num1;

  for(cont = num1.length() - 1; cont >= 0; cont--){
    aux.append(num1.substr(cont, 1));
  }

  cont2 = aux.length();
  
  while(cont2 >= 0){
    aux2 = aux.substr(cont5, 1);
    if (aux2 == "0"){
      __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont5) : "m" (cont5), "m" (uno) ) ;
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
    else if(aux2 == "1"){
      float aux1 = 2;
      float num = 2;
      while (cont3 < cont5){
        __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (num), "m" (aux1)) ;
        num = resultado;
        __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont3) : "m" (cont3), "m" (uno) ) ;
      }
      cont3 = 0;
      __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (resultado2) : "m" (total), "m" (num) ) ;
      total = resultado2;
      __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont5) : "m" (cont5), "m" (uno) ) ;
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
    else{
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
  }
  float numero = 2;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (total) : "m" (total), "m" (numero) ) ;

  cout << "El numero binario " << num1 << " en decimal es: " << total;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al conversor numerico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al conversor de binario a decimal"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorNumerico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    BaD();
  }
}

void DaC2(){
  system("clear");
  cout << endl <<"------->> Convertir de base Decimal a Complemento base 2 <<-------" << endl;
  char x = '0';
  float num1, resta, num2 = 2, aux2, aux3 = 0, dos = 2, uno = 1, cont1 = 0, cont2, val = 256;
  string numero, aux;

  cout << endl <<"Ingrese un numero: ";
  cin >> num1;

  int aux4 = num1;
  if (num1 < 0){
    __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (num1) : "m" (num1), "m" (val) ) ;
  }
  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (aux2) : "m" (uno), "m" (dos));
  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (aux3) : "m" (aux3), "m" (dos));

  while (num1 >= -2){
    __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (resta) : "m" (num1), "m" (num2));

    num1 = resta;
    resta = 0;
    __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont1) : "m" (cont1), "m" (uno) ) ;
    if(num1 == 0){
      numero = numero + '0';
      num1 = cont1;
      cont1 = 0;
    }
    else if(num1 == 1){
      numero = numero + '1';
      num1 = cont1;
      cont1 = 0;
    }
    else if (num1 == aux2 ){
      numero = numero + '1';
      num1 = -3;
    }
    else if (num1 == aux3 ){
      numero = numero + '0';
      num1 = -3;
    }
  }

  for(cont2 = numero.length() - 1; cont2 >= 0; cont2--){
    aux.append(numero.substr(cont2, 1));
  }
  cout << endl << "El numero " << aux4 << " en complemento base 2 es " << aux;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al conversor numerico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al conversor de decimal a complemento base 2"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorNumerico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    DaC2();
  }
}

void C2aD(){
  system("clear");
  cout << endl <<"------->> Convertir de Complemento base 2 a base Decimal <<-------" << endl;
  char x = '0';
  string aux, aux2, num1;
  float resultado, resultado2, cont, cont2, cont5 = 0, cont3 = 0, total = 0, val = 256, uno = 1;
  bool bandera = false;

  cout << endl << "Ingrese el numero: ";
  cin >> num1;

  if(num1.length() > 7){
    string aux3 = num1.substr(0, 1);
    if(aux3 == "1"){
      bandera = true;
    }
  }

  for(cont = num1.length() - 1; cont >= 0; cont--){
    aux.append(num1.substr(cont, 1));
  }

  cont2 = aux.length();
  
  while(cont2 >= 0){
    aux2 = aux.substr(cont5, 1);
    if (aux2 == "0"){
      __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont5) : "m" (cont5), "m" (uno) ) ;
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
    else if(aux2 == "1"){
      float aux1 = 2;
      float num = 2;
      while (cont3 < cont5){
        __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (num), "m" (aux1)) ;
        num = resultado;
        cont3 = cont3 + 1;
      }
      cont3 = 0;
      __asm__ ( "fld %1;"
                  "fld %2;"
                  "faddp;"
                  "fstp %0;" : "=m" (resultado2) : "m" (total), "m" (num) ) ;
      total = resultado2;
      __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont5) : "m" (cont5), "m" (uno) ) ;
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
    else{
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
  }
  float numero = 2;

  __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (total) : "m" (total), "m" (numero) ) ;

  if(bandera == true){
    __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (total) : "m" (total), "m" (val) ) ;
  }
  cout << "El numero " << num1 << " en decimal es: " << total;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al conversor numerico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al conversor de complemento base 2 a decimal"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorNumerico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    C2aD();
  }
}

void DaI(){
  char x;
  system("clear");
  string num1, completo, binario, entero, numero, numeroEx, auxExponente, auxEbinario, auxFbinario;
  float flo2, ent, flo, val = 127, num2 = 2, aux2 = -1, aux3 = -2, dos = 2, cont1 = 0, cont1E = 0, cont2, cont2E, resta, restaE, contflo = 0, auxDecimal, exponente = 0;
  int z = 0;
  
  cout << endl <<"------->> Convertir de Base Decimal a Formato IEEE 754 <<-------" << endl;
  cout << endl <<"Digite el numero: ";
  cin >> num1;
  
  if(num1.substr(0,1) == "-"){
    completo = "1";
    entero = num1.substr(1, num1.length());
  }else{
    completo = "0";
    entero = num1;
  }

  string separador = ".";
  size_t pos = 0;
  string auxEntero;
  while ((pos = entero.find(separador)) != string::npos) {
    auxEntero = entero.substr(0, pos);
    entero.erase(0, pos + separador.length());
  }

  auxEntero.append(".0");
  entero.append(".0");

  if (entero.length() == 3){
    auxDecimal = 10;
  }else if (entero.length() == 4){
    auxDecimal = 100;
  }else if (entero.length() == 5){
    auxDecimal = 1000;
  }else{
    auxDecimal = 10000;
  }

  ent = stof(auxEntero);
  flo = stof(entero);

  while (ent >= -2){
    __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (resta) : "m" (ent), "m" (num2));
    ent = resta;
    resta = 0;
    cont1 = cont1 + 1;
    if(ent == 0){
      numero = numero + '0';
      ent = cont1;
      cont1 = 0;
    }else if(ent == 1){
      numero = numero + '1';
      ent = cont1;
      cont1 = 0;
    }else if (ent == aux2 ){
      numero = numero + '1';
      ent = -3;
    }else if (ent == aux3 ){
      numero = numero + '0';
      ent = -3;
    }
  }

  for(cont2 = numero.length() - 1; cont2 >= 0; cont2--){
    auxEbinario.append(numero.substr(cont2, 1));
  }

  while(contflo < 23){
    __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (flo2) : "m" (flo), "m" (dos)) ;
    if(flo2 >= auxDecimal){
      auxFbinario.append("1");
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (flo) : "m" (flo2), "m" (auxDecimal));
      contflo++;
    }else{
      auxFbinario.append("0");
      flo = flo2;
      contflo++;
    }
  }

  binario = auxEbinario + auxFbinario;
  z = auxEbinario.length() + 2;
  exponente = auxEbinario.length()-1;

  binario.insert(1,".");

  __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (exponente) : "m" (exponente), "m" (val));
  
  while (exponente >= -2){
    __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (restaE) : "m" (exponente), "m" (num2));

    exponente = restaE;
    restaE = 0;
    cont1E = cont1E + 1;
    if(exponente == 0){
      numeroEx = numeroEx + '0';
      exponente = cont1E;
      cont1E = 0;
    }else if(exponente == 1){
      numeroEx = numeroEx + '1';
      exponente = cont1E;
      cont1E = 0;
    }else if (exponente == aux2 ){
      numeroEx = numeroEx + '1';
      exponente = -3;
    }else if (exponente == aux3 ){
      numeroEx = numeroEx + '0';
      exponente = -3;
    }
  }

  for(cont2E = numeroEx.length() - 1; cont2E >= 0; cont2E--){
    auxExponente.append(numeroEx.substr(cont2E, 1));
  }

  string separator = ".";
  size_t posb = 0;
  while ((posb = binario.find(separator)) != string::npos) {
    binario.erase(0, posb + separator.length());
  }

  completo = completo + auxExponente + binario;
  completo = completo.substr(0, 32);

  cout << "El numero " << num1 << " en IEE es " << completo;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al conversor numerico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al conversor de decimal a IEEE"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorNumerico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    DaI();
  }
}

float auxBinADec(string num1){
  char x = '0';
  string aux, aux2;
  float resultado, resultado2, cont, cont2, cont3 = 0, cont5 = 0, total = 0, uno = 1;

  for(cont = num1.length() - 1; cont >= 0; cont--){
    aux.append(num1.substr(cont, 1));
  }

  cont2 = aux.length();
  
  while(cont2 >= 0){
    aux2 = aux.substr(cont5, 1);
    if (aux2 == "0"){
      __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont5) : "m" (cont5), "m" (uno) ) ;
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
    else if(aux2 == "1"){
      float aux1 = 2;
      float num = 2;
      while (cont3 < cont5){
        __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (num), "m" (aux1)) ;
        num = resultado;
        cont3 = cont3 + 1;
      }
      cont3 = 0;
      __asm__ ( "fld %1;"
                  "fld %2;"
                  "faddp;"
                  "fstp %0;" : "=m" (resultado2) : "m" (total), "m" (num) ) ;
      total = resultado2;
      __asm__ ( "fld %1;" "fld %2;" "faddp;" "fstp %0;" : "=m" (cont5) : "m" (cont5), "m" (uno) ) ;
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
    else{
      __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno));
    }
  }
  float numero = 2;

  __asm__ ( "fld %2;"
              "fld %1;"
              "fdivp;"
              "fstp %0;" : "=m" (total) : "m" (total), "m" (numero) ) ;

  return total;
}

float auxIEEE(string num1){
  string  aux, aux2;
  float result, cont, cont2 = 0, total = 0, val = 2, uno = 1, dos =2;

  cont = num1.length();

  while(cont > 0){
    aux2 = num1.substr(cont2, 1);
    cout << endl << aux2;
    if (aux2 == "1"){
      __asm__ ( "fld %2;""fld %1;" "fdivp;" "fstp %0;" : "=m" (result) : "m" (uno), "m" (val) ) ;
      __asm__ ( "fld %1;""fld %2;" "faddp;" "fstp %0;" : "=m" (total) : "m" (total), "m" (result) ) ;
      __asm__ ( "fld %1;""fld %2;" "fmulp;" "fstp %0;" : "=m" (val) : "m" (val), "m" (dos) ) ;
      __asm__ ( "fld %1;""fld %2;" "faddp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno) ) ;
      __asm__ ( "fld %2;""fld %1;" "fsubp;" "fstp %0;" : "=m" (cont) : "m" (cont), "m" (uno) ) ;
      cout << endl << total;
    }else{
      __asm__ ( "fld %1;""fld %2;" "faddp;" "fstp %0;" : "=m" (cont2) : "m" (cont2), "m" (uno) ) ;
      __asm__ ( "fld %2;""fld %1;" "fsubp;" "fstp %0;" : "=m" (cont) : "m" (cont), "m" (uno) ) ;
      __asm__ ( "fld %1;""fld %2;" "fmulp;" "fstp %0;" : "=m" (val) : "m" (val), "m" (dos) ) ;
    }
  }
  return total;
}

void IaD(){
  char x;
  system("clear");
  string num1, signo, exponente, mantisa, mantisaAux;
  float expoDec, bitExp, val = 127 , parteEntera, parteDecimal, mUno = -1;

  cout << endl <<"------->> Convertir de Formato IEEE 754 a Base Decimal <<-------" << endl;
  cout << endl <<"Digite el numero: ";
  cin >> num1;

  while (num1.length() < 32){
    num1.append("0");
  }

  signo = num1.substr(0,1);
  exponente = num1.substr(1,8);
  mantisa = num1.substr(9,32);

  expoDec = auxBinADec(exponente);
  __asm__ ( "fld %2;" "fld %1;" "fsubp;" "fstp %0;" : "=m" (bitExp) : "m" (expoDec), "m" (val));

  string correrPunto = mantisa.substr(0, int(bitExp));
  
  mantisaAux = "1"+correrPunto;
  mantisaAux.append(".");
  mantisaAux.append(mantisa.substr(int(bitExp), mantisa.size()));

  string separador = ".";
  size_t pos = 0;
  string auxEntero;
  while ((pos = mantisaAux.find(separador)) != string::npos) {
    auxEntero = mantisaAux.substr(0, pos);
    mantisaAux.erase(0, pos + separador.length());
  }

  parteEntera = auxBinADec(auxEntero);
  parteDecimal = auxIEEE(mantisaAux);

  __asm__ ( "fld %1;""fld %2;" "faddp;" "fstp %0;" : "=m" (parteEntera) : "m" (parteEntera), "m" (parteDecimal) ) ;

  if (signo == "1"){
    __asm__ ( "fld %1;""fld %2;" "fmulp;" "fstp %0;" : "=m" (parteEntera) : "m" (parteEntera), "m" (mUno) ) ;
  }
  
  cout << endl <<"El resultado de "<< num1 << " convertido a Formato IEEE 754 es: "  <<parteEntera;

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al conversor numerico";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al conversor de IEEE a decimal"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorNumerico();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    IaD();
  }
}

void conversorMonedas(){
  system("clear");
  char x = '0';
  cout << endl <<"------->> Cambio de divisas <<-------" << endl;
  cout << endl <<"Opciones: ";
  cout << endl <<"1. Colon";
  cout << endl <<"2. Euro";
  cout << endl <<"3. Dolar";
  cout << endl <<"4. Historial de transacciones";
  cout << endl <<"5. Menu Principal"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if(x == '1'){
    colon();
  }
  else if(x == '2'){
    euro();
  }
  else if(x == '3'){
    dolar();
  }
  else if(x == '4'){
    leerArchivo();
  }
  else if(x == '5'){
    menuPrincipal();
  }
  else{
    conversorMasas();
  }
}

void colon(){
  char x = '0';
  system("clear");
  cout << endl <<"------->> Cambio de colon <<-------" << endl;
  cout << endl <<"1. Dolar";
  cout << endl <<"2. Euro";
  cout << endl <<"3. Cambio de divisas"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == '1'){
    system("clear");
    cout << endl <<"------->> Cambio de colon <<-------" << endl;
    float resultado, num1, dolar = 607;
    string dato, fecha;

    cout << endl <<"Ingrese la fecha: ";
    cin >> fecha;

    cout << endl <<"Digite la cantidad: ";
    cin >> num1;

    __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (dolar) ) ;
    string aux = Convert(dolar);
    if (num1 == '1'){
      cout << endl <<"La cantidad de "<< num1 << " colon es " << resultado << " un dolar";
      dato = "Fecha: " + fecha + "||" + "Moneda: Colon" + "||" + "Tipo de cambio: " + aux + "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del colon"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        colon();
      }
    }
    else{
      cout << endl <<"La cantidad de "<< num1<< " colones es "<< resultado<< " en dolares";
      dato = "Fecha: " + fecha + "||" + "Moneda: Colon" + "||" + "Tipo de cambio: "+ aux +"\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del colon"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        colon();
      }
    }
  }
  else if(x == '2'){
    system("clear");
    cout << endl <<"------->> Cambio de colon <<-------" << endl;
    string dato, fecha;
    float resultado, num1, euro = 733.91;

    cout << endl <<"Ingrese la fecha: ";
    cin >> fecha;

    cout << endl <<"Digite la cantidad: ";
    cin >> num1;

    __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (euro) ) ;
    string aux = Convert(euro);
    if (num1 == '1'){
      cout << endl <<"La cantidad de "<< num1 << " colon es "<< resultado<< " un euro";

      dato = "Fecha: " + fecha + "||" + "Moneda: Colon" + "||" + "Tipo de cambio: " + aux + "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del colon"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        colon();
      }
    }
    else{
      cout << endl <<"La cantidad de "<< num1<< " colones es "<< resultado<< " en euros";
      
      dato = "Venta de colon || Fecha: " + fecha + "||" + "Moneda: Colon" + "||" + "Tipo de cambio: " + aux + "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del colon"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        colon();
      }
    }
  }
  else {
    conversorMonedas();
  }
}

void dolar(){
  char x = '0';
  system("clear");
  cout << endl <<"------->> Cambio de dolar <<-------" << endl;
  cout << endl <<"1. Colon";
  cout << endl <<"2. Euro";
  cout << endl <<"3. Cambio de divisas"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == '1'){
    system("clear");
    cout << endl <<"------->> Cambio de dolar <<-------" << endl;
    string dato, fecha;
    float resultado, num1, colon = 592;

    cout << endl <<"Ingrese la fecha: ";
    cin >> fecha;

    cout << endl <<"Digite la cantidad: ";
    cin >> num1;

    __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (colon) ) ;
    
    string aux = Convert(colon);
    if (num1 == '1'){
      cout << endl <<"La cantidad de "<< num1<< " dolar es "<< resultado<< " un colon";

      dato = "Fecha: " + fecha + "||" + "Moneda: Dolar" + "||" + "Tipo de cambio: "+ aux+ "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del dolar"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        dolar();
      }
    }
    else{
      cout << endl <<"La cantidad de "<< num1<< " dolares es "<< resultado<< " en colones";

      dato = "Fecha: " + fecha + "||" + "Moneda: Dolar" + "||" + "Tipo de cambio: " + aux + "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del dolar"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        dolar();
      }
    }
  }
  else if(x == '2'){
    system("clear");
    cout << endl <<"------->> Cambio de dolar <<-------" << endl;
    string dato, fecha;
    float resultado, num1, euro = 1.2124;

    cout << endl <<"Ingrese la fecha: ";
    cin >> fecha;

    cout << endl <<"Digite la cantidad: ";
    cin >> num1;

    __asm__ ( "fld %2;" "fld %1;" "fdivp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (euro) ) ;
    
    string aux = Convert(euro);
    if (num1 == '1'){
      cout << endl <<"La cantidad de "<< num1<< " dolar es "<< resultado<< " un euro";
      dato = "Fecha: " + fecha + "||" + "Moneda: Dolar" + "||" + "Tipo de cambio: " + aux + "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del dolar"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        dolar();
      }
    }
    else{
      cout << endl <<"La cantidad de "<< num1<< " dolares es "<< resultado<< " en euros";
      dato = "Fecha: " + fecha + "||" + "Moneda: Dolar" + "||" + "Tipo de cambio: " + aux + "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del dolar"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        dolar();
      }
    }
  }
  else {
    conversorMonedas();
  }
}

void euro(){
  char x = '0';
  system("clear");
  cout << endl <<"------->> Cambio del euro <<-------" << endl;
  cout << endl <<"1. Colon";
  cout << endl <<"2. Dolar";
  cout << endl <<"3. Cambio de divisas"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == '1'){
    system("clear");
    cout << endl <<"------->> Cambio del euro <<-------" << endl;
    string dato, fecha;
    float resultado, num1, colon = 733.91;

    cout << endl <<"Ingrese la fecha: ";
    cin >> fecha;

    cout << endl <<"Digite la cantidad: ";
    cin >> num1;

    __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (colon) ) ;
    string aux = Convert(colon);
    if (num1 == '1'){
      cout << endl <<"La cantidad de "<< num1<< " euro es "<< resultado<< " colon";

      dato = "Fecha: " + fecha + "||" + "Moneda: Euro" + "||" + "Tipo de cambio: "+ aux + "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del euro"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        euro();
      }
    }
    else{
      cout << endl <<"La cantidad de "<< num1<< " euros es "<< resultado<< " en colones";
      dato = "Fecha: " + fecha + "||" + "Moneda: Euro" + "||" + "Tipo de cambio: "+ aux +"\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del euro"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        euro();
      }
    }
  }
  else if(x == '2'){
    system("clear");
    cout << endl <<"------->> Cambio del euro <<-------" << endl;
    string dato, fecha;
    float resultado, num1, dolar = 1.2120;

    cout << endl <<"Ingrese la fecha: ";
    cin >> fecha;

    cout << endl <<"Digite la cantidad: ";
    cin >> num1;

    __asm__ ( "fld %1;" "fld %2;" "fmulp;" "fstp %0;" : "=m" (resultado) : "m" (num1), "m" (dolar) ) ;
    string aux = Convert(dolar);
    if (num1 == '1'){
      cout << endl <<"La cantidad de "<< num1<< " euro es "<< resultado<< " un dolar";
      dato = "Fecha: " + fecha + "||" + "Moneda: Euro" + "||" + "Tipo de cambio: " + aux + "\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del euro"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        euro();
      }
    }
    else{
      cout << endl <<"La cantidad de "<< num1<< " euros es "<< resultado<< " en dolares";
      dato = "Fecha: " + fecha + "||" + "Moneda: Euro" + "||" + "Tipo de cambio: " + aux +"\n";
      escribirArchivo(dato);

      cout << endl <<"\n\n";
      cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
      cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
      cout << endl <<"--> Cualquier otra tecla retorna al cambio del euro"; 
      cout << endl <<"Opcion: ";
      cin >> x;

      if (x == 'Q'){
        conversorMonedas();
      } 
      else if ( x == 'E'){
        menuPrincipal();
      }
      else{
        euro();
      }
    }
  }
  else {
    conversorMonedas();
  }
}

void leerArchivo(){
  system("clear");
  cout << endl << "-------> Datos del archivo <-------" << endl;
  char x = '0';
  archivo.open("datos.txt", ios::in);
  if(archivo.is_open()){
    string linea;
    while( getline(archivo, linea)){
      cout<< endl<< linea<<endl;
    }
    archivo.close();
  }
  else{
    cout<< "El archivo no existe...";
  }

  cout << endl <<"\n\n";
  cout << endl <<"--> Presione la tecla 'Q' para regresar al cambio de divisas";
  cout << endl <<"--> Presione la tecla 'E' para regresar al Menu Principal";
  cout << endl <<"--> Cualquier otra tecla retorna al historial de transacciones"; 
  cout << endl <<"Opcion: ";
  cin >> x;

  if (x == 'Q'){
    conversorMonedas();
  } 
  else if ( x == 'E'){
    menuPrincipal();
  }
  else{
    leerArchivo();
  }
}

void escribirArchivo(string dato){
  archivo.open("datos.txt", ios::out|ios::app);
  if(archivo.is_open()){
    archivo<<dato;
    archivo.close();
  }
  else{
    cout<< "El archivo no existe...";
  }
}

string Convert (float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

int main() {
    menuPrincipal();
    return 0 ;
}