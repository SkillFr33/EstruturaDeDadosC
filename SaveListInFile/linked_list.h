#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#define     MBUFFER_SIZE  50

// valores de retorno
#define          SUCCESS  1
#define        NULL_LIST  0
#define CREATE_NODE_FAIL -1
#define SEARCH_NODE_FAIL -2
#define       EMPTY_LIST -3
#define       INVALID_ID -4
#define    GENERIC_ERROR -99 // kkkk

typedef struct node{
  int id; // identificador. Vai ser usado pra armazenar o node na posição correta do arq binário
  char buffer[MBUFFER_SIZE]; // pra armazenar uma mensagem qualquer
  struct node* next;
}Node;

typedef struct list{
  size_t size; // quantidade de nodes
  Node* head; // ponteiro pro primeiro node
}List;

List* createList();
Node* createNode();
int addNode(List* const list, const char* msg);
int push(List* const list, const char* msg); // adiciona um nó no final da lista, mesmo que ela possua 'buracos'

Node* findNode(const List* const list, const int id);
Node* prevNode(const List* const list, const int target_id); // deve ser usada apenas internamente


int printList(const List* const list);
int pop(List* const list);
int removeNode(List* const list, const int id);

#endif