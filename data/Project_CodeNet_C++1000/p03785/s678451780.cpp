#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll n,c,k;
  cin >> n >> c >> k;

  std::vector<ll> t(n);
  rep(i,n){
    cin >> t.at(i);
  }
sort(all(t));

ll a=t.at(0),pa=1,bus=0,time;
bool ne=false;
for(auto i=1;i<n;i++){
  if(ne){
    a=t.at(i-1);
    ne=false;
  }


  time=t.at(i)-a;
  pa++;

  if(time>k || pa>c){
    bus++;
    ne=true;
    pa=1;
  }


}

  cout << bus+1 << endl ;


  }
