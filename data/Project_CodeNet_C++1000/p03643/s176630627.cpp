//code_sm
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si set<int>
#define ll long long
#define pb push_back
ll gcd(ll a,ll b)
{
	if(a==0)
	return b;
	else
	return gcd(b%a,a);
}
int main()
{
int n;
cin>>n;
cout<<"ABC"<<n;
}
