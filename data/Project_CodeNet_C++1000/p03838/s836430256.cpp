#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int main(){
    int x,y;cin>>x>>y;
    int ans=0;
    if(x>=0){
        if(y>=x) ans=y-x;
        else if(0<y&&y<x) ans=1+(x-y)+1;
        else if(-x<y&&y<=0) ans=1+x+y;
        else ans=-y-x+1;
    }else{
        if(y<=x) ans=1+(x-y)+1;
        else if(x<y&&y<=0) ans=y-x;
        else if(0<y&&y<=-x) ans=(-y-x)+1;
        else ans=1+y+x;
    }
    cout<<ans<<endl;
    return 0;
}