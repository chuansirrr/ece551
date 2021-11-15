#include "book.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Book::ReadPagesFromDir(char * Dir) {
  size_t numofpage = 1;
  while (true) {
    std::string filenamecp(Dir);

    filenamecp += "/page";
    filenamecp += std::to_string(numofpage);
    filenamecp += ".txt";
    const char * filefullname = filenamecp.c_str();

    Page onepage;
    if (numofpage == 1) {
      bool value = onepage.Readfile(filefullname);
      if (value == false) {
        std::cerr << "page1.txt not exist, wrong" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
    else {
      bool value = onepage.Readfile(filefullname);
      if (value == false) {
        break;  //have read all pages
      }
    }
    std::pair<unsigned int, Page> onepagecp(numofpage, onepage);
    pages.push_back(onepagecp);
    numofpage++;
  }
}
