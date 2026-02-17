# OrtizValladoNaomiAbril_EDAI_2026-2
Repositorio creado para la materia de EDA I. Facultad de Ingeniería. UNAM, C.U.
#include <stdio.h>
int main(){
     //Arreglo lineal de enteros
     int arrEnt[10];
     //Arreglo de lineal de flotantes
     float arrFlotante[12]; 
     //Arreglo lineal de caracteres 
     char arrCarac[15];

     //Arreglo matricial de enteros
     int arrEntM [3][8];
     //Arreglo matricial de flotantes
     float arrFlotanteM[5][3];
     //Arreglo matricial de caracteres
     char arrCaracM[5][6];
      
     //Llenado de los arreglos lineales usando ciclos for
     printf("Arreglo lineal de numeros enteros\n");
     printf("Ingrese 10 valores de tipo entero:");
     for(int=i=0; i<=10; i++) {
       scanf("%d", &arrEnt[i]); 
        }

       printf("Arreglo lineal de numeros flotantes\n");
       printf("INgrese 12 valores de tipo flotante: ");
       for(int i=0; i<12; i++) {
             scanf("%f", &arrFlotante [i]); 
        }

        printf ("Arreglo lineal de tipo cadena \n"); 
        printf ("INgrese una palabra menor a 15 letras: ");
        scanf("%s", &arrCarac);

       //Llenado de los arreglos matriciales 
      printf("Arreglo matricial de numeros enteros\n"); 
      printf("INgrese 24 valores de tipo entero: ");
      for(int i=0; i<3; i++) {
           for (int j=0; j<8; j++)
           scanf("%d", &arrEntM [i][j]); 
}

      printf ("Arreglo matricial de numeros flotantes\n");
      printf ("Ingrese 15 valores de tipo entero: ");
      for (int i=0; i<5; i++) {
            for (int j=0; j<3; j++)
            scanf ("%f", &arrFlotanteM[[i][j];
}

       printf ("Arreglo matricial de caracteres\n"); 
       print ("Ingrese los datos: ");
       for (int i=0; i<5; i++) {
            for (int j=0; j<6; j++)
            scanf("%c", &arrCaracM[i][j]; 
}

      //Impresion de los arreglos lineales
      printf("LOs datos ingresados al arreglo de tipo entero son: \n");
      for(int i=0; i<10; ++) {
           printf ("%d\t", arrEnt[i]; 
} 
       printf ("\n"); 

      printf ("LOs datos ingresados al arreglo de tipo flotante son: \n");
      for (int i=0; i<12; i++) {
             printf ("%.2f\t", arrFlotante [i]);
}
      printf ("\n"; 

      printf (" Los datos ingresados al arreglo de tipo cadena son:  \n"); 
      printf ("%s\t", arrCarac); 
      printf ("\n"); 

      //Impresion de los arreglos matriciales 
      printf ("Arreglo matricial de numeros enteros\n"); 
      for (int i=0; i<3; i++) {
           for (int j=0; j<8; j++)
{
      printf ("%d\t", arrEntM [i][j]);
}
      printf ("\n");
}

     printf("Arreglo matricial de numeros flotantes: \n");
     for (int i=0; i<5; i++) {
           for (int j=0; j<3; j++)
{
      printf ("%.2f\t", arrFlotanteM[i][j]);
}
     printf ("\n");
}

     printf ("Arreglo matricial de caracteres: \n");
     for (int i:0; i<5; i++){
           for (int j=0; j<6; j++)
{
     printf ("%c\t", arrCaracM[i][j]);
}
     printf ("\n");
}

}
