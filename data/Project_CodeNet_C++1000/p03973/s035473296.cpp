    #include "bits/stdc++.h"

    using namespace std;

    using ll = long long;
    using vll = vector<ll>;
    using vvll = vector<vector<ll>>;
    using vvvll = vector<vector<vector<ll>>>;
    using vvvvll = vector<vector<vector<vector<ll>>>>;
    using pl4 = pair<ll,ll>;
    using str = string;
    using vpl4 = vector<pair<ll,ll>>;

    #define sz size()
    #define be begin()
    #define en end()
    #define fi first
    #define se second
    #define pb push_back
    #define mp make_pair

    #define llin(x) ll (x);cin >>(x);
    #define stin(x) str (x);cin >>(x);
    #define vllin(x,n) vll (x)(n);FOR(i,0,n-1){cin >>(x)[i];}
    #define vllin2(a,b,n) vll (a)(n);vll (b)(n);FOR(i,0,n-1){cin >>(a)[i]>>(b)[i];}
    #define vllin3(a,b,c,n) vll (a)(n);vll (b)(n);vll (c)(n);FOR(i,0,n-1){cin >>(a)[i]>>(b)[i]>>(c)[i];}
    #define vlling(x,n) (x).assign(n,0);FOR(i,0,n-1){cin >>(x)[i];}
    #define vlling2(a,b,n) (a).assign(n,0);(b).assign(n,0);FOR(i,0,n-1){cin >>(a)[i]>>(b)[i];}
    #define vlling3(a,b,c,n) (a).assign(n,0);(b).assign(n,0);(c).assign(n,0);FOR(i,0,n-1){cin >>(a)[i]>>(b)[i]>>(c)[i];}
    #define vpl4in(x,n) vpl4 (x)((n),mp(0,0));FOR(i,0,n-1){cin >>x[i].fi>>x[i].se;}
    #define FOR(i,a,b) for(ll i = a ; i <= b ; i++)
    #define rFOR(i,b,a) for(ll i = a; i >= b ; i--)
    #define SORT(x) sort(x.be, x.en)
    #define rSORT(x) sort(x.rbegin(), x.rend())
    #define say(x) cout<<(x);
    #define sal(x) cout<<(x)<<endl;
    #define says(x) cout<<(x)<<(' ');
    #define sas cout<<(' ');
    #define sayR(x) cout<<fixed<<setprecision(10)<<(x);
    #define salR(x) cout<<fixed<<setprecision(10)<<(x)<<endl;
    #define yn(a) cout <<((a)?"yes":"no")<<endl;
    #define Yn(a) cout <<((a)?"Yes":"No")<<endl;
    #define YN(a) cout <<((a)?"YES":"NO")<<endl;
    #define Imp(a) cout <<((a)?"Possible":"Impossible")<<endl;
    #define IMP(a) cout <<((a)?"POSSIBLE":"IMPOSSIBLE")<<endl;
    #define pow(a,b) ll(pow(a,b))

    ll MOD=998244353;
    ll INF=100000000000001;
    vector<ll> value; // ノードの値を持つ配列
    ll N;             // 葉の数
    
    void update(ll i, ll x) {
        // i 番目の葉の値を x に変える
        i += N - 1; // i 番目の葉のノード番号
        value[i] = x;
        while (i > 0) {
            i = (i - 1) / 2; // ノード i の親ノードの番号に変える
            value[i] = min(value[i * 2 + 1],
                        value[i * 2 + 2]); // 左右の子の min を計算しなおす
        }
    }
    
    ll query(ll a, ll b, ll k, ll l, ll r) {
        // [a, b) の区間に対するクエリについて
        // ノード k （区間 [l, r) 担当）が答える
        if (r <= a || b <= l) return INF; // 区間が被らない場合は INF を返す
        if (a <= l && r <= b)
            return value[k]; // ノード k の担当範囲がクエリ区間 [a, b)
                            // に完全に含まれる
        else {
            ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
            ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
            return min(c1, c2); // 左右の子の値の min を取る
        }
    }

long long mi(long long a) {
    ll m=MOD;
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

signed main(){
    llin(n);
    vllin(a,n);
    ll g=1,t=0;
    FOR(i,0,n-1){
        t+=(a[i]-1)/g;
        if(a[i]==g || g==1) g++;
    }
    sal(t);
}