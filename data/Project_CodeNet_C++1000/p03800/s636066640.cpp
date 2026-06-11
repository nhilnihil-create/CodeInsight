#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> piipi;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

char s[100005];
int dp[100005];
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
            memset(dp, -1, sizeof(dp));
            dp[n-1] = j;
            dp[0] = k;

            bool ok = 1;
            for(int i=0;i<n;i++){
                if(dp[i] == 0){
                    if(s[i] == 'o'){
                        if(dp[(i+1)%n] == -1) dp[(i+1)%n] = dp[(i-1+n)%n];
                        else if(dp[(i+1)%n] != dp[(i-1+n)%n]) ok = 0;
                    }
                    else{
                        if(dp[(i+1)%n] == -1) dp[(i+1)%n] = 1-dp[(i-1+n)%n];
                        else if(dp[(i+1)%n] != 1-dp[(i-1+n)%n]) ok = 0;
                    }
                }
                else{
                    if(s[i] == 'x'){
                        if(dp[(i+1)%n] == -1) dp[(i+1)%n] = dp[(i-1+n)%n];
                        else if(dp[(i+1)%n] != dp[(i-1+n)%n]) ok = 0;
                    }
                    else{
                        if(dp[(i+1)%n] == -1) dp[(i+1)%n] = 1-dp[(i-1+n)%n];
                        else if(dp[(i+1)%n] != 1-dp[(i-1+n)%n]) ok = 0;
                    }
                }
            }
            if(ok){
                for(int i=0;i<n;i++){
                    if(dp[i] == 0   ) printf("S");
                    else printf("W");
                }
                return 0;
            }
        }
    }
    printf("-1\n");
}