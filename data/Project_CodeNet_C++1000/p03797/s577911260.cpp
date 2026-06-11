#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

ll ans =0;

int main(){
  ll N,M;cin >> N >> M;
  if(2*N<=M){
    ans += N;
    M-=2*N;
    N=0;
  }else{
    ans += M/2;
    N -= M/2;
    M =0;
  }

  cout << ans+M/4 << endl;

}
