#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define LINE_BUFFER 256

int main(int argc, char *argv[])
{
  if(argc <3){
    printf("Error en los parametros");
    return EXIT_FAILURE;
  }
  char* nombre_fichero = argv[1];
  char* patron = argv[2];

  FILE* archivo = fopen(nombre_fichero, "r");
  if(!archivo){
    printf("Error al abrir el archivo");
    return EXIT_FAILURE;
  }
  char linea[LINE_BUFFER]; 
  for(int lin = 1; fgets(linea, sizeof(linea), archivo);lin++){
    linea[strcspn(linea, "\n")] = 0;
    if (strstr(linea, patron) != NULL) {
      printf("[PROCESADOR %d] Patrón '%s' encontrado en línea %d\n", getpid(), patron, lin);
    }
  }
  fclose(archivo);
  return EXIT_SUCCESS;
}
