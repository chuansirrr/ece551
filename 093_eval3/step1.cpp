#include "step1.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool Page::Readfile(std::ifstream & f) {
  //store every line of text in the string in vector
  std::vector<std::string> allTextLine;

  while (!f.eof()) {
    std::string temps;
    std::getline(f, temps);
    allTextLine.push_back(temps.c_str());
  }
  std::vector<std::string>::iterator it = allTextLine.begin();
  std::vector<std::string> navigations_cp;
  std::vector<std::string> textOfPage_cp;
  size_t flag_hash = 0;
  size_t flag_text = 0;
  while (it != allTextLine.end()) {
    if ((*it)[0] != '#' && flag_text == 0) {
      navigations_cp.push_back(*it);
    }
    else if ((*it)[0] == '#' && flag_text == 0) {
      flag_hash = 1;
      flag_text = 1;
    }
    else {
      textOfPage_cp.push_back(*it);
    }
    ++it;
  }

  if (flag_hash == 0) {
    std::cerr << "no hash in the text, incorrect form" << std::endl;
    exit(EXIT_FAILURE);
  }
  getNavigations(navigations_cp);
  getTextOfPage(textOfPage_cp);
  f.close();
  return true;
}

void Page::getNavigations(std::vector<std::string> navigations_cp) {
  std::string number;
  unsigned int num;
  std::string textOfChoice;
  std::vector<std::string>::iterator it = navigations_cp.begin();
  std::vector<std::pair<unsigned int, std::string> > init_navigat;
  while (it != navigations_cp.end()) {
    if (((navigations_cp)[0] == "WIN" || (navigations_cp)[0] == "LOSE") &&
        navigations_cp.size() == 1) {
      num = 0;
      if ((navigations_cp)[0] == "WIN") {
        flagofWinorLose = 1;
      }
      if ((navigations_cp)[0] == "LOSE") {
        flagofWinorLose = 2;
      }
    }
    else if (((navigations_cp)[0] == "WIN" || (navigations_cp)[0] == "LOSE") &&
             navigations_cp.size() != 1) {
      std::cerr << "If WIN or LOSE, more than 1 line, incorrect form" << std::endl;
      exit(EXIT_FAILURE);
    }
    else {
      number = getnumber(*it);
      num = atoi(number.c_str());
      textOfChoice = getText(*it);
    }
    init_navigat.push_back(std::pair<unsigned int, std::string>(num, textOfChoice));
    ++it;
  }
  navigations = init_navigat;
}

void Page::printresult() {
  std::vector<std::string>::iterator it = textOfPage.begin();
  while (it != textOfPage.end()) {
    std::cout << *it << std::endl;
    ++it;
  }
  if (flagofWinorLose == 1) {
    std::cout << "Congratulations! You have won. Hooray!" << std::endl;
  }
  if (flagofWinorLose == 2) {
    std::cout << "Sorry, you have lost. Better luck next time!" << std::endl;
  }
  if (flagofWinorLose == 0) {
    std::cout << "What would you like to do ?" << std::endl;
    std::cout << std::endl;
    std::vector<std::pair<unsigned, std::string> >::iterator it = navigations.begin();
    unsigned i = 1;
    while (it != navigations.end()) {
      std::cout << " " << i << ". ";
      std::cout << it->second << std::endl;
      ++it;
      ++i;
    }
  }
}

std::string Page::getnumber(std::string textline) {
  int index = textline.find(':');
  if (index == -1) {
    std::cerr << "no colon, incorrect form" << std::endl;
    exit(EXIT_FAILURE);
  }
  size_t flagIsNum = 1;
  for (int i = 0; i < index; i++) {
    if (isdigit(textline[i]) == 0) {
      flagIsNum = 0;
    }
  }
  if (flagIsNum == 0) {
    std::cerr << "not valid num, incorrect form" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string number(textline.substr(0, index + 1));
  //std::string textOfChoice(textline.substr(++index));
  return number;
}

std::string Page::getText(std::string textline) {
  size_t index = textline.find_first_of(':');
  std::string textOfChoice(textline.substr(++index));
  return textOfChoice;
}

void Page::getTextOfPage(std::vector<std::string> textOfPage_cp) {
  textOfPage = textOfPage_cp;
}
