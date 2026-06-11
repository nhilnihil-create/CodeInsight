#include<bits/stdc++.h>
using namespace std;
const int N=250000;
int ll[N],rr[N],ans,check[30];
string s;
int main()
{
    cin>>s;
    int len=s.length(),now=26;
    rr[0]=len-1;
    for(int i=len-1;i>=0;i--)if(!check[s[i]-'a'])
    {
        now--;
        check[s[i]-'a']=1;
        if(now==0)
        {
            ll[ans]=i;ans++;rr[ans]=i-1;now=26;
            memset(check,0,sizeof(check));
        }
    }
    ll[ans]=0;
    int last=0;
    char ans_now;
    for(int i=ans;i>=0;i--)
    {
        int now=26;
        memset(check,0,sizeof(check));
        for(int j=last;j<=rr[i];j++)check[s[j]-'a']=1;
        for(int j=0;j<26;j++)if(!check[j])
        {
            printf("%c",j+'a');
            ans_now=j+'a';
            break;
        }
        for(int j=last;j<len;j++)
        if(s[j]==ans_now){last=j+1;break;}
    }
	return 0;
}