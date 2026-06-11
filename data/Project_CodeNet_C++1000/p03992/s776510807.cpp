#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  vector<char> vec(12);
  rep(i,12){
    cin >> vec[i];
  }
  rep(i,4){
    cout << vec[i];
  }
  cout << " ";
  FOR(i,4,12){
    cout << vec[i];
  }
  cout << endl;
}