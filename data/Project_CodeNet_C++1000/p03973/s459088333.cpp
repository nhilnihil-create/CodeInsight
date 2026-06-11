#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;

constexpr int buff_size = 1 << 21;
char buff[buff_size], *ci, ct;
int A;

inline int readint() {
    A = 0;
    while ((ct = *ci++) >= '0') A = (A << 3) + (A << 1) + ct - '0';
    return A;
}

inline ll solve() {
    int N;
    scanf("%d\n", &N);
    fread_unlocked(buff, 1, (N << 3) + (N << 1) + N, stdin);
    ci = buff;
    int M = 2, cnt;
    ll ans = readint() - 1;
    while(--N) {
        int A = readint();
        if(A == M) M++;
        else if(A < M) continue; 
        else {
            ans += (cnt = A / M);
            if(A == cnt * M) ans--;
        }
    }
    return ans;
}

int main() {
    printf("%lld\n", solve());
	return 0;
}