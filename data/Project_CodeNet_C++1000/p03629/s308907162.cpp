#include <bits/stdc++.h>
using namespace std;

char s[2000010];
set <int> S;
int nextt[2000010][30],i,j;
int now[30];
int now_tot[2000010];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int tot=0;
    for (i=len; i>=1; i--)
    {
        S.insert(s[i-1]-'a' );
        now_tot[i]=tot;
        if (S.size()==26)
        {
            tot++;
            S.clear();
        }
    }
    if (tot==0)
    {
        for(i=0; i<26; i++)
            if(S.count (i )==0)
            {
                printf("%c",i+'a');
                return 0;
            }
    }
    memset(now,0,sizeof(now));
    for (i=len; i>=1; i--)
    {
        for (j=0; j<26; j++)
            nextt[i][j]=now[j];
        now[s[i-1]-'a']=i;
    }
    int tmp=0;
    for (i=0; i<26; i++)
        if (S.count(i)==0)
        {
            tmp=now[i];
            break;
        }
    printf("%c",s[tmp-1]);
    for (i=1; i<tot; i++)
    {
        for (j=0; j<26; j++)
            if(now_tot[nextt[tmp][j]]==now_tot[tmp] -1 )
            {
                tmp=nextt[ tmp ][ j ];
                printf("%c",s[tmp-1]);
                break;
            }
    }
    for(i=0; i<26; i++)
        if(nextt[ tmp ][ i ]==0)
        {
            printf("%c",i+'a');
            break;
        }
    return 0;
}
