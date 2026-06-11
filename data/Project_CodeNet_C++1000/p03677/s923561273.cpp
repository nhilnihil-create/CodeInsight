#include <bits/stdc++.h>
using namespace std;
using lli=long long;

const int MOD=1e9+7;

int n,m,a[100001];
vector<int> v[100001];

inline int getlen(int i) {
    if(a[i]<=a[i+1]) return a[i+1]-a[i];
    else return m-a[i]+a[i+1];
}
bool isin(int l,int r,int x) {
    if(l<=r) return l<=x && x<=r;
    else return x>=l || x<=r;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]--;

    int cnt=0;
    lli sum=0,ans=10000000000000000ll;
    for(int i=1;i<n;i++) {
        if(a[i]==a[i+1]) continue;
        v[(a[i]+1)%m].push_back(i);
        v[(a[i+1]+1)%m].push_back(-i);
        
        if(!isin((a[i]+1)%m,(a[i+1])%m,m-1)) {
            sum += getlen(i);
        }else {
            if(a[i+1]!=m-1) sum += a[i+1];
            else sum--;
            cnt++;
        }
    }

    for(int i=0;i<m;i++) {
        for(auto &b:v[i]) {
            if(b<0) {
                cnt--; sum += getlen(-b)+1;
            } else {
                cnt++; sum -= 1;
            }
        }
        ans=min(ans,sum+cnt);
        sum -= cnt;
    }
    printf("%lld\n",ans);

    return 0;
}
