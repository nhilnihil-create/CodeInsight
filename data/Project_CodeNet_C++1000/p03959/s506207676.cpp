#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const LL MOD = 1e9 + 7;
const int MAX = 101010;
LL T[MAX], A[MAX];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld", &T[i]);
    rep(i, N) scanf("%lld", &A[i]);
    
    // 2. 記録の整合性を確認.
    bool ok = true;
    int atT = -1, atA = -1;
    if(T[N - 1] != A[0]) ok = false;
    rep(i, N){
        if(T[i] == T[N - 1]){
            atT = i;
            break;
        }
    }
    repr(i, N - 1, 0){
        if(A[i] == A[0]){
            atA = i;
            break;
        }
    }
    if(atT > atA) ok = false;
    
    // 3. 記録の整合性が矛盾していれば終了.
    if(!ok){
        puts("0");
        return 0;
    }
    
    // 4. 山の高さの列としてありうるものは？
    LL ans = 1, befT = T[0], befA = A[N - 1];
    repx(i, 1, atT){
        if(befT == T[i]) ans *= T[i];
        ans %= MOD;
        befT = T[i];
    }
    repr(i, N - 2, atT + 1){
        if(befA == A[i]) ans *= A[i];
        ans %= MOD;
        befA = A[i];
    }
    
    // 5. 出力.
    printf("%lld\n", ans);
    return 0;
    
}