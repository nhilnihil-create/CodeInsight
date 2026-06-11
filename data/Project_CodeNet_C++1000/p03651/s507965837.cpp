#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n,k;
  cin >> n>>k;
  
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
  }
  int g=a.at(0);
  rep2(i,1,n){
    g=__gcd(g,a.at(i));
  }
  sort(a.begin(),a.end());
  if(a.at(n-1)>=k&&g==__gcd(g,k)){
    cout<<"POSSIBLE"<<endl;
  }
  else{
    cout<<"IMPOSSIBLE"<<endl;
  }
}