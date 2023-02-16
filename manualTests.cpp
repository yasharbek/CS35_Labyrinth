/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "linkedStack.h"
#include "linkedQueue.h"
#include "maze.h"
// TODO: put #includes here

using namespace std;

int main() {

  Maze newMaze = new Maze(4,3);
  cout >> newMaze->getWidth() >>endl;

/*
  LinkedQueue<int>* list1 = new LinkedQueue<int>();
  cout << list1->isEmpty() << endl;
  list1->insert(4);
  list1->insert(7);
  cout << list1->getSize() << endl;
  cout << list1->remove() << endl;
  cout << list1->isEmpty() << endl;
  cout << list1->peek() << endl;
  cout << list1->getSize() << endl;

  LinkedStack<int>* list1 = new LinkedStack<int>();
  cout << list1->isEmpty() << endl;
  list1->insert(4);
  list1->insert(7);
  cout << list1->getSize() << endl;
  cout << list1->remove() << endl;
  cout << list1->isEmpty() << endl;
  cout << list1->peek() << endl;
  cout << list1->getSize() << endl;

*/
  return 0;
}
