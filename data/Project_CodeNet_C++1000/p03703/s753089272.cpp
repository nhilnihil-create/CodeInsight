#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

//1-indexedに注意！！！
struct BIT{
    private:
    int n;
    vector<long long> bit;

    public:
    BIT(int n):n(n){
        bit.resize(n+1);
    }

    long long sum(int i){
        long long res = 0;
        while(i > 0){
                res += bit[i];
                i -= i&-i;
        }
        return res;
    }

    void add(int i,long long val){
        while(i <= n){
                bit[i] += val;
                i += i&-i;
        }
    }
};

int main(){
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> a(n),left(n+1),right(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i] -= k;
    for(int i=n-1;i>=0;i--) left[i] = left[i+1] + a[i];
    for(int i=0;i<n;i++) right[i+1] = right[i] + a[i];
    ll all = right[n];
    vector<pll> lefter(n+1);
    rep(i,n+1) lefter[i] = pll(left[i],i);
    sort(lefter.begin(),lefter.end());
    vector<ll> order(n+1);
    rep(i,n+1) order[lefter[i].second] = i;

    /*
    rep(i,n+1) cout << lefter[i].second << " " ;
    cout << endl;
    rep(i,n+1) cout << order[i] << " " ;
    cout << endl;
    */

    BIT bit(n+1);
    ll ans = 0;
    for(int i=n;i>=0;i--){
        int l = -1,r = n+1;
        while(r - l > 1){
            int m = (l + r)/2;
            if(right[i]+lefter[m].first<=all) l = m;
            else r = m;
        }
        //cout << l << endl;
        ans += bit.sum(r);
        //cout << "#" << bit.sum(r) << endl;
        bit.add(order[i]+1,1);
    }
    cout << ans << endl;
    return 0;
}