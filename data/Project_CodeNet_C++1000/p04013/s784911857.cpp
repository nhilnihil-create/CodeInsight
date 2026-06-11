#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define ve vector
#define umap unordered_map

int main() {
    int n, a;
    cin>>n>>a;
    ve<int> x(55);
    ve<ve<ll> > dp(55,ve<ll>(5555));
    for(int i=1;i<=n;i++) cin>>x[i];
    dp[0][0]=1;
    int sum=0;
    for(int i=1;i<=n;i++) {
        for(int j=i-1;j>=0;j--) {
            for(int k=sum;k>=0;k--) {
                dp[j+1][k+x[i]] += dp[j][k];
            }
        }
        sum += x[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=dp[i][i*a];
    cout<<ans<<endl;
}