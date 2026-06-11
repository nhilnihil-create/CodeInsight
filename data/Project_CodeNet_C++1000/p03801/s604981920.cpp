//新幹線からAC

#include <bits/stdc++.h>
using namespace std;
    
#define int long long
#define pb push_back
#define ub upper_bound
#define lb upper_bound
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define ve vector
#define vi vector<int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
    
using ll = long long;
const ll INF = LLONG_MAX / 4 - 100;
ll mod = 1e9 + 7;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<ll> prime;
    
class fact {
public:
    int fmod = 1e9+7;
    vector<int> fac, inv;
    fact (int n, int Mod = 1e9+7) {
        fmod = Mod;
        fac = vector<int>(n,0);
        inv = vector<int>(n,0);
        fac[0] = 1; for (int i = 1; i < n; i++) fac[i] = fac[i-1] * i % fmod;
        for (int i = 0;i < n;i++) inv[i] = fact::POW(fac[i],fmod-2);
    }
    ll nCr(ll n, ll r) {return (fac[n] * inv[r] % fmod) * inv[n-r] % fmod;}
    ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%fmod;}a = a * a%fmod; b >>= 1;}return c;}
};
    
template <class T = ll> T in() {T x; cin >> x; return (x);}
void DEBUG(vector<int> a) {for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;}
void EMP(int x) {cout<<"!!!"<<x<<"!!!"<<endl;}
ll GCD(ll a, ll b) {ll c; while (b != 0) {c = a % b; a = b; b = c;}return a;}
ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;}
ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%mod;}a = a * a%mod; b >>= 1;}return c;}
void PRI(ll n) {bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) {a[i] = 1LL;}for (int i = 2; i < n + 1LL; i++) {if (a[i]) {prime.pb(i); ll b = i; while (b <= n) {a[b] = 0; b += i;}}}}
template <typename T> T chmin(T& a, T b) {if(a>b)a=b;return a;}
template <typename T> T chmax(T& a, T b) {if(a<b)a=b;return b;}
bool isSqrt(ll a) {return pow(sqrt(a),2) == a ? 1 : 0;}
void YesNo(bool a) {if (a) cout << "Yes"; else cout << "No"; cout << endl;}
void yesno(bool a) {if (a) cout << "yes"; else cout << "no"; cout << endl;}
void YESNO(bool a) {if (a) cout << "YES"; else cout << "NO"; cout << endl;}

template<typename Monoid>
class SegTree {

//半開区間!!!!!!!!!!!!!!!
public:
    int p = 2;
    vector<Monoid> node;
    using Func = function<Monoid(Monoid,Monoid)>;
    Func pick; Monoid init;//操作と単位元

    SegTree(vector<Monoid> A, string type, Monoid m) {
        if (type == "min") {
            pick = [](int a, int b){return min(a,b);};
        } else if (type == "max") {
            pick = [](int a, int b){return max(a,b);};
        } else if (type == "sum") {
            pick = [](int a, int b){return a + b;};
        }

        init = m;
        while (A.size() > p) p *= 2;
        node = vector<Monoid>(2*p-1,init);

        for (int i = 0;i < A.size();i++) {
            node[p-1+i] = A[i];
        }

        for (int i = p - 2;i >= 0;i--) {
            node[i] = pick(node[i*2+1],node[i*2+2]);
        }
    }

    SegTree(vector<Monoid> A, Func f, Monoid m) {
        pick = f; init = m;
        while (A.size() > p) p *= 2;
        node = vector<Monoid>(2*p-1,init);

        for (int i = 0;i < A.size();i++) {
            node[p-1+i] = A[i];
        }

        for (int i = p - 2;i >= 0;i--) {
            node[i] = pick(node[i*2+1],node[i*2+2]);
        }
    }

    //1点更新
    void update(int i, Monoid v) {
        for (node[(i+=p)-1] = v; i >>= 1;) {
            node[i-1] = pick(node[i*2-1], node[i*2]);
        }
    }

    //1点加算
    void add(int i, Monoid v) {
        update(i, this[i] + v);
    }
 
    int getval(int start,int end,int k = 0,int l = 0,int r = -1) {
        if (start == end) return init;
        if (r < 0) r = p;
        if (r <= start || end <= l) {return init;}
        if (start <= l && r <= end) {return node[k];}
        int L,R;
        L = getval(start,end,k*2+1,l,(l+r)/2);
        R = getval(start,end,k*2+2,(l+r)/2,r);
        return {pick(L,R)};
    }

    inline Monoid operator [] (int i) {
        return node[i+p-1];
    }
};

bool solve() {
    int n; cin >> n;
    set<int> se{0}; map<int, int> ma;
    vi a(n); rep (i, n) cin >> a[i], se.insert(a[i]);
    int p = 0;
    for (auto& x : se) {
        ma[x] = p, ++p;
    }
    vi index;
    for (auto& x : se) {
        index.pb(x);
    }
    vi ans(n);
    SegTree<int> seg(vi(p), "sum", 0);
    SegTree<int> mseg(a, "max", 0);
    int last = p;
    for (int i = n - 1; i >= 0; i--) {
        seg.update(ma[a[i]], seg[ma[a[i]]] + 1);
        if (mseg.getval(0, i) < a[i]) {
            int st = ma[mseg.getval(0, i)] + 1;
            int cnt = 0;
            int sum = 0;
            for (int j = st; j < last; j++) {
                cnt += seg[j];
                sum += seg[j] * index[j];
                seg.update(j, 0);
            }
            sum -= mseg.getval(0, i) * cnt;
            last = st + 1;
            seg.update(st - 1, seg[st-1] + cnt);
            ans[i] = sum;
        }
    }
    rep (i, n) cout << ans[i] << endl;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();    
}
