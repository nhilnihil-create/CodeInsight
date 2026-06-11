#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    int n;cin>>n;
    int a[n];
    rep(i,n){
        int tmp;cin>>tmp;
        a[i]=tmp/400;
    }
    sort(a,a+n);
    int ans = 1;
    int cc = 0;
    rep(i,n-1)if(a[i+1]!=a[i] && a[i+1] < 8)++ans;
    rep(i,n  )if(a[i ] >= 8)++cc;
    if(cc==n)--cc;
    
    cout<<ans<<" "<<ans+cc<<endl;
	return 0;
}