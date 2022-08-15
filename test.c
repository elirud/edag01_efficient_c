#include <stdio.h>

int main() {
   int a = 1;
   float b = 2;
   double c = 3;
   FILE* fp;

   fp = fopen("test.txt", "w");
   fprintf(fp, "%d %f %lf\n", a, b, c);
   fclose(fp);
}