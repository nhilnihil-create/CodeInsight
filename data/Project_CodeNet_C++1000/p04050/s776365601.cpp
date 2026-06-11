#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M;
  cin >> N >> M;
  deque< int > odd, even;
  for(int i = 0; i < M; i++) {
    int x;
    cin >> x;
    if(x & 1) odd.emplace_back(x);
    else even.emplace_back(x);
  }
  if(odd.size() >= 3) {
    cout << "Impossible" << endl;
  } else {
    if(odd.size()) {
      even.emplace_front(odd.back());
      odd.pop_back();
    }
    if(odd.size()) {
      even.emplace_back(odd.back());
      odd.pop_back();
    }
    for(auto t : even) cout << t << " ";
    cout << endl;

    if(even.size() == 1) {
      if(even[0] == 1) cout << 1 << endl << 1 << endl;
      else cout << 2 << endl << even[0] - 1 << " " << 1 << endl;
    } else {
      even.front()++;
      even.back()--;
      if(even.back() == 0) even.pop_back();
      cout << even.size() << endl;
      for(auto t : even) cout << t << " ";
      cout << endl;
    }
  }
}


