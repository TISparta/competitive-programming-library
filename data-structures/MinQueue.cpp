template <typename T>
struct MinQueue {
  // arr_1 <= arr_2 <= ... <= arr_t
  deque <T> arr;
  MinQueue () {}

  void add (T val) {
    while (not arr.empty() and val < arr.back()) arr.pop_back();
    arr.pb(val);
  }

  void remove (T val) {
    if (arr.front() == val) arr.pop_front();
  }

  T get_min () const { return arr.front(); }
};
