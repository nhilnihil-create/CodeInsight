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
#include<cmath>
#include<cstring>
#include<set>
#include<climits>
#include<deque>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define all(a) a.begin(),a.end()
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
llfor;ll mod=1000000007;
/*pi*/double pi=acos(-1);
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll ans=1;rep(i,0,n){ans*=x;ans%=mod;}return ans;}
/*階乗*/ll fact(ll x){ll ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){ll ans=1;rrp(i,n-r+1,n+1){ans*=i;ans%=mod;}return ans/=fact(r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/*Fibonacci数列*/ll fib(ll x){ll fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];}
/*桁数*/ll dig(ll n){ll d=1,tmp=n;while(tmp/10>0){tmp/=10;d++;}return d;}
double ans=0;
////////////////////////////////////////////////////////////
int main(){
 vector<ll>odd,even;
 ll n;
 sc(n);
 ll b;
 rep(i,0,n){
  sc(b);
  if((i+1)%2==0)push(even,b);
  else push(odd,b);
 }
 if(n%2==0){
  rrp(i,n/2,0)cout<<even[i]<<" ";
  rep(i,0,n/2)cout<<odd[i]<<" ";
  pnn;return 0;
 }
 rrp(i,n/2+1,0)cout<<odd[i]<<" ";
 rep(i,0,n/2)cout<<even[i]<<" ";
 pnn;
return 0;}
