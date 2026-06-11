//Author : Prakhar Asaiya
#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define REPN(i,a,b) for(ll i = a; i <= b; ++i)
#define REPV(i,a,b) for(ll i = a; i >= b; --i)
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define with_tests int t; cin>>t; while(t--){ solve(); }
#define without_tests solve();
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 100000000
#define ff first
#define ss second
const int M=1e9+7;


void solve()
{
	int x,a,b;
	cin>>x>>a>>b;
	if(abs(x-a) < abs(x-b))
	cout<<"A";
	else
	cout<<"B";
}

int main()
{/*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#*/
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  //with_tests;
  without_tests;
  return 0;
}