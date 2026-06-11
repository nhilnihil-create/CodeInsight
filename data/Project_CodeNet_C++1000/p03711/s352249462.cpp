#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll x,y;
  cin >> x >> y;
  vector<ll>a={1,3,5,7,8,10};
  vector<ll>b={4,6,9,11};
  ll judge=0;
  for(ll i=0;i<a.size();i++){
    if(x==a[i]) judge++;
    if(y==a[i]) judge++;
  }
  if(judge==2){
    cout << "Yes" << endl;
    return 0;
  }
  judge=0;
  for(ll i=0;i<b.size();i++){
    if(x==b[i]) judge++;
    if(y==b[i]) judge++;
  }
  if(judge==2) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}