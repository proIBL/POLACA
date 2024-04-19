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

char elementocima(struct pila *pila){
    return pila->cima->elemento;
}

void insertar(struct pila *pila,char elemento){
    struct nodo *nuevo;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo -> elemento = elemento;
    nuevo -> siguiente = pila -> cima;
    pila -> cima = nuevo;
}

void eliminarcima(struct pila *pila){
    struct nodo *top;
    top= pila->cima;
    pila->cima = top->siguiente;
    free(top);
}

int tamanopila(struct pila *pila){
    struct nodo *temp;
    int cantidadelementos=0;
    for(temp=pila->cima; temp != NULL; temp=temp->siguiente){
        cantidadelementos++;
    }
    return cantidadelementos;
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

char* Paso3(char *P,char caracter){
    
    char *nueva_cadena = (char *)malloc((strlen(P) + 1) * sizeof(char));
    strcpy(nueva_cadena, P);
    nueva_cadena[strlen(P)] = caracter;
    return nueva_cadena;
}

void Paso4(struct pila *pila){
    insertar(pila,'(');
}

char* Paso5(struct pila *pila, char operador,char *P){
    if(operador == '+' || operador == '-'){
        while(elementocima(pila) == '+' || elementocima(pila) == '-' || elementocima(pila) == '/' || elementocima(pila) == '*' || elementocima(pila) == '^'){
            char *nueva_cadena = (char *)malloc((strlen(P) + 1) * sizeof(char));
            strcpy(nueva_cadena, P);
            nueva_cadena[strlen(P)] = elementocima(pila);
            P = nueva_cadena;
            eliminarcima(pila);
        }
    }
    else if(operador == '*' || operador == '/'){
        while(elementocima(pila) == '/' || elementocima(pila) == '*' || elementocima(pila) == '^'){
            char *nueva_cadena = (char *)malloc((strlen(P) + 1) * sizeof(char));
            strcpy(nueva_cadena, P);
            nueva_cadena[strlen(P)] = elementocima(pila);
            P = nueva_cadena;
            eliminarcima(pila);
        }
    }else if(operador == '^'){
        while(elementocima(pila) == '^'){
            char *nueva_cadena = (char *)malloc((strlen(P) + 1) * sizeof(char));
            strcpy(nueva_cadena, P);
            nueva_cadena[strlen(P)] = elementocima(pila);
            P = nueva_cadena;
            eliminarcima(pila);
        }
    }
    insertar(pila,operador);
    return P;
}

char* Paso6(struct pila *pila, char *P){
    
    while(elementocima(pila) == '+' || elementocima(pila) == '-' || elementocima(pila) == '/' || elementocima(pila) == '*' || elementocima(pila) == '^'){
        char *nueva_cadena = (char *)malloc((strlen(P) + 1) * sizeof(char));
        strcpy(nueva_cadena, P);
        nueva_cadena[strlen(P)] = elementocima(pila);
        P = nueva_cadena;
        eliminarcima(pila);
    }
    if(elementocima(pila) == '('){
        eliminarcima(pila);
    }
    return P;
}

void Paso2(char *Q, char *P, struct pila *pila){
    int i;
    
    for (i = 0; i < strlen(Q); i++){
        if (Q[i] >= '0' && Q[i] <= '9'){
            P = Paso3(P, Q[i]);
        }
        else if(Q[i] == '('){
            Paso4(pila);
        }
        else if(Q[i] == '+' || Q[i] == '-' || Q[i] == '*' || Q[i] == '/' || Q[i] == '^'){
            P = Paso5(pila, Q[i], P);
        }
        else if(Q[i] == ')'){
            P = Paso6(pila, P);
        }
        else{
            printf("Esto no sabemos que es\n");
        }
        
    }
    printf("%s\n",P);
}

void POLACA(char *Q){
    struct pila pila;
    crearpila(&pila);
    char *P = "";
    
    Q = Paso1(Q, &pila);
    Paso2(Q, P, &pila);
}

int main()
{
    POLACA("((2+312)^3+5/2)*2+8^2");

    return 0;
}