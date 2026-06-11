#include <cstdio>

#define int long long
#define dotimes(i, n) for (int i : range(n))

using namespace std;

class range {
  class iterator {
    int i, s;
  public:
    iterator(int i, int s): i(i), s(s) {}
    int& operator*() {
      return i;
    }
    void operator++() {
      i += s;
    }
    bool operator!=(iterator const& that) {
      return i < that.i;
    }
  };
  iterator b, e;
public:
  range(int e): b({0, 1}), e({e, 1}) {}
  range(int b, int e): b({b, 1}), e({e, 1}) {}
  range(int b, int e, int s): b({b, s}), e({e, s}) {}
  iterator begin() {
    return b;
  }
  iterator end() {
    return e;
  }
};

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

template<typename T>
inline int size(T container) {
  return static_cast<int>(container.size());
}

template<typename T>
inline bool maxs(T& a, T const& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
inline bool mins(T& a, T const& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  const int N = rint();
  const int K = rint();
  int a[N];
  dotimes(i, N)
    a[i] = rint();
  int r = 1e12;
  dotimes(k, 1 << (N - 1)) {
    int h = a[0];
    int c = 0, s = 0;
    dotimes(i, N - 1) {
      if ((k >> i) & 1) {
        c++;
        if (!maxs(h, a[i+1]))
          s += ++h - a[i+1];
      } else if (h < a[i+1])
        goto fail;
    }
    if (c >= K - 1)
      mins(r, s);
  fail:
    ;
  }
  wint(r);
  return 0;
}
