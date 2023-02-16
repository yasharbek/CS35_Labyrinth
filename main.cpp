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

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main(int argc, char** argv) {
  if (argc > 3){
    cout << "Invalid number of arguments" << endl;
    return 0;
  }

  string fileName = argv[1];
  Maze *usermaze;
  //test to make sure fileName is correct
  try {
    usermaze = loadMap(fileName); // do stuff
  } catch (runtime_error e) {
    cout << "Invalid file name." <<endl;// handle error
    return 0;
  }
  string searchType = argv[2];
  //call diff functions here
  if (searchType == "breadth"){
    List<Position*>* answer = usermaze->solveBreadthFirst();
    //here make invalid maze runtime_error***
    if (answer == nullptr){
      cout << "Sorry, no solution to the maze" << endl;
      delete usermaze;
      return 0;
    }
    else{
      cout << renderAnswer(usermaze,answer);
    }
  }
  else if(searchType == "depth"){
    List<Position*>* answer = usermaze->solveDepthFirst();
    //here make invalid maze runtime_error***
    if (answer == nullptr){
      cout << "Sorry, no solution to the maze" << endl;
      delete usermaze;
      return 0;
    }
    else{
      cout << renderAnswer(usermaze,answer);
    }
  //memory prob somewhere here
}
  else{
    cout << "Invalid search argument." << endl;
    return 0;
  }
  //delete answer;
  delete usermaze;
  return 0;
}
