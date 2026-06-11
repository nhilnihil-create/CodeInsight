#include<bits/stdc++.h>
using namespace std;
char b[17],c[17]={"CODEFESTIVAL2016"};
int main()
{
    int ans=0;scanf("%s",b);
    for(int i=0;i<strlen(b);i++)
        if(b[i]!=c[i])ans++;
    printf("%d\n",ans);
    return 0;
}