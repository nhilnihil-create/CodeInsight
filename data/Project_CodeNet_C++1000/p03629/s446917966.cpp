#include<bits/stdc++.h>
#define N 250000
using namespace std;

int L[N],R[N],ans=0;
int check[30]={0};

int main()
{
    char s[N];
    scanf("%s",s);
    int len=strlen(s);
    int now=26;
    R[0]=len-1;
    for(int i=len-1;i>=0;i--)
    {
        if(!check[s[i]-'a'])
        {
            now--;
            check[s[i]-'a']=1;

            if(now==0)
            {
                L[ans]=i;
                ans++;
                R[ans]=i-1;
                now=26;
                memset(check,0,sizeof(check));
            }
        }
    }
    L[ans]=0;
    int last=0;
    char ans_now;
    for(int i=ans;i>=0;i--)
    {
        int now=26;
        memset(check,0,sizeof(check));
        for(int j=last;j<=R[i];j++)check[s[j]-'a']=1;
        for(int j=0;j<26;j++)
        if(!check[j])
        {
            printf("%c",j+'a');
            ans_now=j+'a';
            break;
        }
        for(int j=last;j<len;j++)if(s[j]==ans_now)
        {
            last=j+1;
            break;
        }
    }
return 0;
}