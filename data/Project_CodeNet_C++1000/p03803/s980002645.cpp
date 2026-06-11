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
int v[N];
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    int a,b;
    cin >> a >> b;
    if(a == 1 && b == 1)
        cout << "Draw\n";
    else if(a == 1)
        cout << "Alice\n";
    else if(b == 1)
        cout << "Bob\n";
    else{
        if(a == b)
            cout << "Draw\n";
        else if(a > b)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;   
}