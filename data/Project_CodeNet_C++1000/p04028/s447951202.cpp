#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
//#include<map>
using namespace std;
typedef long long int llint;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define izryt bool
#define fi first
#define se second
#define res resize
const llint mod=1000000007;
const llint gya=500000004;//mod modで2の逆元
const llint big=1e18;
const llint red=0xE869120;
const llint pro=1002001;
int main(void){
	llint gen=1,i,j,N;
	string str;
	vector<llint>dp,ddp;
	cin>>N;
	cin>>str;
	dp.res(N+2);ddp.res(N+2);
	dp[0]=1;
	for(i=0;i<N;i++){
		ddp[0]=dp[0]+dp[1];
		ddp[0]%=mod;
		for(j=1;j<N+1;j++){
			ddp[j]=2*dp[j-1]+dp[j+1];
			ddp[j]%=mod;
		}
		swap(dp,ddp);
	}
	gen=dp[str.size()];
	for(i=0;i<str.size();i++){
		gen*=gya;
		gen%=mod;
	}
	cout<<gen<<endl;
}
