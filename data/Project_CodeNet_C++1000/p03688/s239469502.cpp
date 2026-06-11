#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, b, a) for(int i = (b); i >= (a); i--)
using namespace std;
const int N = 1e5 + 9, inf = 0x3f3f3f3f;
int n, minn = inf, maxx, sum, a[N];
int main(){
    scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%d", &a[i]);
        minn = min(minn, a[i]), maxx = max(maxx, a[i]);
    }
    rep(i, 1, n) if(a[i] != minn && a[i] != maxx) {
        printf("No\n");
        return 0;
    }
    if(minn == n - 1 && maxx == n - 1){
        printf("Yes\n");
        return 0;
    }
    if(minn == maxx){
        if(minn <= n / 2) printf("Yes\n");
        else printf("No\n");
        return 0;
    }
    rep(i, 1, n) if(a[i] == minn) sum++;
    //cout << maxx << " " << minn << " " << sum << endl;
    if(maxx != minn + 1 || maxx <= sum || maxx > (n - sum) / 2 + sum) printf("No\n");
    else printf("Yes\n");
    return 0;
}