///Code by: Luis Alejandro
///Handle: Sekai
///Country: Cuba

#include <bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx2")

using namespace std;

typedef unsigned long long ull;
typedef long long lld;
typedef long double ld;
typedef pair<int,int> pii;

const int MAXN=1e5+5;
const int MOD=1e9+7;
const int INF=1e9;
const ld PI=acos(-1);
const ld EPS=1e-9;

#define lg2(x) 31-__builtin_clz(x)
#define logx(a,b) (log(a)/log(b))
#define pow2(a) a*a
#define pow3(a) a*a*a
#define lcm(a,b) (a*b)/__gcd(a,b)

pii mkp(int a, int b){
    if(a>b)swap(a,b);
    return make_pair(a,b);
}

int mod_pow(int a, int b){
    if(!b)return 1;
    if(b&1)return mod_pow(a,b-1)*a%MOD;
    int power=mod_pow(a,b>>1);
    return power*power%MOD;
}

int modular_inverse(int a){
    return mod_pow(a,MOD-2);
}

vector<int> movy={0,0,1,-1};
vector<int> movx={1,-1,0,0};

void solve(){
    int n, l;
    cin>>n>>l;
    vector<string> a(n);
    for(string &it:a)cin>>it;
    sort(a.begin(),a.end());
    for(string it:a)cout<<it;
    cout<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("IN.txt","r",stdin);
        //freopen("OUT.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}