#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vec(a) vector<int>a
using namespace std;
//fibonacci
int binet(int n)
{
	return (pow((1+sqrt(5)),n-1)-pow((1-sqrt(5)),n-1))/(pow(2,n-1)*sqrt(5));
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	fastio
	ll i,j,k,l,m,n;
	string str;
	cin>>str;
	set <char> a;
	for(i=0;i<str.length();i++)
	{
		a.insert(str[i]);
	}
	set<char>::iterator itr;
	itr=a.end();
	k=0;
	for(i=97;i<=122;i++)
	{
		if(a.count((char)i)==0)
		{
			k=1;
			break;
		}
	}
	if(k==0)
		cout<<"None"<<"\n";
	else
		cout<<(char)i<<"\n";

	return 0;
}
	