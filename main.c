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

void BST_INSERT(struct Arbol* arbol, struct Nodo* y, struct Nodo* z)
{
    //Z = to insert
    //y = to compare
    if(arbol->Root == arbol->NIL)
    {
        arbol->Root = z;
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

void RB_INSERT(struct Arbol* arbol, struct Nodo* z)
{
    //PASO 1: BST INSERTION
    BST_INSERT(arbol,arbol->NIL, z);
    z->Left = arbol->NIL;
    z->Right = arbol->NIL;
    z->isRed = true;
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
    RB_INSERT(&tree, &nodo5);
    //RB_INSERT(&tree, &nodo1);
    // printf() displays the string inside quotation
    //printf("Valor raiz = %d",raiz.Key);
    printf("\n");
    return 0;
}