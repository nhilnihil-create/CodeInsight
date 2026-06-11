#include<iostream>
#include<stack>
using namespace std;
stack<char>s;

int main()
{
	char a;
	int res=0;
	while(cin>>a)
	{
		res++;
		if(a=='S') s.push(a);
		else if(!s.empty())
		{
			s.pop();
			res=res-2;
		}
	}
	cout<<res<<endl;
	return 0;
}