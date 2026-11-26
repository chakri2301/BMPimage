#include <stdio.h>
#include <stdint.h>
#include "bmp.h"
void createImage(int iHeight, int iWidth, uint8_t* image) {
  FILE *file;
  file = fopen("./pic.bmp", "wb");
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