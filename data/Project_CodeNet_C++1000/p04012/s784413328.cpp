//Pradeep_7
//double tt = clock();
//if((clock()-tt)/CLOCKS_PER_SEC > 1) break;
#include<bits/stdc++.h>
#define mp make_pair 
#define pb push_back
#define fi first
#define se second 
#define IO ios_base::sync_with_stdio(false);  cin.tie(NULL);
#define ll long long int
#define nn cout<<"\n"
#define tcc int tc;	cin>>tc; while(tc--)
#define arr(a,n)	for(int i=0;i<n;i++)		cin>>a[i]
#define all(a)	a.begin(),a.end()
#define rall(a)	a.rbegin(),a.rend()
using namespace std;     
int main()
{
	string a;
	cin>>a;
	map<char,int> mp;
	for(char c : a)
	{
		mp[c]++;
	}
	for(int i=0;i<a.size();i++)
	{
		if(mp[a[i]]% 2!=0)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
