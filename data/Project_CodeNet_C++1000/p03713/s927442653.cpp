#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
//key point is to take one as whole and other two as max diving each other 

ll minarea(ll h ,ll w){
    if(w%3==0)return 0;
    else{
        ll d=1e9;
        for(int i=1;i<w;i++){
            ll a=h*i;
            ll b=(w-i)*(h-h/2);
            ll c=(w-i)*(h/2);
            d=min(d,max({a,b,c})-min({a,b,c}));
        }
        return min(d,h);
    }
}
int main(){
    ll h,w;
    cin>>h>>w;
    cout<<min(minarea(h,w),minarea(w,h))<<endl;
}