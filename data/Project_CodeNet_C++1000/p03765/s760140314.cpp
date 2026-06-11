#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<bitset>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
const int MAXN=1e5+11;
char S[MAXN],T[MAXN];
int N,M,SS[MAXN][2],ST[MAXN][2],Q;
int main(){
    scanf("%s%s",S+1,T+1);N=strlen(S+1),M=strlen(T+1);
    for(int i=1;i<=N;i++) SS[i][0]=SS[i-1][0]+(S[i]=='A'),SS[i][1]=SS[i-1][1]+(S[i]=='B');
    for(int i=1;i<=M;i++) ST[i][0]=ST[i-1][0]+(T[i]=='A'),ST[i][1]=ST[i-1][1]+(T[i]=='B');
    Q=read();
    while(Q--){
        int l1=read(),r1=read(),l2=read(),r2=read();
        int sa=SS[r1][0]-SS[l1-1][0],sb=r1-l1+1-sa;
        int ta=ST[r2][0]-ST[l2-1][0],tb=r2-l2+1-ta;
        int Sa=sa+2*sb,St=ta+2*tb;
        if((Sa-St)%3) printf("NO\n");
        else printf("YES\n");
    }return 0;
}/*
  AAAAABBBBAAABBBBAAAA
  BBBBAAABBBBBBAAAAABB
  1
  2 15 2 13
  */
