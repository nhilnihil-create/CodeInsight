#include <stdio.h>
#include <iostream>
#include <vector>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define vecll vector<ll>
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
string strin(){string s;cin>>s;return s;}
bool func(ll n){
    ll sum=0,cnt=0,p=n*(n+1)/2;
    vecll a(n),b(n);
    rep(i,n) sum+=a[i]=lin();
    if(sum%p!=0)return false;
    ll num=sum/p;
    rep(i,n){
        b[i]=a[(i+1)%n]-a[i]-num;
        if(b[i]>0||b[i]%n!=0)return false;
        cnt-=b[i]/n;
    }
    if(cnt!=num)return false;
    return true;
}
int main(){
    string ans=func(in())?"YES":"NO";
    cout<<ans<<endl;
}