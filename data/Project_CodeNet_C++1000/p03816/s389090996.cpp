#include <iostream>
#include <map>

int reduce_3to1(int x)
{
  if(x <= 2) {
    return x;
  } else {
    return x%2 == 0 ? 2 : 1;
  }
}

int main()
{
  int N;
  std::cin >> N;
  std::map<int, int> cards;
  for(int i=0; i<N; i++) {
    int a;
    std::cin >> a;
    cards[a]++;
  }

  // we can reduce same 3 cards to 1
  int num_doubles = 0;
  for(auto &c: cards) {
    c.second = reduce_3to1(c.second);
    if(c.second == 2) {
      num_doubles++;
    }
  }

  // couple of double cards can be deleted
  num_doubles %= 2;

  std::cout << cards.size() - num_doubles << std::endl;

  return 0;
}
