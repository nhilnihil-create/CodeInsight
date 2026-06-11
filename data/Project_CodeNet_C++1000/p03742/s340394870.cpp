#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
int main(){
    ll x, y; cin >> x >> y;
    if(abs(x-y)<=1) cout<<"Brown" << endl;
    else cout << "Alice"<<endl;
}