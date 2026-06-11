#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main() {
  ll x;
  cin >> x;
  ll sum=0;
  int i=0;
  while(sum<x){
    i++;
    sum+=i;
  }
  cout<<i<<endl;
}
