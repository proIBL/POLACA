#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nodo{
    char elemento;
    struct nodo *siguiente;
};

struct pila{
    struct nodo *cima;
};

void crearpila(struct pila *pila){
    pila -> cima = NULL;
}

int pilavacia(struct pila *pila){
    return (pila -> cima == NULL);
}

void insertar(struct pila *pila,char elemento){
    struct nodo *nuevo;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo -> elemento = elemento;
    nuevo -> siguiente = pila -> cima;
    pila -> cima = nuevo;
}

char* Paso1(char *Q, struct pila *pila){
    int i;
    char *Q2;
    
    Q2 = (char *)malloc(strlen(Q) + 1);
    
    for (i = 0; i < strlen(Q) + 1;i++){
        Q2[i] = Q[i];
    }
    
    Q2[strlen(Q)] = ')';
    
    insertar(pila,'(');
    
    return Q2;
}

void Paso2(char *Q, struct pila *pila){
    int i;
    
    for (i = 0; i < strlen(Q); i++){
        if (Q[i] >= '0' && Q[i] <= '9'){
            printf("Este es un numero\n");
        }
        else if(Q[i] == '('){
            printf("Este es un parentesis izquierdo\n");
        }
        else if(Q[i] == '+' || Q[i] == '-' || Q[i] == '*' || Q[i] == '/' || Q[i] == '^'){
            printf("Este es un operador\n");
        }
        else if(Q[i] == ')'){
            printf("Este es un parentesis cerrando\n");
        }
        else{
            printf("Esto no sabemos que es\n");
        }
    }
}

void POLACA(char *Q){
    struct pila pila;
    crearpila(&pila);
    Q = Paso1(Q, &pila);
    Paso2(Q, &pila);
    printf("%s\n", Q);
}

int main()
{
    POLACA("((2+312)^3+5/2)*2+8^2");

    return 0;
}