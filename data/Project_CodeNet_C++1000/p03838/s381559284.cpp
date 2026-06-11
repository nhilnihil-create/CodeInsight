#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int x,y; cin>>x>>y;

    int ans=abs(abs(y)-abs(x));
    if((int64_t)x*y<0) ans++;
    else if((int64_t)x*y==0){
        if(y-x<0) ans++;
    }else{
        if(y-x<0) ans+=2;
    }

    cout<<ans<<endl;
}