#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
};

void exchange(struct node *t, struct node *u) {
  struct node *t_next = t->next;
  struct node *t_nnxt = t_next->next;
  t->next = u->next;
  u->next = t_next;
  t_next->next = t->next->next;
  t->next->next = t_nnxt;
}

struct node * init_linked_list () {
  struct node *head = (struct node *) malloc(sizeof(struct node));
  struct node *z = (struct node *) malloc(sizeof(struct node));
  head->next = z;
  z->next = z;
  return head;
}

void push (struct node *head, int x) {
  struct node *pushed = (struct node *) malloc(sizeof(struct node));
  pushed->key = x;
  pushed->next = head->next;
  head->next = pushed;
  return;
}

void print_linked_list (struct node *head) {
  for (struct node *t = head->next; t != t->next; t = t->next)
    printf("%d", t->key);
  printf("\n");  
  return;
}

int main () {
  struct node *head = init_linked_list();
  // 01234567
  for (int i = 7; i >= 0; --i) push(head, i);
  print_linked_list(head);
  // 04231567
  exchange(head->next, head->next->next->next->next);
  print_linked_list(head);
  return 0;
}
