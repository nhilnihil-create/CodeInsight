#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long 
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	if(a.length()>b.length())cout<<"GREATER";
	else if(b.length()>a.length())cout<<"LESS";
	else{
		if(a>b)cout<<"GREATER";
		else if(b>a)cout<<"LESS";
		else cout<<"EQUAL";
	}
	
}