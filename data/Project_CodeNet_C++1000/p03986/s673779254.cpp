#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
const int maxn=2e5+5;
using namespace std;
int main()
{
	string s;
	cin>>s;
	stack<char> q;
	for(int i=0;i<s.size();i++)
	{
		if(q.size()==0)
		{
			q.push(s[i]);
			continue;
		}
		char temp=q.top();
		if(temp=='S'&& s[i]=='T')
		{
			q.pop();
		}
else
{
q.push(s[i]);
}
	
	}
	cout<<q.size()<<endl;
	return 0;
} 