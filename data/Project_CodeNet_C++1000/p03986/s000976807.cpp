#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<char> S;
	char c;
	while(scanf("%c",&c)!=EOF&&c!='\n')
	{
		if(S.empty())
		{
			S.push(c);
			continue;
		}
		char cc=S.top();
		S.push(c);
		
		if(c=='T'&&cc=='S')
		{
			S.pop();S.pop();
		}
	}
	cout<<S.size();
	
	return 0;
 } 