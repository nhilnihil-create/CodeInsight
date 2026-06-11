#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    int w,h,n;
    cin>>w>>h>>n;

    int xl=0,xr=w,yu=h,yd=0;

    rep(i,n){
        int x,y,a;
        cin>>x>>y>>a;

        if(a==1) xl=max(xl,x);
        else if(a==2) xr=min(xr,x);
        else if(a==3) yd=max(yd,y);
        else if(a==4) yu=min(yu,y);
    }

    cout<<max(0,xr-xl)*max(0,yu-yd)<<endl;

}
