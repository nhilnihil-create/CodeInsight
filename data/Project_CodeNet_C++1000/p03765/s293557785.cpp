#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
char s[N],t[N];
int ps[N],pt[N];

int main(){
    scanf("%s%s",s+1,t+1);
    int n = strlen(s+1),m=strlen(t+1);
    for(int i = 1; i<=n; i++)
        ps[i] = ps[i-1]+1+(s[i]=='B');
    for(int i = 1; i<=m; i++)
        pt[i] = pt[i-1]+1+(t[i]=='B');
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int ns = ps[b]-ps[a-1];
        int nt = pt[d]-pt[c-1];
        if(ns%3==nt%3)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}