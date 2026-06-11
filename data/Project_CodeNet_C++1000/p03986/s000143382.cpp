#include<bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

stack<char> p;
char c1,c2;

int main()
{
	while(scanf("%c",&c1)!=EOF && c1!='\n')
	{
		if(p.empty())
		{
			p.push(c1);
			continue;
		}
		c2 = p.top();
		p.push(c1);
		if(c1=='T' && c2=='S')
		{
			p.pop();
			p.pop();
		}
	}
	printf("%d",p.size());
	
	return 0;
 }