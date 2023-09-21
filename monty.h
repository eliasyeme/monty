#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ctype.h"

#define DLM " \n\t\a\b"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct op_s - op data bundle
 * @err: error type
 * @filename: program file name
 * @tokens: where commands are saved
 * @line_number: program line number
 * @file: file pointer
 */
typedef struct op_s
{
	char err;
	char *filename;
	char **tokens;
	FILE *file;
	unsigned int line_number;
} op_t;

extern op_t op;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

int exec(void);
int err(void);
char **tokenize(char *str);
int word_len(const char *str);
int word_count(const char *str);
char *next_word(char *str);
int is_empty(const char *s);
void free_tokens(void);
unsigned int token_arr_len(void);
void free_stack(stack_t **stack);
void (*get_opfunc())(stack_t**, unsigned int);
void last_to_err(int error_code);
int check_mode(stack_t *stack);
int init_stack(stack_t **stack);
int call_func(stack_t **stack);

#endif /* MONTY_H */
