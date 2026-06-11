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
#include<unordered_map>
#include<set>
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
#define all(a) a.begin(),a.end()
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define sizeoof(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/*約数*/vector<ll>div(ll a){vector<ll>b;ll i;rep(i,1,a){if(!a%i)push(b,a);}return b;}
llfor;///////////////////////////////////////////////////////////
int main(){
 ll n,m;
 sc(n);sc(m);
 ll x[m+10]={},y[m+10]={},ball[n+10]={1};
 bool key[n+10]={false};
 rep(i,0,m){
  sc(x[i]);sc(y[i]);
 }
 rep(i,0,n+10)ball[i]=1;
 ll ans=0;
 key[1]=true;
 rep(i,0,m){
  if(ball[x[i]]==0)continue;
  ball[x[i]]--;
  if(key[x[i]]==true&&key[y[i]]==false)key[y[i]]=true;
  if(ball[x[i]]==0)key[x[i]]=false;
  ball[y[i]]++;
 // cout<<x[i]<<" "<<ball[x[i]]<<" "<<key[x[i]]<<" "<<y[i]<<" "<<ball[y[i]]<<" "<<key[y[i]]<<endl;
 }
 //rep(i,1,n+1)cout<<i<<" "<<ball[i]<<" "<<key[i]<<endl;
 rep(i,1,n+1){
  if(key[i]==true)ans++;
 }
 pr(ans);
return 0;}

