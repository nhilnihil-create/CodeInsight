#include <stdio.h>
#include <iostream>
#include <vector>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define vecll vector<ll>
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
bool f(ll n){
    ll sum=0,cnt=0,p=n*(n+1)/2;
    vecll a(n);
    rep(i,n) sum+=a[i]=in();
    if(sum%p!=0)return false;
    ll num=sum/p;
    rep(i,n){
        ll k=a[(i+1)%n]-a[i]-num;
        if(k>0||k%n!=0)return false;
        cnt-=k/n;
    }
    return cnt==num;
}
int main(){
    string a=f(in())?"YES":"NO";
    cout<<a;
}