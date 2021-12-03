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
  std::vector<std::pair<unsigned int, Page> > pages;  //store all the pages
  std::vector<std::vector<unsigned int> >
      successstories;  //store all the path from page1 to WIN or LOSE

 public:
  Book() : pages(), successstories() {}
  ~Book() {}
  void ReadPagesFromDir(char * Dir);
  void verifyConditions();
  void beginstory();
  void printdepth();
  void DFS();
  void DFS_for_step4();
  bool compareRepeart(std::vector<unsigned int> storyline, unsigned int addedpagenum);
  void printsuccessstory();
};
