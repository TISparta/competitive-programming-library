// Based on tourist template: https://codeforces.com/contest/1423/submission/94770723
template <typename T>
T inverse (T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <class T, T mod>
class Modular {
private:
  T value;

public:
  constexpr Modular (): value(0) {}

  template <class U>
  Modular (const U& x) { value = normalize(x); }

  template <class U>
  static T normalize (const U& x) {
    T ret;
    if (-mod <= x and x < mod) ret = x;
    else ret = x % mod;
    if (ret < 0) ret += mod;
    return ret;
  }

  const T& operator ()() const { return value; }

  Modular& operator += (const Modular& other) { if ((value += other.value) >= mod) value -= mod; return *this; }
  Modular& operator -= (const Modular& other) { if ((value -= other.value) < 0) value += mod; return *this; }
  Modular& operator ++ () { return *this += 1; }
  Modular& operator -- () { return *this -= 1; }
  Modular operator ++ (int) { Modular ret(*this); *this += 1; return ret; }
  Modular operator -- (int) { Modular ret(*this); *this -= 1; return ret; }
  Modular operator - () const { return Modular(-value); }
  Modular& operator *= (const Modular& other) { value = normalize(1LL * value * other.value); }
  Modular& operator /= (const Modular& other) { return *this *= Modular(inverse(other.value, mod)); }

  template <class U, U umod>
  friend bool operator == (const Modular <U, umod>& lhs, const Modular <U, umod>& rhs);
  
  template <class U, U umod>
  friend bool operator < (const Modular <U, umod>& lhs, const Modular <U, umod>& rhs);

  template <class U, U umod>
  friend std::istream& operator >> (std::istream& stream, Modular <U, umod>& number);

};

template <class T, T mod>
bool operator == (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return lhs.value == rhs.value; }
template <class T, T mod, class U>
bool operator == (const Modular <T, mod>& lhs, U rhs) { return lhs == Modular <T, mod> (rhs); }
template <class U, class T, T mod>
bool operator == (U lhs, const Modular <T, mod>& rhs) { return Modular <T, mod> (lhs) == rhs; }

template <class T, T mod>
bool operator != (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return not (lhs == rhs); }
template <class T, T mod, class U>
bool operator != (const Modular <T, mod>& lhs, U rhs) { return not (lhs == rhs); }
template <class U, class T, T mod>
bool operator != (U lhs, const Modular <T, mod>& rhs) { return not (lhs == rhs); }

template <class T, T mod>
bool operator < (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return lhs.value < rhs.value; }

template <class T, T mod>
Modular <T, mod> operator + (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) += rhs; }
template <class T, T mod, class U>
Modular <T, mod> operator + (const Modular <T, mod>& lhs, U rhs) { return Modular<T, mod> (lhs) += rhs; }
template <class U, class T, T mod>
Modular <T, mod> operator + (U lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) += rhs; }

template <class T, T mod>
Modular <T, mod> operator - (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) -= rhs; }
template <class T, T mod, class U>
Modular <T, mod> operator - (const Modular <T, mod>& lhs, U rhs) { return Modular<T, mod> (lhs) -= rhs; }
template <class U, class T, T mod>
Modular <T, mod> operator - (U lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) -= rhs; }


template <class T, T mod>
Modular <T, mod> operator * (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) *= rhs; }
template <class T, T mod, class U>
Modular <T, mod> operator * (const Modular <T, mod>& lhs, U rhs) { return Modular<T, mod> (lhs) *= rhs; }
template <class U, class T, T mod>
Modular <T, mod> operator * (U lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) *= rhs; }

template <class T, T mod>
Modular <T, mod> operator / (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) /= rhs; }
template <class T, T mod, class U>
Modular <T, mod> operator / (const Modular <T, mod>& lhs, U rhs) { return Modular<T, mod> (lhs) /= rhs; }
template <class U, class T, T mod>
Modular <T, mod> operator / (U lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) /= rhs; }

template <class T, T mod, class U>
Modular <T, mod> power (Modular <T, mod> a, U b) {
  assert(b >= 0);
  Modular <T, mod> ret = 1;
  while (b != 0) {
    if (b & 1) ret *= a;
    a *= a;
    b >>= 1;
  }
  return ret;
}
template <class T, T mod, class U, U umod>
Modular <T, mod> power (Modular <T, mod> a, Modular <U, umod> b) { return power(a, b()); }
template <class U, class T, T mod>
Modular <T, mod> power (U a, Modular <T, mod> b) { return power(Modular <T, mod> (a), b()); }

template <class T, T mod>
std::ostream& operator << (std::ostream& stream, const Modular <T, mod>& number) { 
  return stream << number();
}

template <class T, T mod>
std::istream& operator >> (std::istream& stream, Modular <T, mod>& number) {
  T x;
  stream >> x;
  number.value = Modular <T, mod>::normalize(x);
  return stream;
}
