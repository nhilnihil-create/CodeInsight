#include <bits/stdc++.h>
using namespace std;
constexpr uint64_t MOD =1000000007UL;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(void) {
    int N;
    int tmpa;
    int i;
    bool correct = true;
    int array_size;
    uint64_t ans = 1;

    cin >> N;

    if(N%2) array_size = N/2+1;
    else array_size = N/2;

    vector <int> A(array_size,0);

    for(i=0;i<N;i++){
        cin >> tmpa;
        if(N % 2) {
            if(tmpa % 2) {
                correct = false;
            } else {
                A[tmpa/2]++;
            }
        } else {
            if(tmpa%2) {
                A[tmpa/2]++;
            } else {
                correct = false;
            }
        }
    }

    if(N%2) {
        i = 1;
    } else {
        i = 0;
    }
    for(;i<array_size;i++) {
        if(A[i] != 2) {
            correct = false;
        }
    }

    if(!correct) {
        cout << "0\n";
    } else {
        if(N%2) {
            array_size -= 1;
        }

        ans = modpow(2,array_size, MOD);
        cout << ans << "\n";
    }

    return 0;
}
