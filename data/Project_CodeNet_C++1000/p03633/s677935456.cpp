
#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

ll gcd(ll a,ll b){
  ll r = a%b;
  while(r!=0){
    a = b;
    b = r;
    r = a%b;
  }

  return b;
}

int main(){
  ll n; cin >> n;
  vector<ll> t(n);
  rep(i,n){
    cin >> t.at(i);
  }

 sort(all(t));

 rep(i,n-1){
   if(t.at(i)>t.at(i+1)) swap(t.at(i),t.at(i+1));
   if(t.at(i+1)%t.at(i)==0) continue;
   else t.at(i+1)=t.at(i+1)/gcd(t.at(i+1),t.at(i))*t.at(i);
 }

 cout << t.at(n-1) << endl;
}
