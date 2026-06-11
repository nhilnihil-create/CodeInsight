// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> P;
int main() {
  int n; cin >> n;
  vector<int> C(100001, 0);
  loop(i,0,n) {
    int a;
    cin >> a;
    C[a]++;
  }
  
  priority_queue<P> Q;
  loop(i,0,100001) {
    if (C[i] == 0) continue;
    Q.push({ C[i], i });
  }
  
  while (Q.size()) {
    auto p = Q.top(); Q.pop();
    if (p.first == 1) {
      Q.push(p);
      break; // 最大のが1なら全部１つずつ
    }
    if (p.first >= 3) {
      p.first -= 2;
      Q.push(p);
      continue;
    }
    
    // 2個の場合には奇数個残っているはずなのでもう１つある
    auto p2 = Q.top(); Q.pop();
    p2.first--;
    p.first = 1;
    Q.push(p);
    if (p2.first > 0) Q.push(p2);
  }
  cout << Q.size() << endl;
  return 0;
}
