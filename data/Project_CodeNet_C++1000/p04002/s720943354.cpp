#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
map<pii, int> dp;
LL ans[10];
int main(){
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    vector<pii> v;
    for(int i=1;i<=n;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        dp[pii(a, b)]++;
        for(int j=max(3, a);j<=min(h, a+2);j++){
            for(int k=max(3, b);k<=min(w, b+2);k++) v.push_back(pii(j, k));
        }
    }   
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0;i<v.size();i++){
        int y = v[i].first, x = v[i].second;
        int sum = 0;
        for(int j=y-2;j<=y;j++){
            for(int k=x-2;k<=x;k++){
                sum += dp[pii(j, k)];
            }
        }
        ans[sum]++;
    }
    ans[0] = (h-3+1)*1ll*(w-3+1);
    for(int i=1;i<=9;i++) ans[0] -= ans[i];
    for(int i=0;i<=9;i++) printf("%lld\n", ans[i]);
}