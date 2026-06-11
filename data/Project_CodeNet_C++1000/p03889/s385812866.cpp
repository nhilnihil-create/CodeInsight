#include<bits/stdc++.h>
using namespace std;
bool is;
char ch,now,a;
string s;
stack<int> t;
int main()
{
	cin>>s; int n=s.size();
	for(int i=0;i<n;i++)
	    t.push(s[i]);
	for(int i=0;i<n;i++)
	{
		now=t.top();
	    if(now=='b') a='d';
	    else if(now=='d') a='b';
	    else if(now=='p') a='q';
	    else if(now=='q') a='p';
	    if(a==s[i]) t.pop();
		else
		{
			is=1; break;
		}
	}
	if(!is) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}