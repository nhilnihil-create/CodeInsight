#include<bits/stdc++.h>
using namespace std;
string s;
bool ok1,ok2;
int main()
{
	cin>>s;
	ok1=(s[0]==s[s.size()-1]);
	ok2=s.size()%2;
	if(ok1!=ok2)
	{
		cout<<"First"<<endl;
	}
	else
	{
		cout<<"Second"<<endl;
	}
	return 0;
}