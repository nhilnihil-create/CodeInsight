#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+15;
const int M = 26;
int Next[N][M];
int dp[N],go[N],ggo[N];

void solve(){
   string s;
   cin>>s;
   int n = s.size();
   for(int j = 0;j<M;++j) {
      Next[n+1][j] = n+1;
   }
   for(int i=n;i>=0;--i){
      for(int j = 0;j<M;++j){
         Next[i][j] = Next[i+1][j];
      }
      if(i+1<=n){
         int g = s[i] - 'a';
         Next[i][g] = i+1; 
      }
   }
   for(int i=n;i>=0;--i) {
      dp[i] = 1e9;
      for(int j = 0;j<M;++j){
         int cur = Next[i][j];
         if(cur>n+1){
            dp[i] = 1;
            go[i] = j;
            ggo[i] = cur;
         } else {
            if(dp[i]> dp[cur]+1){
               dp[i] = dp[cur]+1;
               go[i] = j;
               ggo[i] = cur;
            }
         }
      }
   }
   int cur = 0;
   while(cur<=n) {
      putchar(char('a'+go[cur]));
      cur = ggo[cur];
   }
   putchar('\n');
}


int main() {
   //freopen("input.txt","r",stdin);
   solve();
}