#include<bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 32);
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef list<ll> lst;
typedef pair<ll, ll> P;

ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

#define Endl endl

/*--------------------template--------------------*/

class UF
{
  public:
    vi rank, data;
    UF() {}
    UF(ll size)
    {
        rank.resize(size, 0);
        data.resize(size, 0);
        REP(i, size)
        {
            init(i);
        }
    }
    void init(ll x)
    {
        data[x] = x;
        rank[x] = 0;
    }

    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }

    void unite(ll x, ll y)
    {
        link(root(x), root(y));
    }

    void link(ll x, ll y)
    {
        if (rank[x] > rank[y])
        {
            data[y] = x;
        }
        else
        {
            data[x] = y;
            if (rank[x] == rank[y])
            {
                rank[y]++;
            }
        }
    }
    // xの根を探す。同じ集合なら同じ根が帰る, O(A^-1)
    ll root(ll x)
    {
        return (x == data[x] ? data[x] : data[x] = root(data[x]));
    }

    // 分離されている集合の数を返す, O(n)
    ll getSetNum(){
        map<ll, ll> c;
        REP(i,data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }

    // 頂点vと連結な集合を返す, O(n)
    vi getContainingSet(int v)
    {
        vi ret;
        REP(i,data.size()) {
            if(root(i)==root(v)){
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main() {
    ll l;
    cin >> n >> k >> l;
    UF ufa(n);
    UF ufb(n);
    REP(i,k){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ufa.unite(a, b);
    }
    REP(i, l)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ufb.unite(a, b);
    }
    vector<P> temp(n);
    REP(i,n){
        temp[i] = {ufa.root(i), ufb.root(i)};
    }
    map<P, ll> mp;
    REP(i,n){
        mp[temp[i]]++;
    }
    REP(i,n) {
        cout << mp[temp[i]] << " ";
    }
    cout << endl;
}