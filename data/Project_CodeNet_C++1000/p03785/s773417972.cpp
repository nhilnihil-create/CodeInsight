// 解き直し.
// https://img.atcoder.jp/agc011/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int t[101010];

int main(){
    
    // 1. 入力情報.
    int N, C, K;
    scanf("%d %d %d", &N, &C, &K);
    rep(i, N) scanf("%d", &t[i]);
    
    // 2. sort.
    sort(t, t + N);
    
    // 3. バスの台数を計算.
    int bus = 0, at = 0, idx = 0, top = t[0];
    while(idx < N){
        // 先頭と同じバスに乗る乗客を検索.
        at = upper_bound(t, t + N, top + K) - t;
        
        // 乗客を振り分ける.
        if(at - idx >= C) idx += C;
        else              idx = at;
        
        // 先頭を更新.
        top = t[idx];
      
        // バスの台数をカウントアップ
        bus++;
    }
    
    // 4. 出力.
    printf("%d\n", bus);
    return 0;
    
}