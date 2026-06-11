#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<char,char>mp;
int main()
{
    mp['p']='q';
    mp['q']='p';
    mp['b']='d';
    mp['d']='b';
    char s[100010];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(mp[s[i]]!=s[strlen(s)-i-1])return !printf("No");
    }
    return !printf("Yes");
}