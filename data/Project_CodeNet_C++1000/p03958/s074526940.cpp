#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,t;
  cin >> n>>t;
  vector<int>a(t);
  rep(i,t){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  if(2*a.at(t-1)-n-1>0){
    cout<<2*a.at(t-1)-n-1<<endl;
  }
  else{
    cout<<0<<endl;
  }
}