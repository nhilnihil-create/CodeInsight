#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    int N, K;
    cin >> N >> K;
    vector<LL> a(N+1), sum(N+1, 0), plsum(N+1, 0);
    for(int i = 1;i <= N;i++)   cin >> a[i];
    for(int i = 1;i <= N;i++)   sum[i] = sum[i-1]+a[i];
    for(int i = 1;i <= N;i++)    plsum[i] = plsum[i-1]+max(0LL, a[i]);
    LL ans = 0;
    for(int i = 1;i+K-1 <= N;i++){
        LL an = 0;
        an += max(0LL, sum[i+K-1]-sum[i-1]);
        an += plsum[N]-plsum[i+K-1];
        an += plsum[i-1]-plsum[0];
        ans = max(ans, an);
    }
    cout << ans << endl;
}