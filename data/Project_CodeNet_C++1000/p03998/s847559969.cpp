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
ll ans=0;llfor;///////////////////////////////////////////////////////////
char a[110],b[110],c[110];
ll alen,blen,clen;
ll acnt=0,bcnt=0,ccnt=0;
void turn_a();
void turn_b();
void turn_c();
ll cnt=0;
void turn_a(){
 //pr(cnt);puts("turn_a");cnt++;
 //pr(alen);
 alen-=1;
 if(alen<=0){puts("A");return;}
 else{
 acnt++;
 if(a[acnt-1]=='a')turn_a();
 else if(a[acnt-1]=='b')turn_b();
 else if(a[acnt-1]=='c')turn_c();
 }
}
void turn_b(){
 //pr(cnt);puts("turn_b");cnt++;
// pr(blen);
 blen-=1;
 if(blen<=0){puts("B");return;}
 else{
 bcnt++;
 if(b[bcnt-1]=='a')turn_a();
 else if(b[bcnt-1]=='b')turn_b();
 else if(b[bcnt-1]=='c')turn_c();
 }
}
void turn_c(){
 //pr(cnt);puts("turn_c");cnt++;
 clen-=1;//pr(clen);
 if(clen<=0){puts("C");return;}
 else{
 ccnt++;
 //pr(clen);
 if(c[ccnt-1]=='b')turn_b();
 else if(c[ccnt-1]=='c')turn_c();
 else if(c[ccnt-1]=='a')turn_a();
 }
}
int main(){
 sc(a);sc(b);sc(c);
 alen=strlen(a)+1;blen=strlen(b)+1;clen=strlen(c)+1;
 turn_a();

return 0;}