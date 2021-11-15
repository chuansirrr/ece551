#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "step1.hpp"

class Book {
 private:
  std::vector<Page> pages;

 public:
  Book() : pages() {}
  ~Book() {}
  void ReadPagesFromDir(char * Dir);
};
