#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

template <class RandomIt>
auto rsort(RandomIt first, RandomIt last)
  -> typename std::enable_if<std::is_integral<
    typename RandomIt::value_type::first_type>::value>::type
{
  using PairType = typename RandomIt::value_type;
  using KeyType = typename PairType::first_type;

  intmax_t cur_shift=0, max_exp=sizeof(KeyType);
  std::vector<PairType> work(last-first);
  for (int i=0; i<max_exp; ++i) {
    size_t num[256]={};

    for (RandomIt it=first; it<last; ++it)
      ++num[((it->first)>>cur_shift)&255];

    {
      size_t tmp=0;
      for (int j=0; j<256; ++j)
        std::swap(tmp, num[j]+=tmp);
    }

    for (RandomIt it=first; it<last; ++it)
      work[num[((it->first)>>cur_shift)&255]++] = std::move(*it);

    {
      size_t j=0;
      for (RandomIt it=first; it<last; ++it)
        *it = std::move(work[j++]);
    }

    cur_shift += 8;
  }

  if (!std::is_signed<KeyType>::value) return;

  RandomIt mid=last;
  for (RandomIt it=last; --it>=first;)
    if ((it->first) >= 0) {
      mid = ++it;
      break;
    }

  if (mid == last)
    return;

  std::copy(first, mid, work.begin()+(last-mid));
  std::copy(mid, last, work.begin());
  std::copy(work.begin(), work.end(), first);
}

int main() {
  size_t W, H;
  scanf("%zu %zu", &W, &H);

  std::vector<std::pair<unsigned, size_t>> es;
  for (size_t j=0; j<H+W; ++j) {
    unsigned p;
    scanf("%u", &p);
    es.emplace_back(p, j);
  }

  rsort(es.begin(), es.end());
  size_t a=W+1, b=H+1;
  uintmax_t res=0;
  for (const auto &e: es) {
    if (e.second < W) {
      res += e.first*b;
      --a;
    } else {
      res += e.first*a;
      --b;
    }
  }

  printf("%ju\n", res);
}
