#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

bool func(char x){
    if(x=='Y') return 1;
    else return 0;
}
bool check(ll int y){
    printf("? %lld\n",y);
  	fflush(stdout);
    char c;
    cin>>c;
    return func(c);
}
void ans(ll int z){
    printf("! %lld",z);
}

main(){
    if(check(1e11)){
        int l=0,r=10;
        while(l!=r){
            int mid=(l+r)/2;
            bool f=check(pow(10,mid)*2);
            if(f) r=mid;
            else l=mid+1;
        }
        ans(pow(10,l));
        return 0;
    }
    ll int l=0,r=10;
    while(l!=r){
        int mid=(l+r+1)/2;
        bool f=check(pow(10,mid));
        if(f) l=mid;
        else r=mid-1;
    }
    int dig=l;
    l=pow(10,dig);
    r=pow(10,dig+1);
    while(l!=r){
        ll int mid=(l+r)/2;
        bool f=check(mid*10);
        if(f) r=mid;
        else l=mid+1;
    }
    ans(l);
    return 0;

    
}
