#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
typedef long long ll;

// sum(0), add(0,x) してはいけない
template<typename T>
class BIT{
public:
    vector<T> bit;
    int size;
    BIT(int size):
        bit(vector<T>(size+1,0)),size(size){}
    
    T sum(int i){
        if(!i) return 0;
        return bit[i]+sum(i-(i&(-i)));
    }

    void add(int i,T x){
        if(i>size)return;
        bit[i]+=x;
        add(i+(i&(-i)),x); 
    }   
};

int main(){
    int N; ll K; cin >> N >> K;
    vector<ll> a(N);
    REP(i,N) cin >> a[i];
    REP(i,N) a[i] -= K;
    REP(i,N-1) a[i+1] += a[i];
    ll ans = 0;
    REP(i,N) if(a[i]>=0) ans ++;
    vector<ll> b(a);
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    REP(i,N) a[i] = lower_bound(all(b),a[i]) - b.begin() + 1;
    BIT<ll> bit(N+10);
    REP(i,N) {
        ans += bit.sum(a[i]);
        bit.add(a[i],1);
    }
    cout << ans << endl;
    return 0;
}