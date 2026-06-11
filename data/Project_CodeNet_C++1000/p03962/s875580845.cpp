#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  set<ll> S;
  S.insert(a);
  S.insert(b);
  S.insert(c);
  cout<<S.size()<<endl;
}