#include "./bmp.h"
#include <stdint.h>
#include <stdio.h>
int main() {
  int iHeight = 100;
  int iWidth = 100;
  uint8_t image[iHeight][iWidth * 3];
  for (int i = 0; i < iHeight; i++) {
    for (int j = 0; j < iWidth * 3; j += 3) {
      image[i][j] = 255;
      image[i][j + 1] = 255;
      image[i][j + 2] = 0;
    }
  }
  createImage(iHeight, iWidth, (uint8_t *)image);
}