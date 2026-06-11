#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);
int main(){
    int n; scanf("%d", &n);
    ll T[n], A[n];
    REP(i, n){
        sc(T[i])
        sc(A[i])
    }
    ll ans1 = 0, ans2 = 0, tmp = 0;
    for (int i = 0; i < n; i++){
        if (T[i] == A[i] && ans1 == ans2) continue;
        if (ans1 == 0){
            ans1 = T[i];
            ans2 = A[i];
            continue;
        }else if (ans1 % T[i] == 0 && ans2 % A[i] == 0){
            tmp = max(ans1 / T[i], ans2 / A[i]);
        }else if (ans1 % T[i] == 0){
            tmp = max(ans1 / T[i], ans2 / A[i] + 1ll);
        }else if (ans2 % A[i] == 0){
            tmp = max(ans1 / T[i] + 1ll, ans2 / A[i]);
        }else tmp = max(ans1 / T[i] + 1ll, ans2 / A[i] + 1ll);
        ans1 = T[i] * tmp;
        ans2 = A[i] * tmp;
    }
    if (ans1 == 0){
        ans1 = 1;
        ans2 = 1;
    }
    cout << ans1 + ans2 << endl;
    return 0;
}