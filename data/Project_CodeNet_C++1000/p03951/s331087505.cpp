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
  int n,count=0;
  string s,t;
  cin >> n >> s >> t;
  string a;
  rep(i,n){
    if(s[i] != t[count] && count != 0){
      count = 0;
    }
    if(s[i] == t[count]){
      count++;
    }
  }
  a = s + t.substr(count,n-count);
  cout << a.size() << endl;
}