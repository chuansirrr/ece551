#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

class Page {
 public:
  std::vector<std::pair<unsigned int, std::string> > navigations;
  std::vector<std::string> textOfPage;
  size_t flagofWinorLose;
  std::pair<unsigned int, unsigned int> state;
  size_t page_number;

 public:
  Page() : navigations(), textOfPage(), flagofWinorLose(0), state(0, 0), page_number(0) {}
  Page(const Page & rhs) :
      navigations(rhs.navigations),
      textOfPage(rhs.textOfPage),
      flagofWinorLose(rhs.flagofWinorLose),
      state(rhs.state),
      page_number(rhs.page_number) {}
  Page & operator=(const Page & rhs) {
    if (this != &rhs) {
      navigations = rhs.navigations;
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
