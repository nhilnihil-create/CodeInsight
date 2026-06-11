#include<iostream>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
    ll H, W;
    cin >> H >> W;
    ll ans=1000000000000, mins, maxs;
    ll tmp, tmp1, tmp2, tmp3;
    if(H%3==0 || W%3==0){
        ans = 0;
    }
    for(ll i=1; i<H; i++){
        tmp=W/2;
        tmp1=i*W;
        tmp2=(H-i)*tmp;
        tmp3=(H-i)*(W-tmp);
        maxs = max(tmp1,max(tmp2,tmp3));
        mins = min(tmp1,min(tmp2,tmp3));
        tmp=maxs-mins;
        if(tmp<ans){
            ans=tmp;
        }
        tmp=(H-i)/2;
        tmp1=i*W;
        tmp2=tmp*W;
        tmp3=(H-i-tmp)*W;
        maxs = max(tmp1,max(tmp2,tmp3));
        mins = min(tmp1,min(tmp2,tmp3));
        tmp=maxs-mins;
        if(tmp<ans){
            ans=tmp;
        }
    }
    for(ll i=1; i<W; i++){
        tmp=H/2;
        tmp1=i*H;
        tmp2=(W-i)*tmp;
        tmp3=(W-i)*(H-tmp);
        maxs = max(tmp1,max(tmp2,tmp3));
        mins = min(tmp1,min(tmp2,tmp3));
        tmp=maxs-mins;
        if(tmp<ans){
            ans=tmp;
        }
        tmp=(W-i)/2;
        tmp1=i*H;
        tmp2=tmp*H;
        tmp3=(W-i-tmp)*H;
        maxs = max(tmp1,max(tmp2,tmp3));
        mins = min(tmp1,min(tmp2,tmp3));
        tmp=maxs-mins;
        if(tmp<ans){
            ans=tmp;
        }
    }
    cout << ans << endl;
    return 0;
}