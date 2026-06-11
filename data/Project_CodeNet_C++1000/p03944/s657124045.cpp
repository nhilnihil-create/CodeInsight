#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int w,h,n;cin>>w>>h>>n;
    int s=0;
    int t=0;
    rep(i,n){
        int x,y,a;cin>>x>>y>>a;
        if(a==2)w=min(w,x);
        if(a==1)s=max(s,x);
        if(a==4)h=min(h,y);
        if(a==3)t=max(t,y);
    }
    int ans = max((w-s)*(h-t),0);
    if((w-s)<=0 ||(h-t)<=0)ans=0;
    cout<<ans<<endl;
	return 0;
}