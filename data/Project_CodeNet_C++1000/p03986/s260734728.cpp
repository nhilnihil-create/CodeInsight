#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
	char s[200010];
	scanf("%s",&s);
	int x=strlen(s);
	stack<int> a;
	for(int i=0;i<x;i++)
	{
		if(a.empty())
		{
			if(s[i]=='S')
			a.push(0);
			else
			a.push(1);
			continue;
		}
		if(a.top()==0&&s[i]=='T')
		a.pop();
		else{
			if(s[i]=='S')
			a.push(0);
			else
			a.push(1);
		}
		
	}
	cout << a.size() << endl;
}
