#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<functional>
#include<limits.h>
#include<stdlib.h>
#include<string>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j,k
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define sort(a) sort(a.begin(),a.end())
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
ll ans=0;llfor;///////////////////////////////////////////////////////////
int main(){
 ll w,n,h,k;
 sc(w);sc(h);sc(n);
 ll a[n+10],l[n+10],m[n+10];
 bool xy[w+10][h+10];
 
 rep(i,0,w+1){
  rep(j,0,h+1){
   xy[i][j]=false;
  }
 }
 rep(i,0,n){
  sc(l[i]);sc(m[i]);sc(a[i]);

 if(a[i]==1){
   rep(j,0,l[i]+1){
    rep(k,0,1+h){
     xy[j][k]=true;
    }
   }
  }
  if(a[i]==2){
   rep(j,l[i]+1,1+w){
    rep(k,0,1+h){
     xy[j][k]=true;
    }
   }
  }
  if(a[i]==3){
   rep(j,0,m[i]+1){
    rep(k,0,1+w){
     xy[k][j]=true;
    }
   }
  }
  if(a[i]==4){
   rep(j,m[i]+1,h+1){
    rep(k,0,1+w){
     xy[k][j]=true;
    }
   }
  }
  
 }

 ll ans=0;
 rep(i,1,w+1){
  rep(j,1,h+1){
   if(xy[i][j]==false)
     ans++;
  }
 }
 pr(ans);
  return 0;}