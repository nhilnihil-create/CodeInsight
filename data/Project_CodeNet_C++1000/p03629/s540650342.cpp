#include<bits/stdc++.h>
using namespace std;
#define _   int v, int tl, int tr, int l, int r
#define tm  (tl + tr >> 1)
#define sol v+v, tl, tm, l, r
#define sag v+v+1, tm+1, tr, l, r
#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;    

int dp[N],nex[N],yaz[N],L[32];
char s[N];

signed main(){  
    scanf(" %s", s+1);
	int n = strlen(s+1);
	for(int i=0; i<26; i++) L[i] = n+1;

    dp[n+1] = 0;
    for(int i=n; i>=0; i--){
        dp[i] = n;
        for(int j=0; j<26; j++)
        	if(dp[i] > dp[ L[j] ] + 1){
                dp[i] = dp[ L[j] ] + 1;
                nex[i] = L[j];
                yaz[i] = j;
            }
        L[ s[i]-'a' ] = i;
    }
    
   	for(int i=0; i<=n; i = nex[i])
        printf("%c", yaz[i]+'a');
    	
    return 0;
}