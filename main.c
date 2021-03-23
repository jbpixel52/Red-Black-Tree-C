#include <stdio.h>
#include <stdbool.h>

//   1. Every node is either red or black.
//   2.   The root is black.
//   3.   Every leaf (NIL) is black.
//   4.   If a node is red, then both its children are black.
//    5.   For each node, all simple paths from the node to descendant 
//        leaves contain thesame number of black nodes.

struct Nodo 
{ 
    int Key; 
    bool isRed;
    struct Nodo* Padre; // parent 
    struct Nodo* Right; // right-child 
    struct Nodo* Left; // left child 
}; 

struct Arbol
{
    struct Nodo* Root; // raiz
    struct Nodo* NIL; //NIL
};

void LEFT_ROTATE(struct Arbol* arbol, struct Nodo* z)
{

}

void BST_INSERT(struct Arbol* arbol, struct Nodo* y, struct Nodo* z)
{
    //Z = to insert
    //y = to compare
    if(arbol->Root == arbol->NIL)
    {
        arbol->Root = z;
        //Diagrama B del libro, los NILS crean un ciclo
        arbol->Root->Padre = arbol->NIL;
        return;
    }
    else if(arbol->Root !=arbol->NIL)
    {
        if(y==arbol->NIL)
        {
            //Si es altura 0, comparemos con raiz
            y=arbol->Root;
        }
        //Si hay raiz comenzemos a comparar
        if(z->Key < y->Key)
        {
            //Vamos a la izquierda
            if(y->Left==arbol->NIL)
            {
                y->Left = z;
                z->Padre = y;
            }
            else
            {
                BST_INSERT(arbol, y->Left, z);
            }

        }
        else if( z->Key > y->Key)
        {
            //Vamos a la derecha
            if(y->Right==arbol->NIL)
            {
                y->Right = z;
                z->Padre = y;
            }
            else
            {
                BST_INSERT(arbol, y->Right, z);
            }
        }
    }
}

void RB_INSERT_FIXUP(struct Arbol* arbol, struct Nodo* z)
{
    struct Nodo* y;
    while(z->Padre->isRed)
    {
        //Si Z esta del lado izquierdo de su abuelo
        if(z->Padre == z->Padre->Padre->Left)
        {
            //Y es igual al TIO
            y = z->Padre->Padre->Right;
            if(y->isRed)
            {
                z->Padre->isRed = false;
                y->isRed = false;
                z->Padre->Padre->isRed = true;
                z = z->Padre->Padre;
            }
            else if(z == z->Padre->Right)
            {
                z = z->Padre;
                //Left rotate(T,z);
            }
            //Hacer padre negro y abuelo rojo para
            //  cumplir condiciones de no 2 rojos
            z->Padre->isRed = false;
            z->Padre->Padre->isRed = true;
            //Right rotate(T, z);
        }
        //Si z esta del lado derecho del abuelo
        else if(z->Padre == z->Padre->Padre->Right)
        {
            //Mismo pero left y right reverso
            //Y es igual al TIO
            y = z->Padre->Padre->Left;
            if(y->isRed)
            {
                z->Padre->isRed = false;
                y->isRed = false;
                z->Padre->Padre->isRed = true;
                z = z->Padre->Padre;
            }
            else if(z == z->Padre->Left)
            {
                z = z->Padre;
                //Left rotate(T,z);
            }
            //Hacer padre negro y abuelo rojo para
            //  cumplir condiciones de no 2 rojos
            z->Padre->isRed = false;
            z->Padre->Padre->isRed = true;
             //Right rotate(T, z);
        }
        arbol->Root->isRed = false;
    }
}

void RB_INSERT(struct Arbol* arbol, struct Nodo* z)
{
    //z es el nodo por insertar
    //PASO 1: BST INSERTION con color rojo
    BST_INSERT(arbol,arbol->NIL, z);
    z->Left = arbol->NIL;
    z->Right = arbol->NIL;
    z->isRed = true;
    //PASO 2: RB Insert FIXUP pagina 316
    RB_INSERT_FIXUP(arbol,z);

}

int main() 
{
    //Definir arbol y sentinela
    struct Arbol tree;
    struct Nodo sentinela;
    
    sentinela.Key = 0;
    sentinela.Left = NULL;
    sentinela.Right = NULL;
    tree.NIL = &sentinela;
    tree.Root = tree.NIL;

    struct Nodo nodo1;
    nodo1.Key = 23;
    struct Nodo nodo2;
    nodo2.Key = 17;
    struct Nodo nodo3;
    nodo3.Key = 16;
    struct Nodo nodo4;
    nodo4.Key = 28;
    struct Nodo nodo5;
    nodo5.Key = 19;

    RB_INSERT(&tree, &nodo1);
    RB_INSERT(&tree, &nodo2);
    RB_INSERT(&tree, &nodo3);
    RB_INSERT(&tree, &nodo4);
    //Este uktimo es para breakpoint
    RB_INSERT(&tree, &nodo5);
    //RB_INSERT(&tree, &nodo1);
    // printf() displays the string inside quotation
    //printf("Valor raiz = %d",raiz.Key);
    printf("\n");
    return 0;
}