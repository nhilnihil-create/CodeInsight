#include<bits/stdc++.h>
#define N ((int)(1e5 + 5))
using namespace std;

char s[N] , t[N];

int ssum[N], tsum[N];

int main()
{
    scanf("%s %s",s,t);
    for(int i = 0; s[i]!='\0'; i++){
        ssum[i+1] = ssum[i]+((s[i]-'A')+1);
    }
    for(int i = 0; s[i]!='\0'; i++){
        tsum[i+1] = tsum[i]+((t[i]-'A')+1);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int i , j , a, b;
        scanf("%d %d %d %d",&i,&j,&a,&b);
        i--;
        a--;
        if((ssum[j]-ssum[i])%3==(tsum[b]-tsum[a])%3) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
