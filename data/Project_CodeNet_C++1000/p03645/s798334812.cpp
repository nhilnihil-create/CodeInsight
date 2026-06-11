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
  
  map<pair<int, int>, int> s;
  for (int i = 0; i < M; i++)
  {
      cin >> a[i] >> b[i];
      a[i]--; b[i]--;
      s[make_pair(a[i], b[i])] += 1;
  }
  
    bool hantei = false;
  for (int i = 0; i < M; i++)
  {
      if (s[make_pair(0, i)] == 1 && s[make_pair(i, N - 1)] == 1) 
      {
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