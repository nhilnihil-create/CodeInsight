#include <bits/stdc++.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> v(3,0);
    rep(i,0,n){
        ll in;
        cin >> in;
        if(in%4 == 0)v[2]++;
        else if(in%2 == 0)v[1]++;
        else v[0]++;
    }
    if(!v[1]){
       if(v[0] <= v[2]+1)cout << "Yes\n";
       else cout << "No\n"; 
    }else if(v[0] <= v[2])cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}