#include <bits/stdc++.h>
using namespace std;

long long x[100009];
long long a[100009], d[100009], id[100009], go[100009], ans[100009];
bool vs[100009];

int main() {
    int N, M; long long K; scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%lld",&x[i]);
    for(int i=1; i<N; i++) d[i] = x[i+1] - x[i], id[i] = i;
    scanf("%d%lld",&M,&K);
    for(int i=1; i<=M; i++) {
        scanf("%lld",&a[i]);
        swap(id[a[i]], id[a[i]-1]);
    }
    for(int i=1; i<N; i++) go[id[i]] = i;
    for(int i=1; i<N; i++) {
        if(!vs[i]) {
            int now = i;
            vector<int> S;
            while(!vs[now]) {
                vs[now] = 1;
                S.push_back(now);
                now = go[now];
            }
            int sz = S.size();
            for(int i=0; i<sz; i++) {
                ans[S[i]] = S[(i-K%sz+sz)%sz];
            }
        }
    }
    long long s = x[1];
    for(int i=1; i<=N; i++) {
        printf("%lld\n", s);
        s += d[ans[i]];
    }
    return 0;
}
