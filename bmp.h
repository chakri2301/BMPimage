#ifndef BMP_H
#define BMP_H
#include <stdio.h>
#include <stdint.h>
#pragma pack(1)
typedef struct {
  unsigned short int type;                 /*2- Magic identifier            */
  unsigned int size;                       /*4- File size in bytes          */
  unsigned short int reserved1, reserved2; // 4
  unsigned int offset;                     /*4 Offset to image data, bytes */
  // total = 14 bytes
} BmpHeader;

typedef struct {
  unsigned int size;             /* 4-Header size in bytes      */
  int width, height;             /* 8-Width and height of image */
  unsigned short int planes;     /* 2-Number of colour planes   */
  unsigned short int bits;       /* 2-Bits per pixel            */
  unsigned int compression;      /* 4-Compression type          */
  unsigned int imagesize;        /* 4-Image size in bytes       */
  int xresolution, yresolution;  /* 8-Pixels per meter          */
  unsigned int ncolours;         /* 4-Number of colours         */
  unsigned int importantcolours; /* 4-Important colours         */
                                 // total = 40 bytes
} BmpInfoHeader;
typedef struct {
  char b;
  char g;
  char r;
  char a;
} paletteEntry;
void createImage(int iHeight, int iWidth, uint8_t* image, const char* fileName);
void fromPPM(const char* inFileName, const char* outFileName);
#pragma pack()
#endif