#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<ll, int, int, int, int, int, int, int>T;
#define PI 3.14159265358979
const int MAX = 510000;
const int MOD = 1000000007;
const int INF=100000000;


int main(){
  int K,S;
  cin>>K>>S;
  ll ans=0ll;
  rep(i,K+1){
  	rep(j,K+1){
      int z=S-i-j;
      if(0<=z&&z<=K){ans++;}
    }
  }
  cout<<ans;
}






