/* cc oscilador.c -o oscilador -lm && ./oscilador */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct estado_s { double Q, P; } estado_t ;
double gamma;

static inline double dot_Q(estado_t sistema){
   return (sistema.P);
}
static inline double dot_P(estado_t sistema){
   return (-(sistema.Q + gamma * sistema.P) + 1.0);
}

int main(void){
   estado_t sistema;
   double tf, t, dt, dt2;
   FILE *arq;

   arq = fopen("oscilador.dat", "w");
   if(!arq){
      fputs("Erro ao abrir arquivo", stderr);
      return EXIT_FAILURE;
   }

   gamma = 0.5;

   sistema.Q = 0.0;
   sistema.P = 0.0;

   dt = 1.0e-1;
   dt2 = 0.5 * dt;
   tf = 10.0;
   t = 0.0;
 
   while(t < tf){

      sistema.Q += dot_Q(sistema) * dt2;
      sistema.P += dot_P(sistema) * dt;
      sistema.Q += dot_Q(sistema) * dt2;
      t += dt;

      fprintf(arq, "%g %g %g\n", t, sistema.Q, sistema.P);
   }
   fclose(arq);

   return EXIT_SUCCESS;
}
