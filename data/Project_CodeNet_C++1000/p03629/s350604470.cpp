#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAX=200030;
const ll MOD=1000000007;
int N;
char S[MAX];
int dp[MAX],dpn[MAX],nnnn[26],start;
main(){
    scanf(" %s",S);
    N=strlen(S);
    for(int i=0;i<26;i++) nnnn[i]=N+i;
    for(int i=N-1;i>=0;i--) {
        dp[i]=MAX;
        for(int j=0;j<26;j++) if(dp[i]>dp[nnnn[j]]) dpn[i]=nnnn[j], dp[i]=dp[nnnn[j]];
        dp[i]++;
        nnnn[S[i]-'a']=i;
    }
    int t=MAX;
    for(int i=0;i<26;i++){
        if(t>dp[nnnn[i]]) start=nnnn[i],t=dp[nnnn[i]];
    }
    while(start<N){
        printf("%c",S[start]);
        start=dpn[start];
    }
    printf("%c\n",start-N+'a');

    return 0;
}
