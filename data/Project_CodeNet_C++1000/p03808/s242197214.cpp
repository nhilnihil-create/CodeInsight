/*                                  /   \                                                                   (Hello)//JSM//*/      
/*                                 /*****\                                                                              */
/*     Jai Shree Mataji           /       \ |\| |_| $ |-| K                                                            */
#include<vector>
#include<iostream>
#include<algorithm>                
#include<string.h>                 
#include<bits/stdc++.h>            
#include<cstring>                  
#include<map>                     
#include<cmath>                  
#include<set>
using namespace std;            
#define ll long long int        
#define ld long double
#define MOD 1000000007 
#define PI 3.1415926535897932384626433832795                                               
#define YY cout<<"YES"
#define NN cout<<"NO"
#define EE cout<<"\n"
#define ee cout<<"\n"
#define ne cout<<"-1"
#define pb push_back 
#define fi first
#define se second
#define mkp make_pair    
#define mkt make_tuple
#define sall(v ) sort(v.begin(), v.end())      
#define all(v )  v.begin(), v.end()      
#define rall(v )  reverse(v.begin(), v.end())      
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define vl vector<ll>
#define vll vector< pair<ll,ll> > 
#define mpl map<ll, ll>
#define pr pair<ll,ll>
#define tpl tuple<ll,ll,ll>
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) {return (a.second < b.second); }
ll soltn(ll x, ll n) {if(x>=0) return x%n;    else return n+x%n;}
ll pd(ll x,ll y){if(x%y==0) return x/y;else return x/y+1;}
ll coda(ll n,ll d){ll count=0;while(n!=0){if(n%10==d)count++;n/=10;}return count;}
ll pow1(ll n,ll p){if(p==0)return 1;ll x=pow1(n, p/2);x=(x*x)%MOD;if(p%2==0) return x;else return (x*n)%MOD;}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);	
	  ll t=1;
      
//	   cin>>t;

	      while(t--)
{
/*
5
6 9 12 10 8*/
ll n,m,j,k,l,i;
cin>>n;
ll a[n],s=0;
fo(i,n)
{
	cin>>a[i];
	s+=a[i];
}
ll ini=0;
ll f=1;
ll N=((n)*(n+1))/2;
if(s%N!=0)
f=-1;
ini=(s/N);
fo(i,n)
{
	ll p=ini-(a[(i+1)%n]-a[i]);
	if(p<0||p%n!=0)
	f=-1;
}
if(f==1||n==1)
YY;
else
NN;
ee;
}
return 0;
}












