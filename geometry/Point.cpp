const double EPS = 1e-6;

template <typename T>
struct Point {
  T x;
  T y;

  constexpr Point (): x(0), y(0) {}
  Point (T x, T y): x(x), y(y) {}

  Point& operator += (const Point& other) { x += other.x, y += other.y; return *this; }
  Point& operator -= (const Point& other) { x -= other.x, y -= other.y; return *this; }
  T operator *= (const Point& other) { return x * other.x + y * other.y; }
  
  bool operator == (const Point& other) { return abs(x - other.x) < EPS and abs(y - other.y) < EPS; }
  bool operator != (const Point& other) { return not (*this == other); }
  bool operator < (const Point& other) { return abs(x - other.x) < EPS ? y < other.y : x < other.x; }
  
  Point& operator += (const T& fact) { x += fact, y += fact; return *this; }
  Point& operator -= (const T& fact) { x -= fact, y -= fact; return *this; }
  Point& operator *= (const T& fact) { x *= fact, y *= fact; return *this; }
  Point& operator /= (const T& fact) { assert(abs(fact) > EPS); x /= fact, y /= fact; return *this; }

  friend Point operator + (const Point& lhs, const Point& rhs) { Point r = lhs; r += rhs; return r; }
  friend Point operator + (const Point& lhs, const T& rhs) { Point r = lhs; r += rhs; return r; }
  friend Point operator + (const T& lhs, const Point& rhs) { Point r = rhs; r += lhs; return r; }

  friend Point operator - (const Point& lhs, const Point& rhs) { Point r = lhs; r -= rhs; return r; }
  friend Point operator - (const Point& lhs, const T& rhs) { Point r = lhs; r -= rhs; return r; }
  friend Point operator - (const T& lhs, const Point& rhs) { Point r = rhs; r -= lhs; return r; }

  friend Point operator * (const Point& lhs, const Point& rhs) { Point r = lhs; r *= rhs; return r; }
  friend Point operator * (const Point& lhs, const T& rhs) { Point r = lhs; r *= rhs; return r; }
  friend Point operator * (const T& lhs, const Point& rhs) { Point r = rhs; r *= lhs; return r; }

  friend Point operator / (const Point& lhs, const T& rhs) { Point r = lhs; r /= rhs; return r; }
  friend Point operator / (const T& lhs, const Point& rhs) { Point r = rhs; r /= lhs; return r; }

  friend std::ostream& operator << (std::ostream& stream, const Point& pt) { return stream << '(' << pt.x << ", " << pt.y << ')'; }

  friend std::istream& operator >> (std::istream& stream, Point& pt) {
    T x, y;
    stream >> x >> y;
    pt.x = x;
    pt.y = y;
    return stream;
  }

  double norm () const { return sqrt(1.0 * x * x + 1.0 * y * y); }
  T norm2 () const { return x * x + y * y; }
  Point rotate (double beta) const { return Point(cos(beta) * x - sin(beta) * y, sin(beta) * x + cos(beta) * y); }
  Point rotate90 () const { return Point(-y, x); }

};
