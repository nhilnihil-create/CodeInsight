#include<iostream>
#include<string>
#include<stack>
using namespace std;
//TSTTSS
//T ST TST T TT STT SSTT
int main()
{
	stack<char> s;
	string a;
	cin>>a;
	//char c;
	int n=a.size();
	s.push(a[0]);
	for(int i=1;i<n;i++)
	{
		if(!s.empty()) 
		{
			char c=s.top();
			if(c=='S'&&a[i]=='T') 
				s.pop();
			else 
				s.push(a[i]); 
		}
		else s.push(a[i]);
			
	}
	cout<<s.size();
	return 0;
}