#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  string ans="NO";
  ll sum=0,cp=a;
  rep(i,b){
    sum+=a;
    if(sum%b==c){
      ans="YES";
    }
  }
  cout << ans;
}