# include <bits/stdc++.h>
using namespace std;
string s,tmp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	tmp=s;
	reverse(tmp.begin(),tmp.end());
	int Len=tmp.size();
	for(register int i=0;i<Len;++i)
	{
		switch(tmp[i])
		{
			case 'b':tmp[i]='d';break;
			case 'd':tmp[i]='b';break;
			case 'p':tmp[i]='q';break;
			case 'q':tmp[i]='p';break;
		}
	}
	if(tmp==s)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}