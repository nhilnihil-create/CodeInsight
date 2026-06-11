#include <bits/stdc++.h>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef long long LL;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int dp[MAXN],ix[26+3][MAXN],ocr[26+3];
int main(int argc ,char const *argv[])
{
  #ifdef noob
  freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
  #endif  
  string str;
  cin>>str;
  int n = str.size();
  for (int i = 0; i < 26; ++i)
  {
    ocr[i] = n;
  }
  for (int i = n-1; i >=0; i--)
  {
    ocr[str[i]-'a'] = i;
    for (int j = 0; j < 26; ++j)
    {
      ix[j][i] = ocr[j];
    }
    dp[i] = MOD;
  }


  dp[n] = 1;
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
