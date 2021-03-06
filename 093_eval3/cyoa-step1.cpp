#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "step1.hpp"

int main(int argc, char ** argv) {
  // check args
  if (argc != 2) {
    std::cerr << "invalid number of arguments" << std::endl;
    exit(EXIT_FAILURE);
  }
  Page page;

  // read page information

  if (page.Readfile(argv[1]) == false) {
    std::cerr << "cannot open the file" << std::endl;
    exit(EXIT_FAILURE);
  }

  // print out this page
  page.printresult();

  return EXIT_SUCCESS;
}
