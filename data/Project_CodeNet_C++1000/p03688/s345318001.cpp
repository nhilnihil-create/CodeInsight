
#include <bits/stdc++.h>
using namespace std;;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
const int MOD = 1000000007;
const long double pi = 3.14158265358979l;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin >> n;
  vector<ll> a(n);
  ll ma = 0; ll mi = LINF;
  rep(i,n){
    cin >> a[i];
    ma = max(ma, a[i]);
    mi = min(mi, a[i]);
  }
  if(ma-mi>1){
    cout << "No" << endl;
    return 0;
  }
  if(ma==mi){
    if(n >= 2 * ma || ma==n-1){
      cout << "Yes" << endl;
    }else{
      cout <<"No" << endl;
    }
    return 0;
  }
  ll l = 0, s = 0;
  rep(i,n){
    if(a[i]==ma)l++;
    else s++;
  }
  if(s<ma && l >= 2 * (ma-s)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

