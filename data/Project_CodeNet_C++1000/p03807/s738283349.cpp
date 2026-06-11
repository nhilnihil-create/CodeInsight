#include <bits/stdc++.h>
#define rep(i, a) for (ll i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  int ct = 0;
  rep(i,n){
    cin >> a[i];
    if(a[i] % 2 != 0){
      ct++;
    }
  }
  if(ct%2==0){
    cout << "YES" << endl;
    return 0;
  }else{
    cout << "NO" << endl;
    return 0;
  }
}