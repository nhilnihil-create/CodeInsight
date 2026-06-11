#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    rep(i, n) scanf("%lld", &a[i]);
    deque<ll> ans;
    int temp = 1;
    if(n % 2) temp = 0; //nが奇数なら0、偶数なら1
    rep(i, n) {
        if(i % 2 == temp) ans.push_front(a[i]); //偶奇が一致してたら
        else ans.push_back(a[i]);
    }
    rep(i, n) printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}