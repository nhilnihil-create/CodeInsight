#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

const ll INF = LLONG_MAX;
class SegmentTree{
    int n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v){
        int size = v.size();
        n = 1;
        while(n < size) n *= 2;
        node.resize(2*n-1, INF);

        for(int i = 0; i < size; i++){
            node[n-1+i] = v[i];
        }
        for(int i = n-2; i >= 0; i--){
            node[i] = min(node[2*i+1], node[2*i+2]);
        }
    }

    int update(ll idx, ll val){
        idx += n-1;
        node[idx] = val;
        while(idx > 0){
            idx = (idx-1)/2;
            node[idx] = min(node[2*idx+1], node[2*idx+2]);
        }
    }

    //return min value within [a,b)
    //call get_min(a, b);
    ll get_min(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;

        if(b <= l || r <= a) return INF;

        if(a <= l && r <= b) return node[k];

        ll vl = get_min(a, b, 2*k+1, l, (l+r)/2);
        ll vr = get_min(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main(){
    ll N, x;
    cin >> N >> x;
    vector<ll> A(2*N);
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
        A[N+i] = a;
    }

    SegmentTree seg(A);

    ll ans = LLONG_MAX;
    for(int s = 0; s < N; s++){
        ll tmp = x*s;
        for(int i = N; i < 2*N; i++) {
            ll c = seg.get_min(i-s, i+1);
            tmp += c;
        }
        chmin(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
