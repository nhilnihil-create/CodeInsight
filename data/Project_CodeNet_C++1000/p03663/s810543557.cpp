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
int n;
int main(){
    ll ans=0;
    while(1){
        int l=0,r=9;
        int mid,res;
        while(l<=r){
            mid=l+r>>1;
            if(ask(ans*10+mid))res=mid,l=mid+1;
            else r=mid-1;
        }
        if(res!=9)ans=ans*10+res;
        else{
            if(ask(ans*100+10)){
                ll t=ans*100+10;
                while(t<=1000000000)t*=10;
                if(ask(t)){
                    t=ans*100;
                    if(t&&ask(t))ans=ans*10;
                    else ans=ans*10+1;
                    break;
                }
                else ans=ans*10+9;
            }
            else{
                l=2,r=9;
                while(l<=r){
                    mid=l+r>>1;
                    if(ask(ans*100+mid*10))res=mid,r=mid-1;
                    else l=mid+1;
                }
                ans=ans*10+res;
                break;
            }
        }
    }
    printf("! %lld\n",ans);
    fflush(stdout);
    return 0;
}