#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  vector<int> ans(8);
  int p=0;
  rep(i,n){
    if(a.at(i)<3200){
      ans.at(a.at(i)/400)=1;
    }else{
      p++;
    }
  }
  int mini,maxi;
  rep(i,8){
    mini+=ans.at(i);
  }
  maxi=mini+p;
  cout << max(1,mini) <<  " " << maxi;
}
      