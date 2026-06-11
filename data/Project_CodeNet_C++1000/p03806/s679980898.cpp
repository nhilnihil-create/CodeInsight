#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;
int main() {
    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    int A[41], B[41], C[41];
    rep(i,N) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        A[i] = a;
        B[i] = b;
        C[i] = c;
    }
    int H1 = N / 2;
    int H2 = N - H1;
    int mi = INT32_MAX;

    // (MbA0−MaB0)+(MbA1−MaB1)=0
    // MbA0 - MaB0 = MaB1 - MbA1
    
    map<int,int> M1;
    for (int bit = 1; bit < pow(2,H1); bit++) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < H1; i++) {
            if (bit & (1 << i)) {
                a += A[i];
                b += B[i];
                c += C[i];
            }
        }
        int s = Mb * a - Ma * b;
        if (M1[s] == 0) M1[s] = c; // Can't be zero
        else M1[s] = min(M1[s], c);
        if (s == 0) mi = min(mi, c);
    }

    hash_map<int,int> M2;
    for (int bit = 1; bit < pow(2,H2); bit++) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < H2; i++) {
            if (bit & (1 << i)) {
                a += A[H1 + i];
                b += B[H1 + i];
                c += C[H1 + i];
            }
        }
        int s = Ma * b - Mb * a;
        if (M2[s] == 0) M2[s] = c;
        else M2[s] = min(M2[s], c);
        if (s == 0) mi = min(mi, c);
    }

    for (auto x : M1) {
        if (M2.find(x.first)!=M2.end()) {
            mi = min(mi, x.second + M2[x.first]);
        }
    }

    if (mi == INT32_MAX) {
        cout << -1 << endl;
    } else {
        cout << mi << endl;
    }
}
