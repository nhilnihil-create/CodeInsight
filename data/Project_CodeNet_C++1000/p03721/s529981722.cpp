#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

const int amax = 100000;
ll cnt[amax+1];

int main(){
  ll n,k; cin >>n >>k;
  rep(i,n){
    int a,b; cin >>a >>b;
    cnt[a]+=b;
  }
  for(int i = 1; i<=amax; i++){
    if(k<=cnt[i]) {
      cout << i << endl;
      return 0;
    }
    k-=cnt[i];
  }
  return 0;
}