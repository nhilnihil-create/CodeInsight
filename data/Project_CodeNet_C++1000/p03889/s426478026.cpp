//#pragma GCC optimize("Ofast")
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy 2333333
#define bql 2147483647
using namespace std;
string s,ss;
int main()
{
	fast;
	cin>>s;
	ss=s;
	for (int i=0;i<=s.size()-1;i++)
	   if (s[i]=='b')
		    s[i]='d';
		 else if (s[i]=='d')
		    s[i]='b';
		 else if (s[i]=='p')
		    s[i]='q';
		 else
		    s[i]='p';
	reverse(s.begin(),s.end());
	for (int i=0;i<=s.size()-1;i++)
	   if (s[i]!=ss[i])
		 {
			 cout<<"No\n";
			 return 0;
		 }
	cout<<"Yes\n";
	return 0;
}
