/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedQueue.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedQueue<T>::LinkedQueue() {
}

template <typename T> int LinkedQueue<T>::getSize() {
  return this->newlist.getSize();
  //throw runtime_error("Not yet implemented: LinkedQueue::getSize");
}

template <typename T> bool LinkedQueue<T>::isEmpty() {
  return this->newlist.isEmpty();
  //throw runtime_error("Not yet implemented: LinkedQueue::isEmpty");
}

template <typename T> T LinkedQueue<T>::peek() {
  return this->newlist.getFirst();
  //throw runtime_error("Not yet implemented: LinkedQueue::peek");
}

template <typename T> void LinkedQueue<T>::enqueue(T element) {
  this->newlist.insertLast(element);
  //throw runtime_error("Not yet implemented: LinkedQueue::enqueue");
}

template <typename T> T LinkedQueue<T>::dequeue() {
  return this->newlist.removeFirst();
  //throw runtime_error("Not yet implemented: LinkedQueue::dequeue");
}

template <typename T> void LinkedQueue<T>::insert(T element) {
  this->enqueue(element);
  // NOTE: for a hint on how to implement this, see LinkedStack<T>::insert
  //throw runtime_error("Not yet implemented: LinkedQueue::insert");
}

template <typename T> T LinkedQueue<T>::remove() {
  return this->dequeue();
  //throw runtime_error("Not yet implemented: LinkedQueue::remove");
}
