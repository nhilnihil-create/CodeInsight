#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}

signed main (){
  string s;
  cin >> s;
  int ans = 0;
while(s.size()){
s.pop_back();
s.pop_back();
string t;
rep(i,SZ(s)/2) t.push_back(s[i]);
if(t+t == s) ans = max(ans,(int)t.size()*2);
}
cout << ans << endl;
    return 0;
}
