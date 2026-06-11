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
	stack<char> s;
	for(auto c : a)
	{
		if(c=='B')
		{
   			if(!s.empty())
   			{
   				s.pop();
   			}
		}
		else
		{
			s.push(c);	
		}
	}
	string ans="";
	while(!s.empty())
	{
		ans += s.top();
		s.pop();
	}
	reverse(all(ans));
	cout<<ans;
}       