#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll h,w,m,a,b,k;
    cin>>h>>w;
    if(h%3==0||w%3==0){
        cout<<0;
        return 0;
    }
    if(h>w){
        m=w;
    }else{
        m=h;
    }
    a=(h+1)/3;
    b=w/2;
    k=max({a*w,(h-a)*b,(h-a)*(w-b)})-min(a*w,(h-a)*b);
    if(m>k){
        m=k;
    }
    a=(w+1)/3;
    b=h/2;
    k=max({a*h,(w-a)*b,(w-a)*(h-b)})-min(a*h,(w-a)*b);
    if(m>k){
        m=k;
    }
    cout<<m;
}