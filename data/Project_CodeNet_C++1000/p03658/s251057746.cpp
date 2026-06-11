#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n,k;cin>>n>>k;
    int a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n,greater<int>());
    int ans=0;
    rep(i,k)ans+=a[i];
    cout<<ans<<endl;
	return 0;
}