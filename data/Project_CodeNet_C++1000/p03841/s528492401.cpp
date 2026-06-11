#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, b, a) for(int i = (b); i >= (a); i--)
using namespace std;
const int N = 505, M = 250005;
int n, sum, b[N], ans[M], ssum[N];
struct node{
    int pl, num;
}a[N];
bool cmp(node x, node y){
    return x.num == y.num ? x.pl < y.pl : x.num < y.num;
}
int main(){
    scanf("%d", &n);
    rep(i, 1, n){
        scanf("%d", &b[i]);
        a[i].pl = i, a[i].num = b[i];
    }
    sort(a + 1, a + n + 1, cmp);
    rep(i, 1, n){
        sum += a[i].pl;
        if(a[i].num < sum || a[i].num == a[i-1].num) {
            printf("No\n");
            return 0;
        }
    }
    sum = 0;
    per(i, n, 1){
        sum += n - a[i].pl + 1;
        if(n * n - a[i].num + 1 < sum) {
            printf("No\n");
            return 0;
        } 
    }
    rep(i, 1, n){
        int num = a[i].pl - 1;
        ans[a[i].num] = a[i].pl, ssum[a[i].pl]++;
        rep(j, 1, a[i].num - 1) {
            if(!num) break;
            if(!ans[j]) ans[j] = a[i].pl, num--, ssum[a[i].pl]++;
        }
    }
    rep(i, 1, n) rep(j, b[i] + 1, n * n) {
        if(ssum[i] == n) break;
        if(!ans[j]) ans[j] = i, ssum[i]++;
    }
    printf("Yes\n");
    rep(i, 1, n * n) printf("%d ", ans[i]);
    return 0;
}