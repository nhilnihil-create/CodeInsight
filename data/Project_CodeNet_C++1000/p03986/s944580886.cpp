#include<iostream>
#include<stdio.h>
#include<stack> 
using namespace std;
int main()
{
	stack<char> st;
	char a;
	while(cin>>a)
	{
		if(st.size()>0&&st.top()=='S'&&a=='T')
		st.pop();
		else
		{
			st.push(a);
		}
	}
	cout<<st.size()<<endl;
}