#include<bits/stdc++.h>
using namespace std;
char s[100007];
int get[128];
int main()
{
    get['b']=0,get['p']=1,get['d']=2,get['q']=3;
    scanf("%s",s+1);
    for(int l=strlen(s+1),i=1;i<=(l>>1)+1;i++)
    {
        if(get[s[i]]^((get[s[l-i+1]]+2)%4))
			return puts("No"),0;
    }
    return puts("Yes"),0;
}