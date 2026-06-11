#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main(){
  int n;
  cin >>n;
  ll a[n];
  rep(i,n)cin >> a[i];
  sort(a,a+n);
  int count=0;
  ll g[2]={};
  for(int i=n-1;i>=1;i--){
    if(a[i]==a[i-1]){
      g[count]=a[i];
      count++;
      i--;
    }
    if(count==2)break;
  }
  cout << g[0]*g[1] << endl;
}