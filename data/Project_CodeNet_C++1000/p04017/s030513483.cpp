#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    scanf("%d", &N);
    vector<ll> x(N+3);
    for (int i = 1; i <= N; i++) scanf("%lld", &x[i]);
    ll L;
    scanf("%lld", &L);
    x[N+1] = x[N]+L;
    x[N+2] = x[N]+2*L;
    vector<vector<int>> db(N+2, vector<int>(20, 0));
    db[N+1][0] = N+1;
    int a = 1, b = 1;
    while (a <= N) {
        while (x[b+1]-x[a] <= L)b++;
        db[a][0] = b;
        a++;
    }
    
    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= N+1; i++) {
            db[i][j] = db[db[i][j-1]][j-1];
        }
    }
    int Q;
    scanf("%d", &Q);
    
    for (int z = 0; z < Q; z++) {
        int A, B;
        scanf("%d %d", &A, &B);
        int ans = 0;
        if (A > B) swap(A, B);
        int now = A;
        while (now < B) {
            int i = 0;
            while (db[now][i+1] <= B) i++;
            now = db[now][i];
            ans += (1 << i);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
