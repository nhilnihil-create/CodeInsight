#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main(){
  int N;
  cin >> N;
  vector<ll> T(N),A(N);
 
  ll t = 1,a = 1;
  for(int i = 0; i < N; i++){
    cin >> T.at(i) >> A.at(i);
    ll x = t / T.at(i);
    ll y = a / A.at(i);
    
    if(t%T.at(i) != 0) x++;
    if(a%A.at(i) != 0) y++;
    
    ll co = max(x,y);
    
    t = co * T.at(i);
    a = co * A.at(i);
  }
  
  cout << t + a << endl;
}
  
  