#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  string S; cin >> S;
  int n = S.size();
  string T = S;
  for(int i=n-2; i>0; i-=2){ 
    
    string T1 = T.substr(0,i/2);
    string T2 = T.substr(i/2, i/2);
    if(T1 == T2){ cout << i << endl; return 0; }
  }   
}