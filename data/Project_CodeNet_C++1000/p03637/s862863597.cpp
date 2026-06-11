#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<int64_t> a(n),b(n);
  rep(i,n){
    cin >> a.at(i);
  }
  int ans=0;
  rep(i,n){
    if(a.at(i)%4==0){
      b.at(i)=2;
    }else if(a.at(i)%2==0){
      b.at(i)=1;
    }
    ans+=b.at(i);
  }
  rep(i,n){
    if(a.at(i)%4==0 && n%2==1){
      ans++;
    }
  }
  if(ans>=n){
    cout << "Yes";
  }else{
    cout << "No";
  }
}