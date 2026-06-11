#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
int main() {
	int n;cin>>n;
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) cin>>pre[i];
    int ans=1e9;
    for(int i=-1000;i<=1000;i++) {
    	int sum=0;
    	for (int j=1;j<=n;j++) {
    		sum+=(i-pre[j])*(i-pre[j]);
    	}
    	ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}