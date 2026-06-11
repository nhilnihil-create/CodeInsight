//http://arc071.contest.atcoder.jp/tasks/arc071_d
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;
const long long  base = 1e9+7;

long long f[maxn],n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    f[1]=n;
    f[2]=n*n%base;
    int sum=0;
    for (int i=3;i<=n;i++) {
        if (i>3) sum = (sum+f[i-3])%base;
        f[i]=(f[i-1] + (n-1)*(n-1)%base + sum + (n-1 - (i-3))) % base;
    }
    cout<<f[n];
}
