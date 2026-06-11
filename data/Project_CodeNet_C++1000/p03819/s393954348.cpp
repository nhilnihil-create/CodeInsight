#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

//-------------------------------------------------
//--Binary Indexed Tree (Sum only)
//-------------------------------------------------
template<typename T>
class BIT
{
private:
    const int n;
    ::std::vector<T> data;
public:
    BIT(int n):n(n),data(n+1){
        for(int i=1; i<=n; i++) data[i] = 0;
    }
    BIT(const ::std::vector<T> &v):n(v.size()),data(v.size()+1){
        for(int i=1; i<=n; i++) data[i] = v[i-1];
        for(int i=1; i<n; i++)
            data[i+(i&-i)] += data[i];
    }
    void add(int k, T x){k++;
        for(int i=k; i<=n; i+=i&-i) data[i] += x;
    }
    T query(int k){
        T ret=0;
        for(int i=k; i>0; i-=i&-i) ret += data[i];
        return ret;
    }
    T query(int a, int b){return query(b)-query(a);}
    void update(int k, T x){
        T upd = x-query(k, k+1);
        add(k, upd);
    }
    T operator[](int k){return query(k, k+1);}
};

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    auto cmp = [](pi x, pi y){
        int d1 = x.se-x.fi+1;
        int d2 = y.se-y.fi+1;
        return d1<d2;
    };
    using P = tuple<int,int,int>;
    vector<P> lr(n);
    rep(i,n){
        int l,r; cin>>l>>r;
        lr[i] = make_tuple(r-l+1,l,r);
    }
    sort(all(lr));
    BIT<int> bit(m+1);
    int idx=0;
    FOR(i,1,m){
        int ans=0;
        ans += lr.end()-lower_bound(all(lr),make_tuple(i,0,0));
        while(idx<n && get<0>(lr[idx])<i){
            bit.add(get<1>(lr[idx]), 1);
            bit.add(get<2>(lr[idx])+1, -1);
            idx++;
        }
        for(int j=i; j<=m; j+=i){
            ans+=bit.query(j+1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
