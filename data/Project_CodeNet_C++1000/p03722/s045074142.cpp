#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)
 
int main(){
    //ExAC
    //input
    long long N,M;
    cin >> N >> M;
    int a[2000],b[2000];
    long long c[2000];
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i];
    }
    //distance
    long long x[1000]; //x[i] 0->i : Ci;
    for (int i = 0; i < N; ++i) {
        x[i] = LONG_LONG_MAX;
    }
    x[0] = 0;

    //update
    for (int loop = 0; loop < N - 1; ++loop) {
        for (int i = 0; i < M; ++i) {
            if (x[a[i] - 1] == LONG_LONG_MAX) continue;

            x[b[i] - 1] = min(x[b[i] - 1],x[a[i] - 1] + c[i]);
        }
    }

    long long ans = x[N - 1];
    bool negative[1000] = {false};
    for (int i = 0; i < N; ++i) {
        negative[i] = false;
    }
    for (int loop = 0; loop < N ; ++ loop) {
        for (int i = 0; i < M; ++i) {
            if (x[a[i] - 1] == LONG_LONG_MAX) continue;

            if (x[b[i] - 1] > x[a[i] - 1] + c[i]) {
                x[b[i] - 1] = x[a[i] - 1] + c[i];
                negative[b[i] - 1] = true;
            }

            if (negative[a[i] - 1] == true) {
                negative[b[i] - 1] = true;
            }
        }
    }

    if (negative[N - 1]) cout << "inf" << endl;
    else cout << -ans << endl;

    return 0;
}