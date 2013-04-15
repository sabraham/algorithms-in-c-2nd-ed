#include <stdio.h>
#include <stdlib.h>

struct bin_node {
  int key; struct bin_node *l, *r;
};

//****************************************************************************//
// unnecessary -- but don't want to throw away
//****************************************************************************//

struct stack_node {
  struct bin_node *key; struct stack_node *next;
};

int stack_is_empty (struct stack_node *head) {
  return head->next == head->next->next;
}

void push (struct stack_node *head, struct bin_node *x) {
  struct stack_node *pushed =
    (struct stack_node *) malloc(sizeof(struct stack_node));
  pushed->key = x;
  pushed->next = head->next;
  head->next = pushed;
  return;
}

struct bin_node * pop (struct stack_node *head) {
  struct stack_node *t = head->next;
  head->next = t->next;
  struct bin_node *ret = t->key;
  free(t);
  return ret;
}

//****************************************************************************//
// unnecessary -- but don't want to throw away
//****************************************************************************//

struct bin_node *bin_z;

void draw (struct bin_node *head) {
  if (head->l != bin_z) draw(head->l);
  printf("%d ", head->key);
  if (head->r != bin_z) draw(head->r);
  return;
}

// laziness..
struct bin_node * init_bin_tree () {
  bin_z = malloc(sizeof(struct bin_node));
  bin_z->l = bin_z; bin_z->r = bin_z;
  struct bin_node *h = malloc(sizeof(struct bin_node));
  struct bin_node *hl = malloc(sizeof(struct bin_node));
  struct bin_node *hr = malloc(sizeof(struct bin_node));
  struct bin_node *hll = malloc(sizeof(struct bin_node));
  struct bin_node *hlr = malloc(sizeof(struct bin_node));
  struct bin_node *hrl = malloc(sizeof(struct bin_node));
  struct bin_node *hrr = malloc(sizeof(struct bin_node));
  h->key = 3; h->l = hl; h->r = hr;
  hl->key = 1; hl->l = hll; hl->r = hlr;
  hr->key = 5; hr->l = hrl; hr->r = hrr;
  hll->key = 0; hll->l = bin_z; hll->r = bin_z;
  hlr->key = 2; hlr->l = bin_z; hlr->r = bin_z;
  hrl->key = 4; hrl->l = bin_z; hrl->r = bin_z;
  hrr->key = 6; hrr->l = bin_z; hrr->r = bin_z;
  return h;
}

int main () {
  struct bin_node *bin_head = init_bin_tree();
  draw(bin_head);
  return 0;
}
