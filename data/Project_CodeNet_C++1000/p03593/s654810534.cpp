#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int h,w;
	cin >> h >> w;
	vector<string>s(h);
	for(int i = 0;i<h;i++)cin >> s[i];
	vector<int> cnt(26);
	for(int i = 0;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			cnt[s[i][j]-'a']++;
		}
	}
	if(h%2==0&&w%2==0)
	{
		for(int i = 0;i<26;i++)
		{
			if(cnt[i]%4!=0)
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
		cout<<"Yes"<<endl;
		return 0;
	}
	else if(h*w%2==1)
	{
		int a =0 ,b = 0;
		for(int i = 0;i<26;i++)
		{
			if(cnt[i]%2==1)a++;
			if(cnt[i]%4!=0&&cnt[i]%2==0)b++;
		}
		if(a>1||(b*2>h+w-1))
		{
			cout<<"No"<<endl;
			return 0;
		}
		else
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	else
	{
		if(h%2==1)swap(h,w);
		int a=0,b=0;
		for(int i = 0;i<26;i++)
		{
			if(cnt[i]%2==1)a++;
			if(cnt[i]%4!=0&&cnt[i]%2==0)b++;
		}
		if(a>0||(b*2>h))
		{
			cout<<"No"<<endl;
			return 0;
		}
		cout<<"Yes"<<endl;
	}
	return 0; 
}
