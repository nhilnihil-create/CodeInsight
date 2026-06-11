#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

ll MAX=100007;
vector<ll> F(MAX,1);
 
void fact(){
    for(ll i=1;i<MAX;i++){
    F[i]=F[i-1]*i%MOD;
    }
return;
}


// mod. m での a の逆元 a^{-1} を計算する
//ただしmとaが互いにその時のみ
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

long long comb(long long a, long long b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return (((F[a]*modinv(F[b],MOD))%MOD)*modinv(F[a-b],MOD))%MOD;
}

//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓
//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓
//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓
//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓
//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓



int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    fact();
    ll N;
    cin >> N;
    vector<ll> a(N+1,0);
    for(ll i=0;i<N+1;i++)cin>>a[i];
    ll A=INF,B=INF;
    Map M;
    for(ll i=0;i<N+1;i++)M[a[i]]++;
    ll mark;
    for(auto p: M)if(p.second==2){mark=p.first;}
    for(ll i=0;i<N+1;i++){
        if(a[i]==mark&&A==INF)A=i;
        else if(a[i]==mark)B=i;
    }
    print(N)
    for(ll i=2;i<=N+1;i++){
        ll ans=0;
        ans+=comb(N-1,i);
        ans+=comb(N-1,i-2);
        ans-=comb(N+A-B,i-1);
        ans+=comb(N-1,i-1)*2;
        print((ans+MOD)%MOD)
    }

    return 0;
}
