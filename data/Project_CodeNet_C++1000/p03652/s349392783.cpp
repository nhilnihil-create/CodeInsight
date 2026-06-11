#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int N, M;
int A[301][301];
int current[301];
int selected[301];
int cnt[301];

inline int solve() {
    int ans = N;
    for(int k = 0; k < M - 1; k++) {
        for(int i = 0; i < M; i++) cnt[i] = 0;
        for(int i = 0; i < N; i++) {
            while(selected[A[i][current[i]]]) current[i]++;
            cnt[A[i][current[i]]]++;
        }
        auto max_id = max_element(cnt, cnt + M);
        ans = min(ans, *max_id);
        selected[max_id - cnt] = 1;
    }
    return ans;
}

int x;
const int cm = 1 << 20;
char cn[cm], *ci = cn, ct;

inline int readint() {
	x = 0;
	while ((ct = *ci++) >= '0') x = (x >> 1) + (x >> 3) + ct - '0';
    return x;
}

int main() {
    // fread_unlocked(cn, 1, cm, stdin);
    // N = readint();
    // M = readint();
    scanf("%d %d", &N, &M);
    REP(i, N) REP(j, M) {
        scanf("%d", &A[i][j]);
        // A[i][j] = readint();
        A[i][j]--;
    }
    cout << solve() << "\n";
	return 0;
}