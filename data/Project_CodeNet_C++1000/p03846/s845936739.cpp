#include <iostream>
#include <vector>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= MOD;
        (x *= x) %= MOD;
        n >>= 1;
    }
    return ret;
}

int main(void) {
    int64_t N;
    cin >> N;
    vector<int> cnt(N);
    for(int i=0; i<N; i++) {
        int A;
        cin >> A;
        cnt[A]++;
    }

    try {
        if(N % 2) {
            if(cnt[0] != 1) throw 1;
            for(int j=2; j<N; j+=2) {
                if(cnt[j] != 2) throw 2;
            }
            cout << mod_pow(2L, N/2) << endl;
        } else {
            for(int j=1; j<N; j+=2) {
                if(cnt[j] != 2) throw 3;
            }
            cout << mod_pow(2L, N/2) << endl;
        }
    } catch (...){
        cout << 0 << endl;
    }
    return 0;
}
