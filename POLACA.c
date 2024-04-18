#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Paso1(char *Q){
    int i;
    char *Q2;
    
    Q2 = (char *)malloc(strlen(Q) + 2);
    
    Q2[0] = '(';
    for (i = 1; i < strlen(Q) + 2;i++){
        Q2[i] = Q[i - 1];
    }
    Q2[strlen(Q) + 1] = ')';
    
    return Q2;
}

void P(char *Q){
    Q = Paso1(Q);
    printf("%s\n", Q);
}

int main()
{
    P("((2+312)^3+5/2)*2+8^2");

    return 0;
}
