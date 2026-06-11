#include <iostream>
#include <string.h>
using namespace std;

char s[100010];
char s1[100010];

int main()
{
    cin>>s;
    int l = strlen(s);
    if(l&1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<l;i++) s1[i] = s[l-i-1]; 
    for(int i=0;i<l;i++)
    {
        if(s1[i] == 'b') s1[i] = 'd';
        else if(s1[i] == 'd') s1[i] = 'b';
        else if(s1[i] == 'p') s1[i] = 'q';
        else s1[i] = 'p';
    }
    if(!strcmp(s1, s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}