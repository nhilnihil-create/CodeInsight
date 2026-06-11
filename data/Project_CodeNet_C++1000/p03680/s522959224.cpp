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
  ll n;
  cin >> n;

  std::vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }

  ll count=0,m;
  for(ll i=0;i>=0;i=m){
      m=a.at(i)-1;
      a.at(i)=0;

      if(i==1){
        break;
      }
      if(m==-1){
        cout << "-1" << endl;
        return 0;
      }
      count++;
  }

  cout << count << endl ;


  }
