#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=1e9+7;
#define N 200000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll int n,l,t,x[N]={},w[N]={};
    cin>>n>>l>>t;
    rep(i,n){
        scanf("%d %d",&x[i],&w[i]);
    }
    ll int y[N]={};
    rep(i,n){
        if(w[i]==1){
            y[i]=(x[i]+t)%l;
        }
        else {
            y[i]=(x[i]+l-t%l)%l;
    }
    }
    sort(y,y+n);

    ll int count=0;
    ll int flag=0;
    rep2(i,1,n-1){
        if(w[i]!=w[0]){
            if(w[0]==1){
                count+=(t*2-x[i]+x[0]+l)/l;
                if((t*2-x[i]+x[0]+l)%l==0){
                    flag=1;
                }
            }
            if(w[0]==2){
                count+=(t*2+x[i]-x[0])/l;
            }
        }
    }
    count=count%n;
    if(w[0]==2) count=(n-count)%n;
    ll int pos;
    if(w[0]==1){
        pos=(x[0]+t)%l;
    }
    else{
        pos=(x[0]+l-(t%l))%l;
    }
    ll int m;
    if(w[0]==2) m=lower_bound(y,y+n,pos)-y;
    else {
        m=lower_bound(y,y+n,pos)-y;
        if(flag) m++;
    }
    m=(m+n-count)%n;
    rep(i,n){
        printf("%d\n",y[m]);
        m++;
        if(m==n) m=0;
    }
    return 0;
    
}