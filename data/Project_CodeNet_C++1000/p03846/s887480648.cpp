#include <bits/stdc++.h>
#define vi vector<int> 
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define vii vector<pii>
#define MAX (int)(1e7+5)
#define int long long
using namespace std;

void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define see(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define see(x...)
#endif
const int MOD = (int)(1e9+7);
int I_fpow(int x,int y,int p = MOD){int res = 1;x = x % p;while (y > 0){if (y & 1) res = (res * x) % p;y = y >> 1;x = (x * x) % p;} return res;}

signed main() {
    int n;
    cin>>n;

    vi a(n);
    int flg = 0;
    for(int i=0;i<n;i++) cin>>a[i], flg += (a[i] == 0);

    if((n%2 == 0 && flg) || (flg > 1)) return cout<<0 ,0;
    set<int> s;
    for(int i=0;i<n;i++) s.insert(a[i]);
    int g = n/2;
    if(n%2) g++;
    if(s.size() != g) return cout<<0,0;
    vi v;
    for(auto i : s) v.pb(i);
    int flag = 0;
    for(int i=0;i<v.size()-1;i++) {
        if(v[i+1]-v[i] != 2) flag = 1;
    }
    if(flag) return cout<<0,0;
    if(n%2 && v[0] == 0) cout<<I_fpow(2,n/2);
    else if(n%2 == 0 && v[0] == 1) cout<<I_fpow(2,n/2);
    else cout<<0;
    return 0; 
}