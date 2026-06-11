#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300;

int n, a[N][N];
ll r;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", a[i] + j);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            r += a[i][j];
            for(int k = 0; k < n; k++){
                if(i == k || j == k) continue;
                if(a[i][j] > a[i][k] + a[k][j]){ puts("-1"); return 0; }
                if(a[i][j] == a[i][k] + a[k][j]){ r -= a[i][j]; break; }
            }
        }
    }
    printf("%lld\n", r);
}