#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main()
{
    int n; ll L;
    cin >> n >> L;
    vector<ll> a(n);
    rep(i,n) scanf("%lld", &a[i]);

    int start = -1;
    rep(i,n-1) {
        if(a[i]+a[i+1] >= L) {
            start = i;
            break;
        }
    }

    if(start == -1) {printf("Impossible\n"); return 0;}

    printf("Possible\n");
    for(int i = 0; i < start; i++) printf("%d\n",i+1);
    for(int i = n-2; i >= start; --i) printf("%d\n",i+1);
    return 0;
}