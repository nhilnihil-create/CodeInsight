#include <bits/stdc++.h>
#include <string.h>
using namespace std;

bool match(char s[])
{
	int i,j,k,flag=1;
	k = strlen(s);
	if(k&1) return 0;
	
	for(i=0,j=k/2;i<(k/2);i++,j++)
	{
		if(s[i] == s[j]) continue;
		else 
		{
			flag = 0;
			break;
		}
	}
	if(flag == 1) return 1;
	else return 0;	
}

int main()
{
	char str[300];
	scanf("%s", str);
	int i,j,k;
	
	k = strlen(str);
	for(i=2;i<k;i++)
	{
		if(k%2 == 0) str[k-i+1] = str[k-i] = '\0';
		if(match(str) == 1) 
		{
			cout << strlen(str);
			//puts(str);
			break;
		}
	}
	
//	cout << endl;
//	puts(str);
}

