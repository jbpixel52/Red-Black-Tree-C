#include <stdio.h>
#include <stdbool.h>

struct Nodo { 
    int Key; 
    bool isRed;
    struct Nodo* Padre; // parent 
    struct Nodo* Right; // right-child 
    struct Nodo* Left; // left child 
}; 

int main() 
{
    struct Nodo nodo1;
    nodo1.Key = 23;
    nodo1.isRed = true;
    struct Nodo raiz;
    raiz.Right = &nodo1;

    





    // printf() displays the string inside quotation
    printf("Arbol rojo negro");
    return 0;
}