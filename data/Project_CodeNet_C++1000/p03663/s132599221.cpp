#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ask(ll x){
    printf("? %lld\n",x);
    fflush(stdout);
    char res;scanf(" %c",&res);
    if(res=='Y')return true;
    else return false;
}
int p[11];
int main(){
    p[1]=1;
    for(int i=2;i<=10;i++)p[i]=p[i-1]*10;
    ll ans;
    if(ask(1000000000)){
        int l=1,r=10;
        int mid,res;
        while(l<=r){
            mid=l+r>>1;
            if(ask(p[mid]*2))res=mid,r=mid-1;
            else l=mid+1;
        }
        ans=p[res];
    }
    else{
        int l=1,r=9;
        int mid,res;
        while(l<=r){
            mid=l+r>>1;
            if(ask(p[mid]))res=mid,l=mid+1;
            else r=mid-1;
        }
        l=p[res],r=p[res+1]-1;
        while(l<=r){
            mid=l+r>>1;
            if(ask(1ll*mid*10))res=mid,r=mid-1;
            else l=mid+1;
        }
        ans=res;
    }
    printf("! %lld\n",ans);
    return 0;
}