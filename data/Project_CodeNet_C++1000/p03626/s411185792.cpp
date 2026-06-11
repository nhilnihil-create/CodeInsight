#include<bits/stdc++.h>
using namespace std;
int n;
string s[2];
long long dp[60][3][3];
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
				dp[2][i][j]=1LL;
			}
		}
	}
	else{
		for(int i=0;i<3;i++){
			dp[1][i][i]=1LL;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(s[0][i]==s[1][i]){
					for(int z=0;z<3;z++)if(z!=j&&z!=k){
						dp[i+1][z][z]+=dp[i][j][k];
					}
				}
				else{
					for(int z=0;z<3;z++)if(z!=j){
						for(int c=0;c<3;c++)if(c!=k&&c!=z){
							dp[i+2][z][c]+=dp[i][j][k];
						}
					}
				}
			}
		}
	} 
	long long res=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			res+=dp[n][i][j];
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