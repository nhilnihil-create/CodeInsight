#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	int cnt_r=0;
	string ans="";
	rep(i,N)
	{
		if(S[i]==')')
		{
			if(cnt_r<=0)
			{
				ans+='(';
			}
			else
			{
				cnt_r--;
			}
		}
		else
		{
			cnt_r++;
		}	
	}
	ans+=S;
	rep(i,cnt_r)
	{
		ans+=')';
	}
	cout<<ans<<endl;
	return 0;
}
