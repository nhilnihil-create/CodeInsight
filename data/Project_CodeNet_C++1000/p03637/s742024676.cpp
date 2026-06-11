#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
using ll=long long;

int n;
vector<ll> T(100);

ll gcl(ll x,ll y){
    if(x<y) swap(x,y);
    while(y>0){
        ll t=x%y;
        x=y;
        y=t;
    }
    return x;
}

int main(){
    cin>>n;
    int count0=0,count2=0,count4=0;
    rep(i,0,n){
        int a;cin>>a;
        if(a%2==1) count0++;
        if(a%4==0) count4++;
        if(a%4==2) count2++;
    }
    if(count0<=count4||(n%2==1&&count4==n/2&&count0==n/2+1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}