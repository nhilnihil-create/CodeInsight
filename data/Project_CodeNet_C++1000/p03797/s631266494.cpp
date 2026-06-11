#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,m;cin>>n>>m;
	ll res=min(2LL*n,m);
	ll ct=res/2;
	m=m-res;
	m/=4;
	cout<<ct+m;

	
}