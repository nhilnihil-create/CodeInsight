#include <iostream>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef long long LL;
const int MAXN = 2e5+17;
const int MOD = 1e9+7;
int dp[MAXN],nxt[MAXN][26+3],ocr[26+3];
int main(int argc ,char const *argv[])
{
	#ifdef noob
	freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
	#endif	
	string str;
	cin>>str;
	int n = str.length();
	for (int i = 0; i < 26; ++i)
	{
		ocr[i] = n;
	}
	for (int i = n-1; i > -1; --i)
	{
		ocr[str[i]-'a'] = i;
		for (int j = 0; j < 26; ++j)
		{
			nxt[i][j] = ocr[j];
		}
		dp[i] = MOD;
	}
	dp[n] = 1;
	for (int i = n-1; i > -1; --i)
		for (int j = 0; j < 26; ++j)
			dp[i] = min(dp[i],dp[nxt[i][j]+1]+1);
	for (int i = 0; dp[0]; --dp[0])
	{
		for (int j = 0; j < 26; ++j)
		{
			if(dp[i]==dp[nxt[i][j]+1]+1)
			{
				printf("%c",j+'a');
				i = nxt[i][j]+1;
				break;
			}
		}
	}
	return 0;	
}