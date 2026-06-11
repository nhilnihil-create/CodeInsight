#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
  ll n;cin >>n;
  string s,t; cin >>s>>t;
      for (int i =0; i <n; ++i) {
          string ssub=s.substr(i,n-i);
          string tsub=t.substr(0,n-i);
//          cout <<ssub<<" "<<tsub<<endl;
          if(ssub==tsub){
//              cout <<i<<endl;
              cout <<2*n-(n-i)<<endl;
              return 0;
          }
      }
      cout <<2*n<<endl;
  return 0;
}

