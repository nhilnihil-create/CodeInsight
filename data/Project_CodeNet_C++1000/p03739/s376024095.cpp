#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    ll a[n];rep(i,n)cin>>a[i];

    ll tmp=0;
    ll pos=1;
    ll sum=a[0];
    if(a[0]<=0){
        tmp+=abs(a[0])+1;
        sum=1;
    }

    rep(i,n-1){
        sum+=a[i+1];
        if(sum*pos>=0){
            tmp+=abs(sum)+1;
            sum=-pos;
        }
        pos*=-1;
    }
    ll ans=tmp;

    tmp=0;
    pos=-1;
    sum=a[0];
    if(a[0]>=0){
        tmp+=abs(a[0])+1;
        sum=-1;
    }
    rep(i,n-1){
        sum+=a[i+1];
        if(sum*pos>=0){
            tmp+=abs(sum)+1;
            sum=-pos;
        }
        pos*=-1;
    }
    ans=min(ans,tmp);
    cout<<ans<<endl;
	return 0;
}