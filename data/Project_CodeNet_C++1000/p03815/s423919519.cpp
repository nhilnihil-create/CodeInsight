#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;
 
int main(){
  ll n;cin>>n;
  ll sum = 0,i = 0;
  sum+= n/11;
  sum*=2;
  if (n%11 <=6 && n%11 != 0){
    sum++;
  }
  else if (n%11 >= 7){
    sum+=2;
  }
  cout << sum << endl;
}