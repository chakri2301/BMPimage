#include<stdio.h>
#include"./bmp.h"
FILE* file;
int main(){
    printf("Start of Image Creation\n");
    file = fopen("./pic.bmp", "wb");
    BmpHeader header;
    header.type = 0x424D;
    header.size = 0;
    header.reserved1 = 0;
    header.reserved2 = 0;
    header.offset = 54;
    BmpInfoHeader iHeader;
    iHeader.size = 14;
    iHeader.width = 2;
    iHeader.height = 2;
    iHeader.planes = 1;
    iHeader.bits= 24;
    iHeader.compression= 0;
    iHeader.imagesize = 3*iHeader.height*iHeader.width;
    
    
    printf("End of Image Creation\n");
}