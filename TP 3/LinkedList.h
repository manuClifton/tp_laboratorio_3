/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //crea linked list
int ll_len(LinkedList* this); //devuelve la cantidad de cosas en la linked
Node* test_getNode(LinkedList* this, int nodeIndex); //
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//agrega un elemento
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement); //pisa un elemento
int ll_remove(LinkedList* this,int index);// elimina
int ll_clear(LinkedList* this);// limpia la linked
int ll_deleteLinkedList(LinkedList* this);// libera la memoria
int ll_indexOf(LinkedList* this, void* pElement);   // devuelve el entero el indice si esta
int ll_isEmpty(LinkedList* this); // dice si esta vacio o no
int ll_push(LinkedList* this, int index, void* pElement); // empuja
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement); // dice si esta el elemento o no
int ll_containsAll(LinkedList* this,LinkedList* this2); // dice si los elementeo de una linked list estan en el primero
LinkedList* ll_subList(LinkedList* this,int from,int to); //crea un subconjunto de esa linked list
LinkedList* ll_clone(LinkedList* this); // clona la linkedlist y devuelve el primer elemento de la linkedlist
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); // ordenamiento de la linked list
