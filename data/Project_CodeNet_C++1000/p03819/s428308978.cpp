#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> dat;

    BIT(int n=0){
        initialize(n);
    }

    void initialize(int nin){
        n = nin;
        dat.resize(n, 0);
    }

    T sum(int i){
        T s = 0;
        while(i >= 0){
            s += dat[i];
            i = (i & (i+1)) - 1;
        }
        return s;
    }

    T sum_between(int i, int j){
        return sum(j) - sum(i-1);
    }

    void plus(int i, T x){
        while(i < n){
            dat[i] += x;
            i |= i+1;
        }
    }

    // a[0]+...+a[ret] >= x
    int lower_bound(T x){
        int ret = -1;
        int k = 1;
        while(2*k <= n) k <<= 1;
        for( ;k>0; k>>=1){
            if(ret+k < n && dat[ret+k] < x){
                x -= dat[ret+k];
                ret += k;
            }
        }
        return ret + 1;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> lr(M+1);
    for(int i=0; i<N; i++){
        int l, r;
        cin >> l >> r;
        lr[r-l+1].emplace_back(l, r);
    }

    BIT<int> bit(M+2);

    int all = N;
    for(int d=1; d<=M; d++){
        int ans = all;
        for(int i=d; i<=M; i+=d) ans += bit.sum(i);
        cout << ans << endl;

        for(auto& p : lr[d]){
            int l = p.first, r = p.second;
            bit.plus(l, 1);
            bit.plus(r+1, -1);
            all--;
        }
    }
}