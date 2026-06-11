#include <bits/stdc++.h>

template <typename InputIterator>
typename InputIterator::value_type
summation(InputIterator first, InputIterator last) {
  using T = typename InputIterator::value_type;
  T *p = new T();
  const auto sum = std::accumulate(first, last, *p);
  delete p;
  return sum;
}
template <typename T>
std::istream& operator>> (std::istream &stream, std::vector<T> &v);
template <typename T1, typename T2>
std::istream& operator>> (std::istream &stream, std::pair<T1, T2> &p);
template <typename T>
std::istream& operator>> (std::istream &stream, std::vector<T> &v) {
  for (auto &i : v) {
    stream >> i;
  }
  return stream;
}
template <typename T1, typename T2>
std::istream& operator>> (std::istream &stream, std::pair<T1, T2> &p) {
  stream >> p.first >> p.second;
  return stream;
}

int main() {
  int64_t n, k;
  std::cin >> n >> k;
  std::vector<int32_t> a(n);
  std::cin >> a;
  std::sort(a.begin(), a.end());

  std::vector<std::vector<int16_t>> l(n), r(n);

  l[0].push_back(0);
  std::vector<bool> tmp(k, false);
  tmp[0] = true;

  for (int64_t i = 1; i < n; i++) {
    if (a[i - 1] < k) {
      for (const auto j : l[i - 1]) {
        if (k <= a[i - 1] + j) {
          break;
        }
        if (!tmp[a[i - 1] + j]) {
          tmp[a[i - 1] + j] = true;
        }
      }
    }
    l[i].reserve(k);
    for (int64_t j = 0; j < k; j++) {
      if (tmp[j]) {
        l[i].push_back(j);
      }
    }
  }

  r[n - 1].push_back(0);
  std::fill(tmp.begin(), tmp.end(), false);
  tmp[0] = true;

  for (int64_t i = n - 2; 0 <= i; i--) {
    if (a[i + 1] < k) {
      for (const auto j : r[i + 1]) {
        if (k <= a[i + 1] + j) {
          break;
        }
        if (!tmp[a[i + 1] + j]) {
          tmp[a[i + 1] + j] = true;
        }
      }
    }
    r[i].reserve(k);
    for (int64_t j = 0; j < k; j++) {
      if (tmp[j]) {
        r[i].push_back(j);
      }
    }
  }

  int64_t m = 0;
  bool before;

  for (int64_t i = 0; i < n; i++) {
    if (k <= a[i]) {
      break;
    }
    if (0 < i && a[i - 1] == a[i]) {
      if (before) {
        m++;
      }
      continue;
    }

    bool flag = false;
    if (l[i].size() < r[i].size()) {
      for (const auto &j : l[i]) {
        const auto max = k - 1 - j;
        const auto itr = *(--std::upper_bound(r[i].cbegin(),
          r[i].cend(), max));
        if (k <= itr + j + a[i]) {
          flag = true;
          break;
        }
      }
    } else {
      for (const auto &j : r[i]) {
        const auto max = k - 1 - j;
        const auto itr = *(--std::upper_bound(l[i].cbegin(),
          l[i].cend(), max));
        if (k <= itr + j + a[i]) {
          flag = true;
          break;
        }
      }
    }
    if (!flag) {
      m++;
      before = true;
    } else {
      before = false;
    }
  }

  std::cout << m << std::endl;
  return 0;
}
