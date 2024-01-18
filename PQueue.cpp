/*
 * LaQueue
 *
 *
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *
 * (c) copyright 2018, James Shockey - all rights reserved
 *
 * */

#include "PQueue.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

/*
 * Class Priority Queue
 */

/*
 * Insert into Priority Queue
 */
void PQueue::push(void *item, int priority) {
  node *temp = new node;
  temp->data = item;
  temp->priority = priority;
  if (front == NULL) {
    front = temp;
  } else {
    node *current = front;
    while ((current->link != NULL) && (temp->priority < current->priority)) {
      current = current->link;
    }
    temp->link = current->link;
    current->link = temp;
  }
}

/*
 * Delete from Priority Queue
 */
void *PQueue::top() {
  if (front == NULL) {
    return front;
  } else {
    return front->data;
  }
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop() {
  if (front != NULL) {
    front = front->link;
  }
}

/*
 * Print Priority Queue
 */
void PQueue::display() {
  node *current = front;
  while (current != NULL) {
    std::cout << current->priority << " " << (char *)current->data << std::endl;
    current = current->link;
  }
}
