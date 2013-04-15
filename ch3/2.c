struct node {
  int key; struct node *node next;
};

void move_next_to_front (struct node *t) {
  struct node *new_front = t->next;
  t->next = t->next->next;
  new_front->next = head->next;
  head->next = new_front;
}
