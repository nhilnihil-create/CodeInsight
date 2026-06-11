#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>

using namespace std;
typedef long long ll;
typedef pair<int,int>P;

bool same(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=s[0])return false;
	}
	return true;
}

int ch(string s,char rep)
{
	int cnt=0;
	while(!same(s))
	{
		string ns(s.length()-1,'@');
		for(int i=0;i<s.length()-1;i++)
		{
			if(s[i]==rep||s[i+1]==rep)
			{
				ns[i]=rep;
			}
			else
			{
				ns[i]=s[i];
			}
		}
		s=ns;
		cnt++;
	}
	return cnt;
}

int main()
{
	string S;
	cin>>S;
	int res=10000;
	for(char a='a';a<='z';a++)
	{
		res=min(ch(S,a),res);
	}
	cout<<res<<endl;
}