/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedStack.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedStack<T>::LinkedStack() {
}

template <typename T> void LinkedStack<T>::push(T element) {
  this->newlist.insertFirst(element);
  //throw runtime_error("Not yet implemented: LinkedStack::push");
}

template <typename T> T LinkedStack<T>::pop() {
  return this->newlist.removeFirst();
  //throw runtime_error("Not yet implemented: LinkedStack::pop");
}

template <typename T> void LinkedStack<T>::insert(T element) {
  // To "insert" into a stack is to push onto it.  So when we are told to
  // insert, we will push.
  this->push(element);
}

template <typename T> T LinkedStack<T>::remove() {
  return this->pop();
  //throw runtime_error("Not yet implemented: LinkedStack::remove");
}

template <typename T> int LinkedStack<T>::getSize() {
  return this->newlist.getSize();
  //throw runtime_error("Not yet implemented: LinkedStack::getSize");
}

template <typename T> bool LinkedStack<T>::isEmpty() {
  return this->newlist.isEmpty();
  //throw runtime_error("Not yet implemented: LinkedStack::isEmpty");
}

template <typename T> T LinkedStack<T>::peek() {
  return this->newlist.getFirst();
  //throw runtime_error("Not yet implemented: LinkedStack::peek");
}
