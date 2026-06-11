#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
typedef long long ll;
ll n,a,b;
ll c[MAXN];


bool judge(ll x){//对二分的值进行判断
    ll sum=0;
    for(ll i=1;i<=n;i++){   
        ll j=c[i]-x*b;      //减去x个b  
        if(j>0) {       //若小于零就不可以用a方式炸了
            if(j%(a-b)==0)  sum+=j/(a-b);//减去x*b后剩下的量/（a-b）就是可以用a方式炸几次
            else sum+=j/(a-b)+1;
        }
        if(sum>x)   return false;       //x次a方式炸不完全就排除 
    }

return true;
}

int main(){

    cin>>n>>a>>b;
    ll max1=0;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
        max1=max(max1,c[i]);        //找出最大右边界 减少二分次数
    }
    ll l=1; ll r=max1;
        while(r>l){
        ll mid=(l+r)/2;
        if(judge(mid))   r=mid;
        else l=mid+1;
    }

    cout<<r<<endl;

return 0;}