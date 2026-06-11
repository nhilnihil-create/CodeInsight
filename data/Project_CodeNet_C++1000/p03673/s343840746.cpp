#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);

  rep(i,n) cin >> a.at(i);

  int num = 0;
  int len = a.size();

  for(int i=len-1;i>=0;i-=2){
    b.at(num)=a.at(i);
    num++;
  }

  num=0;

  for(int i=len-2;i>=0;i-=2){
    b.at(len-num-1) = a.at(i);
    num++;
  }

  rep(i,n){
    cout << b.at(i) ;
    if(i!=n-1) cout << " ";
  }
}