/*
 * Search an expression using DFS.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */
#include "dfs.h"

void DFT(node *root) // Implement DFS
{
  stack *new_stack = malloc(sizeof(stack)); // Creating new stack
  push(new_stack, root);                    // Calling push to place the root into the stack
  new_stack->next = NULL;                   // new->next is at NULL from the beginning

  while (!(isEmpty)(new_stack)) // loop until stack is empty
  {
    stack *q = pop(new_stack);
    if (q->node->rchild != NULL)
    {
      push(new_stack, q->node->rchild); // call push function with the new stack and right child as arguments
    }
    if (q->node->lchild)
    {
      push(new_stack, q->node->lchild); // same with left child. Push to stack when found
    }
  }

  // step 1: Allocate memory for node
  // step 2: Check if l-child and r-child are pointing at nothing to see if we have reached the depth of the tree
  // Hint: You can use print_node, print_tree and/or print_stack.
}

node *make_node(int num, node *left, node *right)
{
  node *new_node = malloc(sizeof(node)); // node depends on leftchild, rightchild, number, and if we have been there before
  new_node->lchild = left;
  new_node->num = num;
  new_node->rchild = right;
  new_node->visited = false;
  return new_node;
}

void free_node(node *p)
{
}

void print_node(node *p)
{

  if (p == NULL)
    printf("NULL\n");
  else
    printf("%d", p->num);
}

void print_tree(node *p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild)
  {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node)
{
  stack *element = malloc(sizeof(stack));
  element->next = topp->next;
  element->node = node;
  topp->next = element;
  return 0;
}

bool isEmpty(stack *topp) // if stack is empty
{
  if (topp->next = NULL)
    return true;
  else
    return false;
}

node *top(stack *topp)
{
  return topp->node;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp)
{
  stack *Popped_element = 0;
  Popped_element = topp->next;
  topp->next = topp->next->next;
}

void print_stack(stack *topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
  {

    print_node(temp->node);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
}
