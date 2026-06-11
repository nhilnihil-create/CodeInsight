#include <bits/stdc++.h>

using namespace std;

const int INF=1e9+7;
string A;
int dp[200005];
int ix[30][200005];
int nx[30];

int main() {


cin>>A;
int n=A.size();

for(int j=0; j<26; j++){
    nx[j]=n;
}

for(int i=n-1; i>=0; --i){
  nx[A[i]-'a']=i;
  for(int j=0; j<26; j++){
    ix[j][i]=nx[j];
  }
  dp[i]=INF;
}

dp[n]=1;
for (int i = n-1; i > -1; --i)
  for (int j = 0; j < 26; ++j)
    dp[i] = min(dp[i],dp[ix[j][i]+1]+1);

  for (int i = 0; dp[0]; --dp[0])
  {
    for (int j = 0; j < 26; ++j)
    {
      if(dp[i]==dp[ix[j][i]+1]+1)
      {
        printf("%c",j+'a');
        i = ix[j][i]+1;
        break;
      }
    }
  }

  cout<<endl;

  return 0;
}
