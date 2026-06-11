#include<bits/stdc++.h>
using namespace std;
long long i;
string s,S;
int main()
{
	std::ios_base::sync_with_stdio(false),cin.tie(0);
	cin>>s,S=s,reverse(s.begin(),s.end());
	for (i=0;i<s.size();i++)
		s[i]==98?s[i]=100:s[i]==100?s[i]=98
			:s[i]==112?s[i]=113:s[i]==113?s[i]=112:0;
	s==S?puts("Yes"):puts("No");
	return 0;
}