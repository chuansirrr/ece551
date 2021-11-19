#include "book.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>
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
      onepage.page_number = numofpage;
      if (value == false) {
        std::cerr << "page1.txt not exist, wrong" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
    else {
      bool value = onepage.Readfile(filefullname);
      onepage.page_number = numofpage;
      if (value == false) {
        break;  //have read all pages
      }
    }

    std::pair<unsigned int, Page> onepagecp(numofpage, onepage);
    pages.push_back(onepagecp);
    numofpage++;
  }
}

void Book::verifyConditions() {
  //every page that is referenced by a choice is valid
  std::vector<unsigned int> reference_num;  //store the num of reference
  std::vector<size_t> storeOf_flagofWinorLose;
  std::vector<std::pair<unsigned int, Page> >::iterator it_pages = pages.begin();
  while (it_pages != pages.end()) {
    std::vector<std::pair<unsigned int, std::string> >::iterator it_navi =
        (*it_pages).second.navigations.begin();
    while (it_navi != (*it_pages).second.navigations.end()) {
      if ((*it_navi).first != 0) {
        reference_num.push_back((*it_navi).first);
        size_t refer_flag = 0;
        for (std::vector<std::pair<unsigned int, Page> >::iterator it_pagescp =
                 pages.begin();
             it_pagescp != pages.end();
             ++it_pagescp) {
          if ((*it_navi).first == (*it_pagescp).first) {
            refer_flag = 1;
          }
        }
        if (refer_flag == 0) {
          std::cerr << "not every page that is referenced by a choice is valid"
                    << std::endl;
          exit(EXIT_FAILURE);
        }
      }

      ++it_navi;
    }
    storeOf_flagofWinorLose.push_back((*it_pages).second.flagofWinorLose);
    ++it_pages;
  }
  //every page (except page 1) is referenced by at least one *other* page's choices

  std::vector<std::pair<unsigned int, Page> >::iterator it_pagescp = pages.begin();
  ++it_pagescp;
  for (; it_pagescp != pages.end(); ++it_pagescp) {
    std::vector<unsigned int>::iterator it_referencenum = reference_num.begin();
    size_t pageref_flag = 0;
    for (; it_referencenum != reference_num.end(); ++it_referencenum) {
      if ((*it_pagescp).first == (*it_referencenum)) {
        pageref_flag = 1;
      }
    }
    if (pageref_flag == 0) {
      std::cerr << "not every page (except page 1) is referenced by at least one *other* "
                   "page's choices"
                << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  //at least one page must be a WIN and at least one page must be a LOSE
  size_t flag_WIN = 0;
  size_t flag_LOSE = 0;
  std::vector<size_t>::iterator it_WL = storeOf_flagofWinorLose.begin();
  while (it_WL != storeOf_flagofWinorLose.end()) {
    if ((*it_WL) == 1) {
      flag_WIN = 1;
    }
    if ((*it_WL) == 2) {
      flag_LOSE = 1;
    }
    ++it_WL;
  }
  if (flag_LOSE == 0 || flag_WIN == 0) {
    std::cerr
        << "not at least one page must be a WIN and at least one page must be a LOSE"
        << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Book::beginstory() {
  pages[0].second.printresult();
  size_t currPageNum = 0;
  while (true) {
    if (pages[currPageNum].second.flagofWinorLose != 0) {
      return;
    }
    std::string s;
    std::getline(std::cin, s);
    size_t flag_valid = 0;
    for (size_t i = 0; i < s.length(); i++) {
      if (s[i] < 48 || s[i] > 57) {
        flag_valid = 1;
      }
    }
    unsigned int choiceNum = atoi(s.c_str());
    if (choiceNum < 1) {
      flag_valid = 1;
    }

    if (choiceNum > pages[currPageNum].second.navigations.size()) {
      flag_valid = 1;
    }
    /*
    std::vector<std::pair<unsigned int, std::string> >::iterator it_navi =
        pages[currPageNum].second.navigations.begin();
    size_t accum_notequal = 0;
    for (; it_navi != pages[currPageNum].second.navigations.end(); ++it_navi) {
      if ((*it_navi).first != choiceNum) {
        accum_notequal++;
      }
    }
    if (accum_notequal == pages[currPageNum].second.navigations.size()) {
      flag_valid = 1;
    }
    */
    if (flag_valid) {
      std::cout << "That is not a valid choice, please try again" << std::endl;
      continue;
    }
    currPageNum = pages[currPageNum].second.navigations[choiceNum - 1].first - 1;
    pages[currPageNum].second.printresult();
  }
}

void Book::getpagestated() {
  pages[0].second.state.first = 1;

  std::vector<std::pair<unsigned int, Page> >::iterator it_page = pages.begin();
  for (; it_page != pages.end(); ++it_page) {
    if ((*it_page).second.flagofWinorLose != 0) {
      continue;
    }
    else {
      std::vector<std::pair<unsigned int, std::string> >::iterator it_naviga =
          (*it_page).second.navigations.begin();
      for (; it_naviga != (*it_page).second.navigations.end(); ++it_naviga) {
        if (pages[(*it_naviga).first - 1].second.state.first == 0) {
          pages[(*it_naviga).first - 1].second.state.first = 1;
          pages[(*it_naviga).first - 1].second.state.second = (*it_page).first;
        }
        else {
          continue;
        }
      }
    }
  }
}

void Book::DFS() {
  std::stack<Page> stack_page;
  pages[0].second.state.first = 1;  //mark as visited
  stack_page.push(pages[0].second);
  while (!stack_page.empty()) {
    Page curr = stack_page.top();
    stack_page.pop();

    std::vector<std::pair<unsigned int, std::string> >::iterator it_neighbor =
        curr.navigations.begin();
    if (curr.flagofWinorLose != 0) {
      continue;
    }
    for (; it_neighbor != curr.navigations.end(); ++it_neighbor) {
      unsigned int a = 1;
      if (pages[(*it_neighbor).first - a].second.state.first == 0) {
        pages[(*it_neighbor).first - a].second.state.first = 1;
        stack_page.push(pages[(*it_neighbor).first - a].second);
        pages[(*it_neighbor).first - a].second.state.second = curr.page_number;
      }
    }
  }
}

void Book::printdepth() {
  DFS();
  std::vector<std::pair<unsigned int, Page> >::iterator it_page = pages.begin();
  for (; it_page != pages.end(); ++it_page) {
    if ((*it_page).second.state.first == 0) {
      std::cout << "Page " << (*it_page).second.page_number << " is not reachable"
                << std::endl;
    }
    else {
      size_t i = 0;
      Page curr_page = (*it_page).second;
      while (curr_page.page_number != pages[0].second.page_number) {
        curr_page = pages[curr_page.state.second - 1].second;
        i++;
      }
      std::cout << "Page " << (*it_page).second.page_number << ":" << i << std::endl;
    }
  }
}
