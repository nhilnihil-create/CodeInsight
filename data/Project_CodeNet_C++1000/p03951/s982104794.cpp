#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};

//ll mod = 1000000009;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/*
int main() {
        int n; string s, t; cin >> n >> s >> t;
        int I, J;
        for(int i = 0; i < n; i++){
            bool ok = true;
            for(int j = 0; j < n; j++){
                if(s[i]==t[j]){
                    I = i; J = j;
                    while(I < n-1){
                        if(s[I+1] == t[J+1]){
                            I++; J++;
                        }else{
                            ok = false;
                            break;
                        }
                    }
                }
            }if(ok){
                rep(k,I) cout << s[k];
                for(int k = J; k < n; k++) cout << t[k];
                return 0;
            }
        }
}
*/
int main(){
    int n; string s, t; cin >> n >> s >> t;

    for(int i = 0; i < n; i++){
        bool ok = true; int k = 0,K;
        for(int j = i; j < n; j++){
            if(s[j] == t[k]) {k++; K = j;}
            else{
                ok = false;
                break;
            }
        }
        if(ok){
            //rep(l,K+1) cout << s[l];
            //for(int l = k;l < n;l++) cout << t[l];
            cout << K + n - k + 1 << endl;
            return 0;
        }
    }
    cout << 2 * n << endl;
}


