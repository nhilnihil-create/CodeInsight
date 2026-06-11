#include<bits/stdc++.h>
using namespace std;

int n,s[200],sum=0;

int main()
{
    scanf("%i",&n);
    for(int i=0;i<2*n;++i) scanf("%i",&s[i]);
    sort(s+0,s+2*n);
    for(int i=0;i<2*n;i+=2) sum+=s[i];
    printf("%i",sum);
    
    return 0;
}