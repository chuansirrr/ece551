#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "book.hpp"

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cerr << "invalid num of argc" << std::endl;
    exit(EXIT_FAILURE);
  }
  Book book;
  book.ReadPagesFromDir(argv[1]);
  book.verifyConditions();
  //book.beginstory();
  book.getpagestated();
  book.printdepth();
  return EXIT_SUCCESS;
}
