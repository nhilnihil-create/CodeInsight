#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int m = 2*n;
    int l[m];rep(i,m)cin>>l[i];
    sort(l,l+m);
    int ans = 0;
    for(int i=0;i<m;i+=2)ans+=l[i];
    cout<<ans<<endl;
	return 0;
}