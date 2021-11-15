#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

class Page {
 public:
  std::vector<std::pair<unsigned int, std::string> > navigations;
  std::vector<std::string> textOfPage;
  size_t flagofWinorLose;

 public:
  Page() : navigations(), textOfPage(), flagofWinorLose(0) {}
  Page(const Page & rhs) :
      navigations(rhs.navigations),
      textOfPage(rhs.textOfPage),
      flagofWinorLose(rhs.flagofWinorLose) {}
  Page & operator=(const Page & rhs) {
    if (this != &rhs) {
      navigations = rhs.navigations;
      textOfPage = rhs.textOfPage;
      flagofWinorLose = rhs.flagofWinorLose;
    }
    return *this;
  }
  ~Page() {}

  bool Readfile(char * filenam);
  void getNavigations(std::vector<std::string> navigations_cp);
  void getTextOfPage(std::vector<std::string> textOfPage_cp);
  void printresult();
  std::string getnumber(std::string textline);
  std::string getText(std::string textline);
};
