#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int w,h,n;
    cin>>w>>h>>n;
    int l=0,r=w,u=h,d=0;
    rep(i,n){
        int x,y,a;
        cin>>x>>y>>a;
        if(a==1)l=max(l,x);
        if(a==2)r=min(r,x);
        if(a==3)d=max(d,y);
        if(a==4)u=min(u,y);
    }
    cout<<max(0,r-l)*max(0,u-d)<<endl;
    return 0;
}