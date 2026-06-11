#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+5;

const int mod = 1e9+7;

int n;
int a , b;
int x[N];

int main() {
    scanf("%d%d%d" , &n , &a , &b);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &x[i]);
    }
    if(b <= a){
        printf("%lld\n" , (n - 1LL) * b);
        return 0;
    }
    long long ans = 0;
    for(int i = 2; i <= n; i++){
        ans += min(b*1LL , (x[i] - x[i-1] - 0LL) * a);
    }
    printf("%lld\n" , ans);
    return 0;
}
