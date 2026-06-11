#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
int n, k, a[5005], l, r;

int main(){
    scanf("%d%d", &n, &k);
    rep(i,n) scanf("%d", a+i);
    sort(a, a+n);
    l = -1; r = n;
    while(l+1 < r){
        int mid = (l + r) / 2;
        bool dp[9999] = {true}, ok = false;
        rep(i,n) if(i-mid && a[i]<k) for(int j = k; j >= 0; j--) if(dp[j]) dp[a[i]+j] = true;
        for(int i = max(0,k-a[mid]); i < k; i++) if(dp[i]) ok = true;
        (ok ? r : l) = mid;
    }
    printf("%d\n", r);
}