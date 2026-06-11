#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>x(n);
  int dist=0;
  rep(i,n){cin>>x[i];
    if(k>2*x[i])dist+=x[i];
    else dist+=k-x[i];
  }
  cout<<2*dist<<endl;
    
    
  return 0;
}
