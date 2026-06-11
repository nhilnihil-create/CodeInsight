#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int toInt(const string &s){
    if(s[0] == '-')
        return -(s[1] - '0');
    return (s[0] - '0');
}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    ll n,m;
    cin >> n >> m;
    if(n >= m)
        cout << m / 2 << '\n';
    else{
        ll ans = 0;
        ll aux = min(n,m / 2);
        ans += aux;
        m -= aux * 2;
        if(m > 0)
            ans += m / 4;
        cout << ans << '\n';

    }
    return 0;
}