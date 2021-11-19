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

 public:
  Book() : pages() {}
  ~Book() {}
  void ReadPagesFromDir(char * Dir);
  void verifyConditions();
  void beginstory();
  void getpagestated();
  void printdepth();
  void DFS();
};
