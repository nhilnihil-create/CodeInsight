#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define f first
#define s second
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s,h="";
	cin>>s;
	h+= s[0];
	bool flag =0;
	for(int i = 1;i<s.length() ; i++)
	{
		if(s[i]==s[i-1])
		{
			cout<<i<<" "<<i+1<<endl;
			flag =1;
			break;
		}
		else
		{
			h+= s[i];
			string f="";
			if(i>1)
				f = s.substr(i-2,3);//+= s[i-2]+s[i-1]+s[i];
			else
				f = h;
			sort(h.begin(),h.end());
			for(int j =0; j<2; j++)
			{
				if(h[j]==h[j+1])
				{
					cout<<i-1<<" "<<i+1<<endl;
					flag = 1;
					break;
				}
			}
			if(f.length()==3)
				h = f.substr(1,2);
			if(flag)
				break;
		}
	}
	if(!flag)
		cout<<-1<<" "<<-1<<endl;
	return 0;
}