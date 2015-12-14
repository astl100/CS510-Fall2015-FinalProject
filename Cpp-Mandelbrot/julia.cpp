#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cplane.h"

int iterate(COMPLEX z, COMPLEX c)
{
        COMPLEX y;
        unsigned int out;

        for (out = 0; out < MAXITER; out++)
        {
                y = juliamap(z, c);

                if (sqrt(y.x*y.x + y.y*y.y) > 2)                                        {return out;}
        }

        return 0;
}

void cplane_iterate(CPLANE cp, COMPLEX c) 
{
        int i,j;
        int amount_it;

        for(i=0;i<cp.xpoints; i++)
        {
                for(j=0;j<cp.ypoints; j++)
                {
                        COMPLEX z; 
                        z = cp[i][j]; 
                        amount_it = iterate(z, c);
                }
        }
    
        printf("%Lg, %Lg, %o\n",z.x, z.y, amount_it);
} 
