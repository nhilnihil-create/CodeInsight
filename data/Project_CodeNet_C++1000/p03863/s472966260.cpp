#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    string s; cin>>s;
    ll n = s.size();
    vector<ll> cnt(26, 0);
    if((n%2==0) ^ (s[0] == s[n-1])) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}