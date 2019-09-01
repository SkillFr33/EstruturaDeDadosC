#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "simpletron.h"
#include "utils.h"

#define parseOperand(instruction) ((instruction) % operand_module)
#define parseOperation(instruction) ((instruction) / operation_module)

// Cria e aloca memória para um ponteiro para um objeto de simpletron.
// Inicializa seus membros com um valor padrão e retorna o ponteiro
Simpletron* createSimpletron() {
  Simpletron* simpletron = (Simpletron*) malloc(sizeof(Simpletron));
  if(simpletron) {
    simpletron->total_instructions = 0;
    simpletron->accumulator = 0;

    simpletron->curr_instrucion = 0;
    simpletron->curr_operand = 0;
    
    memset(simpletron->memory, 0, sizeof(simpletron->memory));
  }
  return simpletron;
}

// Lê as instruções e as armazena na memória do simpletron
void loadInstructions(Simpletron* simpletron) {
  char buffer[MAX_FGETS_INPUT];
  size_t instruction = 0;

  if(!simpletron){
    fprintf(stderr, "Erro! Ponteiro nulo passado à loadInstructions.\n");
    exit(NULL_POINTER_ERROR);
  }

  for(int i = 0; i < SIMPLETRON_MEMORY / 2; i++) {
    if(!fgets(buffer, MAX_FGETS_INPUT - 1, stdin))
      break; // encerra o loop caso a entrada seja um EOF

    instruction = strtol(buffer, NULL, 10);
    simpletron->memory[i] = instruction;
    ++(simpletron->total_instructions);
  }
}

void run(Simpletron* simpletron) {
  size_t operand = 0;
  size_t operation = 0;
  size_t total_instructions = simpletron->total_instructions;
  size_t instruction = 0;

  for(fast_int i = 0; i < total_instructions; i++){
    instruction = simpletron->memory[i];
    operand = parseOperand(instruction);
    operation = parseOperation(instruction);

    // Switch-case para identificar a operação que deve ser realizada (ver simpletron.h para mais detalhes sobre as operações)
    switch (operation) {
    case READ:
      break;
    
    default:
      fprintf(stderr, "Operação %ld inválida na posição %ld da memória!", operation, )
      break;
    } // end of switch

  } // end of for-loop
}