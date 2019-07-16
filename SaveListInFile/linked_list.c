#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

List* createList() {
  
  List* list = (List*) malloc( sizeof(List) );
  if(list != NULL) {
    list->size = 0;
    list->head = NULL;
    list->end = NULL;
  }

  return list; // depois do retorno no código cliente, verificar se a list é NULL
}

Node* createNode() {

  Node* new_node = (Node*) malloc( sizeof(Node) );
  if(new_node != NULL) { 
    new_node->id = -1;
    new_node->next = NULL;
  }

  return new_node; // depois do retorno, verificar se new_node é NULL
}

Node* findNode(const List* const list, const int index) {
  Node* aux = list->head;
  while(aux != NULL && aux->id != index)
    aux = aux->next;

  return aux;
}


int addNode(List* const list, const char* msg) {
  if(list == NULL)
    return NULL_LIST;

  Node* new_node = createNode();
  if(new_node == NULL)
    return CREATE_NODE_FAIL;

  new_node->id = list->curr_id;
  strcpy(new_node->buffer, msg);
  
  if(list->head == NULL){
    list->head = new_node;
    list->end = new_node;
  }  
  else if (list->curr_id == list->size) { // significa que o node será colocado no final da lista
    list->end->next = new_node;
    list->end = new_node;
  }
  else { // node vai ser colocado na posição curr_id da lista
    //pegando o node anterior da posição que eu quero colocar meu novo node
    Node* aux = findNode(list, list->curr_id - 1);
    if(aux == NULL)
      return SEARCH_NODE_FAIL;
    
    new_node->next = aux->next;
    aux->next = new_node;
  }
  
  ++list->size;
  list->curr_id = list->size;

  return SUCCESS;
}

int pop(List* const list) {
  if(list == NULL)
    return NULL_LIST;
  else if(list->head == NULL)
    return EMPTY_LIST;

  list->curr_id = list->end->id; // salva o id do último nó, que será o id do próximo nó a ser adicionado
  free(list->end);
  
  if(list->head->next == NULL){
    list->end = NULL;
    list->head = NULL;
  }
  else{
    //como dei free em list->end, tive que usar list->curr_id no lugar de list->end->id
    Node* aux = findNode(list, list->curr_id - 1); // pega nó anterior ao último
    if(aux == NULL)
      return SEARCH_NODE_FAIL;

    aux->next = NULL;
    list->end = aux;
  }

  --list->size;

  return SUCCESS;
}

int removeNode(List* const list, const int index) {
  if(list == NULL)
    return NULL_LIST;
  else if(list->head == NULL)
    return EMPTY_LIST;
  else if(index < 0)
    return INVALID_INDEX;



  return SUCCESS;

}

int printList(const List* const list) {
  if(list == NULL) {
    fprintf(stderr, "Lista nula!\n");
    return NULL_LIST;
  }
  else if(list->head == NULL) {
    fprintf(stderr, "Lista vazia!\n");
    return EMPTY_LIST;
  }

  Node* aux = list->head;
  while(aux != NULL){
    printf("%d | %s\n", aux->id, aux->buffer);
    aux = aux->next;
  }

  return SUCCESS;
}