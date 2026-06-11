#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define pbb pair<bool,bool>
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define xmod (ll)(1e9+7) 
#define hmod 1286031825167LL
using namespace std;

int a,b;
char s;
int main(){	
    ios::sync_with_stdio(false);
    cin >> a >> s >> b;
    if (s == '-')
    cout << a-b << "\n";
    else
    cout << a+b << "\n";
    return 0;
}	