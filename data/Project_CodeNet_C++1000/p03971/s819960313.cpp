#include<iostream>
#include<cstdio>
#define endl '\n'
using namespace std;
int main()
{
    int n,A,B;
    char s[100001];
    int cnt[100001] = {0};
    cin>>n>>A>>B>>s;
    int t = A+B;
    int total = 0,b = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i]=='c')continue;
        else{
            if(s[i]=='a' && total<t)
                {total++;cnt[i] = 1;}
            else if( s[i]=='b' && total<t)
                if(b<B) total++,b++,cnt[i]=1;
        }
    }
    for(int i = 0; i<n; i++){
        if(cnt[i]==0)puts("No");
        else if(cnt[i])puts("Yes");
    }
    return 0;
}
