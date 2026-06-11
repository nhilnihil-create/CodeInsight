#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

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
    int N, K;
    cin >> N >> K;
    vector<int64_t> A(N), S(N+1);
    for(int i=0; i<N; i++){
        cin >> A[i];
        A[i] -= K;
        S[i+1] = S[i] + A[i];
    }
    auto cmp = compress(S);
    BIT<int> bit(cmp.size());
    int64_t ans = 0;
    for(int64_t s : S){
        int idx = lower_bound(cmp.begin(), cmp.end(), s) - cmp.begin();
        ans += bit.sum_between(0, idx);
        bit.plus(idx, 1);
    }
    cout << ans << endl;
}
