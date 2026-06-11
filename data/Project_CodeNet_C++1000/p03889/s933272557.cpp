#include<bits/stdc++.h>
std::string s;
std::map<char,char> map;
int l,hl;
int main()
{
	map['b']='d';
	map['d']='b';
	map['p']='q';
	map['q']='p';
	std::cin>>s;
	if(s.length()&1)
	{
		puts("No");
		return 0;
	}
	l=s.length();
	hl=l>>1;
	for(int i=0;i<hl;++i)
		if(map[s[i]]!=s[l-i-1])
		{
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}