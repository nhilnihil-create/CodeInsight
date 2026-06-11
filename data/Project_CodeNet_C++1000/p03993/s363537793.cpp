#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  
  int n;
  cin >> n;
  int to=n;
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
    a.at(i)--;
  }
  int ans=0;
  rep(i,n){
    if(a.at(a.at(i))==i){
      ans++;
    }
  }
  cout<<ans/2<<endl;  
}