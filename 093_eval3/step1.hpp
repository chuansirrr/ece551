#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

class Page {
 public:
  std::vector<std::pair<unsigned int, std::string> > navigations;
  std::vector<unsigned int> navigations_all_flag;
  std::vector<std::string> textOfPage;
  size_t flagofWinorLose;
  std::pair<unsigned int, unsigned int>
      state;  //In BFS, first is dist, second is previous
  size_t page_number;

 public:
  Page() :
      navigations(),
      navigations_all_flag(),
      textOfPage(),
      flagofWinorLose(0),
      state(0, 0),
      page_number(0) {}
  Page(const Page & rhs) :
      navigations(rhs.navigations),
      navigations_all_flag(rhs.navigations_all_flag),
      textOfPage(rhs.textOfPage),
      flagofWinorLose(rhs.flagofWinorLose),
      state(rhs.state),
      page_number(rhs.page_number) {}
  Page & operator=(const Page & rhs) {
    if (this != &rhs) {
      navigations = rhs.navigations;
      navigations_all_flag = rhs.navigations_all_flag;
      textOfPage = rhs.textOfPage;
      flagofWinorLose = rhs.flagofWinorLose;
      state = rhs.state;
      page_number = rhs.page_number;
    }
    return *this;
  }
  ~Page() {}

  bool Readfile(const char * filenam);
  void getNavigations(std::vector<std::string> navigations_cp);
  void getTextOfPage(std::vector<std::string> textOfPage_cp);
  void printresult();
  std::string getnumber(std::string textline);
  std::string getText(std::string textline);
};
