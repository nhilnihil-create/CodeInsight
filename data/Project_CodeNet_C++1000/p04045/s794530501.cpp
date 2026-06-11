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
#define ff first
#define ss second
#define mkp make_pair    
#define mkt make_tuple
#define all(v ) sort(v.begin(), v.end())      
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define vl vector<ll>
#define vc vector<char> 
#define vll vector< pair<ll,ll> > 
#define pr pair<ll,ll>
#define mps map<string ,ll>
#define mpc map<char ,char>
#define mpl map<ll,ll>
#define tpl tuple<ll,ll,ll>
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);	
	  ll t=1;
//	   cin>>t;
	      while(t--)
{

/*
1000 8
1 3 4 5 6 7 8 9*/
ll n,m,i,j,k;
cin>>n>>m;
ll a[m];
mpl M;
fo(i,m)
{
	cin>>a[i];
    M[a[i]]++;
}
for(i=1;i<=1000000;i++)
{ll g=-1;
	if(i>=n)
	{g=1;
		ll N=i;
		while(N!=0)
		{
			if(M[N%10]!=0)
			{
				g=-1;
			break;
			}
			N/=10;
		}
	}
	if(g==1)
	{
		cout<<i;
		return 0;
	}
}
}
return 0;
}

