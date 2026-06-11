#include<bits/stdc++.h>
using namespace std;
long long dp[60][3][3];
int n;
string s[2];
const long long MOD=1000000007LL;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>s[0]>>s[1];
	if(s[0][0]!=s[1][0]){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)if(i!=j){
				dp[0][i][j]=1LL;
			}
		}
	}
	else{
		for(int i=0;i<3;i++){
			dp[0][i][i]=1LL;
		}
	}
	long long res=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(s[0][i]==s[0][i+1])
					dp[i+1][j][k]+=dp[i][j][k];
				else if(s[0][i+1]==s[1][i+1]){
					for(int l=0;l<3;l++)if(l!=j&&l!=k){
						dp[i+1][l][l]+=dp[i][j][k];
					}
				}
				else{
					for(int l=0;l<3;l++)if(l!=j){
						for(int m=0;m<3;m++)if(m!=k&&l!=m){
							dp[i+1][l][m]+=dp[i][j][k];
						}
					}
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			res+=dp[n-1][i][j];
		}
	}
	cout<<res%MOD<<endl;
	return 0;
}
/*
52
RvvttdWIyyPPQFFZZssffEEkkaSSDKqcibbeYrhAljCCGGJppHHn
RLLwwdWIxxNNQUUXXVVMMooBBaggDKqcimmeYrhAljOOTTJuuzzn
*/