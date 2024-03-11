#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char* nombre_fichero = argv[1];
  char* patron = argv[2];

  FILE* archivo = fopen(nombre_fichero, "r");
  char linea[256]; 
  int lineas = 0;
  for(int lin = 1; fgets(linea, sizeof(linea), archivo);lin++){
    lineas++;
    linea[strcspn(linea, "\n")] = 0;
    if (strstr(linea, patron) != NULL) {
      printf("[PROCESADOR %d] Patrón '%s' encontrado en línea %d\n", getpid(), patron, lineas);
    }
  }
  fclose(archivo);
  return EXIT_SUCCESS;
}
