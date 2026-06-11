#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define ll long long
#define ld long double
#define ALL(x) begin(x),end(x)
     

int main() {
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  a.clear();
  
  rep(i,n){
    ll num;
    cin >> num;
    if(a.empty()){
      a.push_back(num);
    }else{
      auto j = find(a.begin(),a.end(),num);
      if(j != a.end()) a.erase(a.begin()+distance(a.begin(),j));
      else a.push_back(num);
    }
  }
  cout << a.size() << endl;
}