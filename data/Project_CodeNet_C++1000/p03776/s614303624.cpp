#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



struct Info{
	Info(ll arg_sum,ll arg_num){
		sum = arg_sum;
		num = arg_num;
	}
	bool operator<(const struct Info &arg) const{

		return sum*arg.num > arg.sum*num;
	}

	ll sum,num;
};


ll N,A,B;
ll value[55];
ll dp[55],num[55];


int main(){

	scanf("%lld %lld %lld",&N,&A,&B);

	for(ll i = 0; i < N; i++){

		scanf("%lld",&value[i]);
	}

	if(N == 1){

		printf("%.10lf\n",value[0]);
		printf("1\n");
		return 0;
	}

	//dp[数字の使用個数] = 最大値
	for(ll i = 0; i <= N; i++){
		dp[i] = 0;
	}
	for(ll i = 0; i <= N; i++){

		num[i] = 0;
	}

	num[0] = 1;

	for(ll i = 0; i < N; i++){
		for(ll k = i; k >= 0; k--){
			if(num[k] == 0)continue;

			ll tmp = dp[k]+value[i];

			if(tmp > dp[k+1]){

				dp[k+1] = tmp;
				num[k+1] = num[k];

			}else if(tmp == dp[k+1]){

				num[k+1] += num[k];
			}
		}
	}

	vector<Info> V;
	for(ll i = A; i <= B; i++){

		V.push_back(Info(dp[i],i));
	}
	sort(V.begin(),V.end());

	ll ans = num[V[0].num];

	for(ll i = 1; i < V.size(); i++){

		if(V[i-1].sum*V[i].num == V[i].sum*V[i-1].num){

			ans += num[V[i].num];

		}else{

			break;
		}
	}

	printf("%.10lf\n",(double)V[0].sum/(double)V[0].num);
	printf("%lld\n",ans);

	return 0;
}
