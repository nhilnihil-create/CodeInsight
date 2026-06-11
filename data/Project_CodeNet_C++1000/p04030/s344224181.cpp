#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,an="";
	cin>>s;
	for(auto i: s)
	if(i=='B'){if(an.size())an.pop_back();}
	
	else an.push_back(i);
	cout<<an<<endl;
	
}



