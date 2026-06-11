#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

ifstream fin("data.txt");

unordered_map<int, int> v;
int k, n, aux, x;

int main() {

  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> x;
    v[x] = 1;
  }

  for (int i = n; ; i++) {
    aux = i;
    while (aux) {
      if (v.find(aux % 10) != v.end()) break;
      aux /= 10;
    }
    if (aux == 0) {
     cout << i;
     break;
    }
  }
  return 0;
}
