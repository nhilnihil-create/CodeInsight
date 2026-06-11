#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

stack<char>a;
char c [100004];
int bo;

char zh ( char p );

int main()
{
	string c;
	getline(cin,c);
	for(int i=0;c[i]!='\0';i++)
	{
		a.push(c[i]);
	}
	for(int i=0;c[i]!='\0';i++)
	{
		if(c[i]==zh(a.top()))
			a.pop();
		else
		{
			bo=1;
			break;
		}
	}
	if(bo==1)
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
	}
char zh(char p)
{
	switch(p)
	{
		case 'p':return 'q';
		case 'q':return 'p';
		case 'b':return 'd';
		case 'd':return 'b';
	}
	return '0';
}