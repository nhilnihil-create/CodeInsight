#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1000001];
int a[1000001];
int main()
{
    scanf("%s",&s);
	int len=strlen(s);
    for(int i=0;i<len/2+1;i++)
    {
    	if(s[i]=='p'&&s[len-i-1]=='q'||s[i]=='b'&&s[len-i-1]=='d'||s[i]=='q'&&s[len-i-1]=='p'||s[i]=='d'&&s[len-i-1]=='b');
    	else
    	{
    		printf("No");
    		return 0;
		}
	}
    printf("Yes");
}