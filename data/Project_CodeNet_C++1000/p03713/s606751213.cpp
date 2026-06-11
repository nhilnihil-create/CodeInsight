#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
  long long a, b, p, q, r, t = 1e12; cin >> a >> b;
  rep(i, a){
    p = i * b;
    q = (a-i)/2*b;
    r = (a-(a+i)/2)*b;
    t = min(t, max(p, max(q, r)) - min(p, min(q, r)));
    q = (a-i)*(b/2);
    r = (a-i)*(b-b/2);
    t = min(t, max(p, max(q, r)) - min(p, min(q, r)));
  }
  rep(i, b){
    p = i * a;
    q = (b-i)/2*a;
    r = (b-(b+i)/2)*a;
    t = min(t, max(p, max(q, r)) - min(p, min(q, r)));
    q = (b-i)*(a/2);
    r = (b-i)*(a-a/2);
    t = min(t, max(p, max(q, r)) - min(p, min(q, r)));
  }
  cout << t << "\n";
  return 0;
}