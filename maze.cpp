/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"

#include "maze.h"

using namespace std;

Maze::Maze(int width, int height) {
  this->width = width;
  this->height = height;
  //creates array of pointers with size of the given width
  this->Positions = new Position**[this->width];
  //first for loop goes through each element in the array above and has each pointer
  //    point to an array with size height
  for (int i = 0; i < this->width; i++){
    this->Positions[i]  = new Position*[this->height]; //loop
    //this for loop creates an x and y value for a Position variable using the width and height
    for (int j = 0; j < this->height; j++){
      this->Positions[i][j] = new Position(i,j);
    }
  }
}

Maze::~Maze() {
  for (int i = 0; i<this->width; i++){
    for (int j = 0; j<this->height; j++){
      delete Positions[i][j];//deletes the x and y
    }
    delete [] Positions[i];//deletes the array in each array[i]
  }
  delete Positions[]//deletes arrays


  //Positions->nullptr;//might need ***don't forget!!
}

int Maze::getWidth() {
  return this->width;
}

int Maze::getHeight() {
  return this->height;
}

bool Maze::isWall(int x, int y) {
  return this->Position[x][y]->iswall();
}

void Maze::setWall(int x, int y) {
  this->Position[x][y]->setwall();
}

List<Position*>* Maze::getNeighbors(Position* position) {//pointer that points to an x&y value
  int x = position->getX(); //3
  int y = position->getY(); //4

  List<Position*>* ListNeighbors = new STLList<Position*>
  //need to look at left, right, top, and bottom
  if (x!=0 && this->Positions[x-1][y]->isWall()==false)){
    ListNeighbors->insertFirst(this->Positions[x-1][y]); //insert aqui
  }
  if (x!=this->getWidth() && this->Positions[x+1][y]->isWall()==false)){
    ListNeighbors->insertFirst(this->Positions[x+1][y]); //insert aqui
  }
  if (y!=0 && this->Positions[x][y-1]->isWall()==false)){
    ListNeighbors->insertFirst(this->Positions[x][y-1]); //insert aqui
  }
  if (y!=this->getWidth() && this->Positions[x][y+1]->isWall()==false)){
    ListNeighbors->insertFirst(this->Positions[x][y+1]); //insert aqui
  }
return ListNeighbors;

}

//call 'solve' on both functions below
List<Position*>* Maze::solveBreadthFirst() {
  OrderedCollection<Position*>* breadthFirst = new LinkedQueue<Position*>;
  return solve(breadthFirst);
  //solve(breadthFirst) --> use queues
}

List<Position*>* Maze::solveDepthFirst() {
  OrderedCollection<Position*>* depthFirst = new LinkedStack<Position*>;
  return solve(solvedepthFirst);
  //solve(depthFirst) --> use stacks
}

//this is where most of the solving is going to go
List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
  //exploration: variable used to store unvisited positions --> start with 0,0
  //use getNeighbors & methods to add correct neighbors to exploration
  //need loop return the path and need function to go through neighbors
  List<Posistion*>* solvedPath = STLList<Position*>
  /*while posistions left:
      remove posistion-->  call it current** (how to remove?)
      if current is exit, return
      elif-->
          mark neighbor as visited
          record current position
          add neighbor to data structure
  */
  exploration->insert(this->Positions[0][0]);
  //first position starts off as visited**
  this->Positions[0][0] = setVisited();
  //need list of neighbors to go through each
  //also use getNeighbors function --> current for paramater
  while(exploration->isEmpty()==false){
    //gonna keep going throught while loop till empty
    Position* current = exploration->remove();//remove()?
    //use width and height for exit
    if (current->getX()==this->width-1 && current->getY(==this->height-1){//if exit
      //break loop? --> go backwards
      //**use insert first to create the pathway in the right order
      solvedPath->insertFirst(current);
      //stop when reach a nullptr
      while (current->getPrevious() != nullptr){
        //insert previous of current into pathway
        solvedPath->insertFirst(current->getPrevious());
        //make current previous to go backwards
        current = current->getPrevious();
      }
      return solvedPath
    }
    List<Position*>* neighborList = this->getNeighbors(current);
    //can i use the get() function for this??
    //does neighbor[i] work??***
    for (int i = 0; neighborList->getSize();i++){
      /*Position* N = neighborList->get(i);
      if (neighborList->get(i)->isVisited()){
      neighborList->get(i)->setVisited();
      neighborList->get(i)->setPrevious(current);
      //add to exploration
      exploration->insert(neighborList->get(i));
      */
      if (neighborList->get(i)->isVisited()){
        neighborList->get(i)->setVisited();
        neighborList->get(i)->setPrevious(current);
        //add to exploration
        exploration->insert(neighborList->get(i));
      }
    }
    //delete stuff after while loop aqui:
    delete neighborList;
  }
  //have to delete the returned path and return null if cant reach position[w][h]
  //since exploration is a list delete - ninja
  delete exploration;
  return nullptr;
}
