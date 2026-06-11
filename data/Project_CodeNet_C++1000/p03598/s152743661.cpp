#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> x(n);
  rep(i,n) cin>>x[i];
  int ans=0,a;
  rep(i,n){
    if(x[i]>(k+1)/2) a=k-x[i];
    else a=x[i];
    ans+=a*2;
  }
  cout<<ans;
}