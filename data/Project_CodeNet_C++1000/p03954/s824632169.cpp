#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " :: " << x << endl
#define _ << " " <<
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for (int i=(a);i>=(b);--i)

const int MX_N = 1e5+5;

int N, A[2*MX_N];
bool B[2*MX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    FOR(i,1,2*N-1){
        cin >> A[i];
    }

    int lo = 0, hi = 2*N;
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;

        FOR(i,1,2*N-1) B[i] = A[i] >= mid;
        bool tp;
        if (B[N] == B[N-1] || B[N] == B[N+1]) tp = B[N];
        else {
            int l = 1, r = 2*N-1;
            RFOR(i,N,1){
                if (B[i] == B[i-1]) { l = i; break; }
            }
            FOR(i,N,2*N-1){
                if (B[i] == B[i+1]) { r = i; break; }
            }
            if (l == 1 && r == N) tp = B[1];
            else tp = l != 1 && (r == 2*N-1 || (N - l) < (r - N)) ? B[l] : B[r];
        }

        if (tp) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}

