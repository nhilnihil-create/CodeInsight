#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n;cin>>n;
    ll a[100010],sum[100010];
    rep(i,0,n)cin>>a[i];
    sum[0]=a[0];
    rep(i,1,n)sum[i]=sum[i-1]+a[i];
    bool st=sum[0]>0,ng=0;
    rep(i,1,n){
        if(st&&sum[i]<0)st=0;
        else if(!st&&sum[i]>0)st=1;
        else ng=1;
    }
    if(!ng){
        cout<<0<<endl;
        return 0;
    }
    ll an=0,pl=0;
    if(sum[0]==0){
        an++;pl++;
    }
    if(sum[0]<0){
        an+=abs(sum[0])+1;
        pl+=abs(sum[0])+1;
    }
    rep(i,1,n){
        if(i%2==0&&sum[i]+pl<=0){
            an+=abs(sum[i]+pl)+1;
            pl+=abs(sum[i]+pl)+1;
        }
        if(i%2==1&&sum[i]+pl>=0){
            an+=sum[i]+pl+1;
            pl-=sum[i]+pl+1;
        }
    }
    ll MN=an;

    an=0;pl=0;
    if(sum[0]==0){
        an++;pl--;
    }
    if(sum[0]>0){
        an+=abs(sum[0])+1;
        pl-=sum[0]+1;
    }
    rep(i,1,n){
        if(i%2==1&&sum[i]+pl<=0){
            an+=abs(sum[i]+pl)+1;
            pl+=abs(sum[i]+pl)+1;
        }
        if(i%2==0&&sum[i]+pl>=0){
            an+=sum[i]+pl+1;
            pl-=sum[i]+pl+1;
        }
    }
    MN=min(MN,an);
    cout<<MN<<endl;
}

    







