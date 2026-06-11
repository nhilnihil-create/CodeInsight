#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N;cin>>N;
  ll cnt;
  ll k=0,m=0;
  rep(i,N){
    ll a;cin>>a;
    if(a%4==0) k++;
    else if(a%2==0) m++;
  }
  if(2*k+m+1>N || (2*k+m+1==N)&&m%2==0) cout << "Yes" << endl;
  else cout << "No" << endl;
}