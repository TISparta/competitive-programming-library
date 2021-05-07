template <typename T>
struct Circle {
  Point <T> c;
  T r;

  constexpr Circle (): c(0, 0), r(0) {}
  Circle (Point <T> c, T r): c(c), r(r) {}
  Circle (T x, T y, T r): c(x, y), r(r) {}

  tuple <Point <T>, Point <T>, bool> intersect (Circle other) const {
    if ((r + other.r) * (r + other.r) < (other.c - c).norm2()) return {Point <T>(), Point <T>(), false};
    if ((r - other.r) * (r - other.r) > (other.c - c).norm2()) return {Point <T>(), Point <T>(), false};
    double d = (other.c - c).norm();
    double b = 0.5 * (d + (r * r - other.r * other.r) / d);
    Point p = c + ((other.c - c) / d) * b;
    double h = sqrt(r * r - b * b);
    Point dir = (((other.c - c) / d) * h).rotate90();
    return {p + dir, p - dir, true};
  }

};
