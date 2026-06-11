#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define a first
#define b second
pair<int, int> p[101010];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N){
        int a, b;
        scanf("%d %d", &a, &b);
        p[i] = {a, b};
    }
    
    // 2. sort.
    sort(p, p + N);
    
    // 3. ゲーム参加人数.
    int ans = p[0].a - 1;
    repx(i, 1, N) ans += min(p[i].a - p[i - 1].a, p[i - 1].b - p[i].b);
    ans += p[N - 1].b + 1;
    
    // 4. 出力.
    printf("%d\n", ans);
    return 0;
    
}