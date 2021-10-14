/* write your class interface in this file
   write function definitions only if they are very short
 */
#include <cmath>
#include <cstdio>
#include <cstdlib>
class Vector2D {
 private:
  double x;
  double y;

 public:
  // void initVector(double init_x, double init_y) {
  //  x = init_x;
  //  y = init_y;
  //}
  Vector2D() {
    x = 0;
    y = 0;
  }
  Vector2D(int init_x, int init_y) : x(init_x), y(init_y) {}
  double getMagnitude() const { return std::sqrt(x * x + y * y); }
  Vector2D operator+(const Vector2D & rhs) const {
    Vector2D copy;
    copy.x = x + rhs.x;
    copy.y = y + rhs.y;
    return copy;
  }
  Vector2D & operator+=(const Vector2D & rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  double dot(const Vector2D & rhs) const { return x * rhs.x + y * rhs.y; }
  void print() const { std::printf("<%.2f, %.2f>", x, y); }
};
