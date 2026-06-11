#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main()
{
	cin>>s1;
	s2=s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='p') s1[i]='q';
		else if(s1[i]=='q') s1[i]='p';
		else if(s1[i]=='b') s1[i]='d';
		else if(s1[i]=='d') s1[i]='b';
	}
	reverse(s1.begin(),s1.end());
	if(s1==s2) printf("Yes");
	else printf("No");
	return 0;
}
