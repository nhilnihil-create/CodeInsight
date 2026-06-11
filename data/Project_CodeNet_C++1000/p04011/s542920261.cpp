#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
const long long INF=1e9+5;
typedef long long ll;

int main() {
  ll N,K,X,Y;
  cin>>N>>K>>X>>Y;
  if(N<=K){
    cout<<N*X<<endl;
  }
  else{
    cout<<K*X+(N-K)*Y<<endl;
  }
}