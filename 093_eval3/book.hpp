#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "step1.hpp"

class Book {
 private:
  std::vector<std::pair<unsigned int, Page> > pages;
  std::vector<std::pair<unsigned int, unsigned int> >
      pagestates;  //first is visited, second is previous
 public:
  Book() : pages(), pagestates() {}
  ~Book() {}
  void ReadPagesFromDir(char * Dir);
  void verifyConditions();
  void beginstory();
  void getpagestated();
  void printdepth();
  void DFS(std::vector<std::pair<unsigned int, Page> > pages,
           Page page,
           unsigned int previous_num);
};
