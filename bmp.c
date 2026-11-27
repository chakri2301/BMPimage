#include "bmp.h"
#include <stdint.h>
#include <stdio.h>
void createImage(int iHeight, int iWidth, uint8_t *image, const char* fileName) {
  FILE *file;
  file = fopen(fileName, "wb");
  BmpHeader header;
  header.type = 0x4D42;
  header.size = 54 + iHeight * iWidth * 3;
  header.reserved1 = 0;
  header.reserved2 = 0;
  header.offset = 54;
  BmpInfoHeader iHeader;
  iHeader.size = 40;
  iHeader.width = iWidth;
  iHeader.height = iHeight;
  iHeader.planes = 1;
  iHeader.bits = 24;
  iHeader.compression = 0;
  iHeader.imagesize = 3 * iHeader.height * iHeader.width;
  iHeader.xresolution = 0;
  iHeader.yresolution = 0;
  iHeader.ncolours = 0;
  iHeader.importantcolours = 0;
  fwrite((void *)&(header), sizeof(BmpHeader), 1, file);
  fwrite((void *)&(iHeader), sizeof(BmpInfoHeader), 1, file);
  fwrite(image, 1, 3 * iHeader.width * iHeader.height, file);
  fclose(file);
}
void fromPPM(const char* inFileName, const char* outFileName) {
  FILE *file;
  int iHeight = 0;
  int iWidth = 0;
  file = fopen(inFileName, "r");
  fscanf(file, "P3\n");
  fscanf(file, "%d %d\n", &iWidth, &iHeight);
  fscanf(file, "255\n");
  uint8_t image[iHeight][iWidth * 3];
  for (int i = iHeight - 1; i >= 0; i--) {
    for (int j = 0; j < iWidth * 3; j += 3) {
      fscanf(file, "%hhu %hhu %hhu\n", &(image[i][j + 2]), &(image[i][j + 1]),
             &(image[i][j]));
    }
  }
  createImage(iHeight, iWidth, (uint8_t *)image, outFileName);
}