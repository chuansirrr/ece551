#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "step1.hpp"

class Book {
 private:
  std::vector<std::pair<unsigned int, Page> > pages;
  std::vector<std::vector<unsigned int> > successstories;

 public:
  Book() : pages(), successstories() {}
  ~Book() {}
  void ReadPagesFromDir(char * Dir);
  void verifyConditions();
  void beginstory();
  void getpagestated();
  void printdepth();
  void DFS();
  void BFS();
  Page returnnext(Page node);
  bool compareRepeart(std::vector<unsigned int> storyline, unsigned int addedpagenum);
  void printsuccessstory();
};
