#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	string s;
	cin>>s;
	ll len=s.length();
	ll rock_count=0,paper_count=0,ans=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='g')
		{
			if(paper_count<rock_count)
				ans++,paper_count++;
			else
				rock_count++;
		}
		else
		{
			if(paper_count<rock_count)
				paper_count++;
			else
				ans--,rock_count++;
		}
	}
	cout<<ans;
	return 0;
}

