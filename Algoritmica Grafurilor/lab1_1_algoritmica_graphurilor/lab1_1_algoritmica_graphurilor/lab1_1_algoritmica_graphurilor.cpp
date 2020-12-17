#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
 FILE *fin, *fout;
 int c;
 if (argc != 3) {
 fprintf(stderr, "Utilizare : copy sursa dest \n");
 exit(1);
 }
 if ((fin = fopen(argv[1], "rt")) == NULL) {
 fprintf(stderr, "Eroare deschidere fisier %s \n", argv[1]);
 exit(1);
 }
 if ((fout = fopen(argv[2], "wt")) == NULL) {
 fprintf(stderr, "Eroare deschidere fisier %s \n", argv[2]);
 exit(1);
 }
 c = getc(fin);
 while (c != EOF) {
 fputc(c, fout);
 c = fgetc(fin);
 }
 fclose(fin);
 fclose(fout);
 return 0;
 } 
