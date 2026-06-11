#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll n,s[101],sum=0;
    cin>>n;
    rep(i,n){
        cin>>s[i];
        sum+=s[i];
    }
    sort(s,s+n);
    rep(i,n){
        if(sum%10!=0) break;
        if(s[i]%10!=0) sum-=s[i];
    }
    if(sum%10==0){
        cout<<0;
    }else{
        cout<<sum;
    }
}