#include<iostream>
#include<algorithm>
using namespace std;
int h,w;
int c[26];
main()
{
	cin>>h>>w;
	string s;
	for(int i=0;i<h;i++)
	{
		cin>>s;
		for(int j=0;j<w;j++)
		{
			c[s[j]-'a']++;
		}
	}
	int cnt1=0,cnt2=0;
	for(int i=0;i<26;i++)
	{
		if(c[i]%2)cnt1++;
		c[i]-=c[i]%2;
		if(c[i]%4==2)cnt2++;
	}
	int ans1=h*w%2,ans2=h%2*(w/2)+w%2*(h/2);
	if(cnt1!=ans1||cnt2>ans2||(ans2-cnt2)%2)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
