#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; 
	string s;
	string res="";
	stack<char>br;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='('){
			br.push(s[i]);
			res=res+"(";
		}
		else if(s[i]==')')
		{
			if(br.size()==0){
				res="("+res;
				res=res+")";}
			else
				{
					br.pop();
					res=res+")";
				}
		}
	}
	for(int i=0;i<br.size();i++)
		res=res+")";
	cout<<res<<"\n";
}