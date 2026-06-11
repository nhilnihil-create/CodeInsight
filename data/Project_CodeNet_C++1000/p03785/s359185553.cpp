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
 ll n,c,k;
 sc(n);sc(c);sc(k);
 llpvec t(n);
 ll b;
 bool a[n+10];


rep(i,0,n){
  sc(b);
  t[i]={b,b+k};
  a[i]=false;
 }
 sort(all(t));
 //rep(i,0,n)cout<<i<<" "<<t[i].first<<" "<<t[i].second<<endl;pnn;
 ll cnt=0;ll ans=0;
  
 rep(i,0,n){
  if(!a[i]){
   cnt=1;
   a[i]=true;
   for(j=i+1;t[j].first<=t[i].second&&j<n&&cnt<c;j++){
    if(t[j].second>=t[i].second){
     a[j]=true;cnt++;
     //cout<<i<<" "<<j<<" "<<cnt<<" "<<ans<<endl;
    }
   }
   ans++;
  }
 }
 
 pr(ans);
  
   
return 0;}