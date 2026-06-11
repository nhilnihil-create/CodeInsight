#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int x,a,b;
  cin >> x>>a>>b;
  if(b<=a){
    cout << "delicious" << endl;
  }
  else if(b<=a+x){
    cout << "safe" << endl;
  }
  else{
    cout << "dangerous" << endl;
  }
}
      
      