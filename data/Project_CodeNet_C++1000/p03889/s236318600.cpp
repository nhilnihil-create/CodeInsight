#include<cstdio>
#include<string>
using namespace std;
char a[100005];
string s,s2,s3;
int main()
{
	scanf("%s",&a);
	s=a;
	for (int j=0;j<=s.size()-1;j++)
	{
		if(s[j]=='b')
		s2+='d';
		if(s[j]=='d')
		s2+='b';
		if(s[j]=='p')
		s2+='q';
		if(s[j]=='q')
		s2+='p';
	}
	for (int j=s2.size()-1;j>=0;j--)
	{
		s3+=s2[j];
	}
	if(s3==s)
	printf("Yes");
	else printf("No");
}