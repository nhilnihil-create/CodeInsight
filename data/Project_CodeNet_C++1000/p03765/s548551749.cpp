#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
char s[max_n],t[max_n];
int cnts[max_n],cntt[max_n];
int q;
int main(){
    scanf(" %s %s",s+1,t+1);
    int ns=strlen(s+1),nt=strlen(t+1);
    for(int i=1;i<=ns;i++)cnts[i]=cnts[i-1]+(s[i]=='A'?1:2);
    for(int i=1;i<=nt;i++)cntt[i]=cntt[i-1]+(t[i]=='A'?1:2);
    scanf("%d",&q);
    while(q--){
        int l1,r1,l2,r2;scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        int x=cntt[r2]-cntt[l2-1]-(cnts[r1]-cnts[l1-1]);
        if(x%3==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}