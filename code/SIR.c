/* cc SIR.c -o SIR -lm && ./SIR */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct estado_s { double S, I, R; } estado_t;
double alpha;

static inline double dot_S(estado_t sistema){
   return (alpha * sistema.S * sistema.I);
}
static inline double dot_R(estado_t sistema){
   return (sistema.I);
}
static inline double N(estado_t sistema){
   return (sistema.S + sistema.I + sistema.R);
}

int main(void){
   estado_t sistema;
   double tf, t, dt, k_S, k_I;
   FILE *arq;

   arq = fopen("SIR.dat", "w");
   if(!arq){
      fputs("Erro ao abrir arquivo", stderr);
      return EXIT_FAILURE;
   }

   alpha = 5.;

   sistema.S = 0.9;
   sistema.I = 1.0 - sistema.S;
   sistema.R = 0.0;

   dt = 1.0e-1;
   tf = 10.0;
   t = 0.0;
 
   while(t < tf){
      k_S = dot_S(sistema) * dt;
      k_I = dot_R(sistema) * dt;

      sistema.S -= k_S;
      sistema.I += k_S - k_I;
      sistema.R += k_I;
      t += dt;

      if(fabs(N(sistema) - 1.0) > 1.0e-8){
         fputs("A populacao nao estah conservando.\n", stderr);
         break;
      }
      fprintf(arq, "%g %g %g %g \n", t, sistema.S, sistema.I, sistema.R);
   }
   fclose(arq);

   return EXIT_SUCCESS;
}
