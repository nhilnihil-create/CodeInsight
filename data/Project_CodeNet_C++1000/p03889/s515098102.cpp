#include<bits/stdc++.h>
using namespace std;
long long i;
string s;
int main()
{
	cin>>s;
	if (s.length()%2!=0) printf("No");
	else
	{
	for (i=s.length()-1;i>=s.length()/2-1;i--)
		{
			if (s[i]=='b'&&(s[s.length()-i-1]!='d')) 
			{
				printf("No");
				return 0;
			}
			if (s[i]=='d'&&(s[s.length()-i-1]!='b')) 
			{
				printf("No");
				return 0;
			}
			if (s[i]=='p'&&(s[s.length()-i-1]!='q')) 
			{
				printf("No");
				return 0;
			}
			if (s[i]=='q'&&(s[s.length()-i-1]!='p')) 
			{
				printf("No");
				return 0;
			}
		}
		printf("Yes");
	}
	return 0;
}