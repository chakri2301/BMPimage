#include "./bmp.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  printf("%d\n", argc);
  argc--;
  if (argc == 1) {
    if (strcmp("-h", argv[1]) == 0) {
      printf("Convert ascii 0-255 PPM into bitmap\n");
      printf("bmpc <ppmFile>-o <output>\n");
      return 0;
    }
    printf("Camehere\n");
  }
  if (argc != 3) {
    printf("arguments Error. see \"bmpc -h\"\n");
    return 0;
  } else {
    if (strcmp("-o", argv[2]) == 0) {
      fromPPM(argv[1], argv[3]);
    }
  }
}