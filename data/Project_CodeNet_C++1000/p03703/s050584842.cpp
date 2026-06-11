#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

template <typename T>
struct BIT {
    int n;             // 要素数
    vector<T> bit[2];  // データの格納先
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }
 
    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x) {  // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }
 
    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, K, ans=0, tmp=0;
vector<ll> A, B, C;
set<ll> as;

signed main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        a -= K;
        A.push_back(a);
    }
    vector<ll> S(N+1,0);
    as.insert(0);
    for(int i=0;i<N;i++) {
        S[i+1] = S[i] + A[i];
        as.insert(S[i+1]);
    }
    for(set<ll>::iterator itr=as.begin();itr!=as.end();itr++) {
        B.push_back(*itr);
    }
    for(int i=0;i<N+1;i++) {
        ll id = lower_bound(B.begin(), B.end(), S[i])-B.begin();
        C.push_back(id+1);
        //cout << " " << C.back();
    }
    //cout << endl;
    BIT<ll> bit(N+2);
    for(int i=1;i<N+2;i++) {
        ans += bit.sum(C[i-1])-bit.sum(0);
        //cout << ans << endl;
        bit.add(C[i-1], C[i-1]+1, 1);  
        /*      
        for(int j=1;j<N+2;j++) {
            cout << " " << bit.sum(j)-bit.sum(j-1);
        }
        cout << endl;
        */
    }
    /*
    cout << endl;
    bit.add(1, 3, 3);
    for(int i=1;i<N+2;i++) {
        cout << " " << bit.sum(i)-bit.sum(i-1);
    }
    cout << endl;
    bit.add(3, 5, 5);
    for(int i=1;i<N+2;i++) {
        cout << " " << bit.sum(i)-bit.sum(i-1);
    }
    cout << endl;
    bit.add(6, 10, 7);
    for(int i=1;i<N+2;i++) {
        cout << " " << bit.sum(i)-bit.sum(i-1);
    }
    cout << endl;
    for(int i=0;i<N+1;i++) {
        auto itr = ms.find(S[i]);
        if (itr != ms.end()) ms.erase(itr);
        ans += distance(ms.lower_bound(S[i]), ms.end());
        //cout << ans << endl;
    }
    */
    cout << ans << endl;
    return 0;
}