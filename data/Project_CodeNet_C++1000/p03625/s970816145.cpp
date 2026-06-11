#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> a(n+1);
  rep(i,n){
    cin >> a.at(i);
  }
  a.at(n)=0;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int64_t p=0,q=0,i=0;
  while(a.at(i)!=0 && q==0){
    if(a.at(i)==a.at(i+1) && p==0){
      p=a.at(i);
      i+=2;
      continue;
    }
    if(a.at(i)==a.at(i+1)&& p!=0){
      q=a.at(i);
      break;
    }
    i++;
  }
  int64_t ans=p*q;
  cout << ans;
}
