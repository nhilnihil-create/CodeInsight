// ※※※ 解答不能 ※※※
// sugim48氏.
// https://atcoder.jp/contests/cf16-final/submissions/992126
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
vector<vector<int>> X(101010);

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> a(N);
    rep(i, N) scanf("%d", &a[i]);
    vector<int> b(100001);
    rep(i, N) b[a[i]]++;
    vector<int> c(M), d(M);
    rep(x, 100001){
        c[x % M] += b[x];
        d[x % M] += b[x] / 2;
    }
    int ans = 0;
    rep(x, M / 2 + 1){
        if(x == 0 || x * 2 == M){
            ans += c[x] / 2;
            continue;
        }
        int y = M - x;
        if(c[x] > c[y]){
            swap(c[x], c[y]);
            swap(d[x], d[y]);
        }
        ans += c[x] + min(d[y], (c[y] - c[x]) / 2);
    }
    printf("%d\n", ans);
    return 0;
}