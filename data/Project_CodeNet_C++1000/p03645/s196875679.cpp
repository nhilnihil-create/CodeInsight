#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll x, ll y) {
    return x / GCD(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  set<pair<int, int>> s;
  for (int i = 0; i < M; i++)
  {
      cin >> a[i] >> b[i];
      a[i]--; b[i]--;
      s.insert({a[i], b[i]});
  }
  
    bool hantei = false;
  
  for (int i = 0; i < N; i++)
  {
      if(s.count({0, i}) && s.count({i, N - 1})) {
          hantei = true;
      }
  }
  
  
    if (hantei)
    {
        cout << "POSSIBLE" << endl;
    }else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    
    

  

    
    return 0;

}