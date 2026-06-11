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
/*pi*/double pi=acos(-1);
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/*Fibonacci数列*/ll fib(ll x){ll i,fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];}
/*桁数*/ll dig(ll n){ll d=0,i=0;while(n/10>0){i++;d++;}return d;}
llfor;ll ans=0;////////////////////////////////////////////////////////////
int main(){
 ll nx,ny,gx,gy;
 cin>>nx>>ny>>gx>>gy;
 ll cnt=0;
 //startを0に合わせる
 gx-=nx;nx=0;
 gy-=ny;ny=0;
  
 string s;
 //1回目goalまで
 //x方向
 if(nx<gx){
  while(nx<gx){
   s+='R';nx++;
  }
 }
 else if(nx>gx){
  while(nx>gx){
   s+='L';nx--;
  }
 }
 //y方向
 if(ny<gy){
  while(ny<gy){
   s+='U';ny++;
  }
 }
 else if(ny>gy){
  while(ny>gy){
   s+='D';ny--;
  }
 }
 
 //1回目(0,0)まで
 ll len=s.length();
 rep(i,cnt,len){
  if(s[i]=='U')s+='D';
  if(s[i]=='D')s+='U';
  if(s[i]=='L')s+='R';
  if(s[i]=='R')s+='L';
 }
  cnt=len-1;
 nx=0;ny=0;
 //重複を避けるための移動
 if(gy>0){
  s+='D';ny--;
 }
 else{
  s+='U';ny++;
 }
   
 //2回目goalまで
 //x方向
 if(nx<gx){
  while(nx<gx+1){
   s+='R';nx++;
  }
 }
 else if(nx>gx){
  while(nx>gx-1){
   s+='L';nx--;
  }
 }
 //y方向
 if(ny<gy){
  while(ny<gy){
   s+='U';ny++;
  }
 }
 else if(ny>0){
  while(ny>0){
   s+='D';ny--;
  }
 }
 if(nx>gx){
  s+='L';nx--;
 }
 else if(nx<gx){
  s+='R';nx++;
 }
 cnt=(cnt+1)*2;
 //1回目(0,0)まで
 len=s.length();
 rep(i,cnt,len){
  if(s[i]=='U')s+='D';
  if(s[i]=='D')s+='U';
  if(s[i]=='L')s+='R';
  if(s[i]=='R')s+='L';
 }
 pr(s);
 return 0;}