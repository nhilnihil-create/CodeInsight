#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n,sum=0;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
    sum+=a.at(i);
  }
  sort(a.begin(),a.end());
  if(sum%10!=0){
    cout << sum;
    return 0;
  }else{
    rep(i,n){
      if(a.at(i)%10!=0){
        sum=sum-a.at(i);
        break;
      }
    }
    if(sum%10==0){
    cout << 0;
    return 0;
    }
  }
  cout << sum;
}
  