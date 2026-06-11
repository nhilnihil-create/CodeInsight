#include <iostream>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main() {
    int n,m;cin>>n>>m;
    int ans=0,a[n],b[n];
    int from,to;
    
    rep(i,n)a[i]=1,b[i]=0;
    b[0]=1;

    rep(i,m){
        cin>>from>>to;
        if(b[from-1]==1 )b[to-1]=1;
        if(a[from-1]==1 && b[from-1]==1)b[from-1]=0;
        a[from-1]-=1;
        a[to-1]+=1;
    }
    rep(i,n)ans+=b[i];
    cout<<ans<<endl;
	return 0;
}