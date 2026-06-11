#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  string s="even";
  int cnt=0;
  for(int i=1; i<=n-1; i++){
    if(s=="even")
    {
      if(a[i-1]<a[i]) s="up";
      if(a[i-1]>a[i]) s="down";
    }
    else if(s=="up" && a[i-1]>a[i])
    {
      cnt++;
      s="even";
    }
    else if(s=="down" && a[i-1]<a[i])
    {
      cnt++;
      s="even";
    }
  }
  cnt++;
  cout<<cnt<<endl;
}
