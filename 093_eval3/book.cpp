#include "book.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Book::ReadPagesFromDir(char * Dir) {
  char * filefullname;
  std::string filenamecp(Dir);
  size_t numofpage = 1;
  filenamecp += "/page";
  filenamecp += std::to_string(numofpage);
  filenamecp += ".txt";
}
