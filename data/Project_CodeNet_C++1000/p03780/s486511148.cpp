#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 5005

ll N,K;
ll A[SIZE];
int dp[SIZE][SIZE],dp2[SIZE][SIZE];

int main(){

	scanf("%lld %lld",&N,&K);

	ll sum = 0;
	for(int i = 0; i < N; i++){

		scanf("%lld",&A[i]);
		sum += A[i];
	}

	if(sum < K){

		printf("%lld\n",N);
		return 0;
	}

	vector<ll> L,R;

	for(int i = 0; i < N; i++){
		if(A[i] >= K)continue;

		L.push_back(A[i]);
		R.push_back(A[i]);
	}

	sort(L.begin(),L.end());
	sort(R.rbegin(),R.rend());

	for(ll i = 0; i <= L.size(); i++){
		for(ll a = 0; a <= K-1; a++){

			dp[i][a] = 0;
			dp2[i][a] = 0;
		}
	}

	dp[0][0] = 1;
	for(ll i = 0; i < L.size(); i++){
		//足さない
		for(ll a = 0; a <= K-1; a++){

			dp[i+1][a] = dp[i][a];
		}
		//足す
		for(ll a = 0; a+L[i] <= K-1; a++){
			if(dp[i][a] == 0)continue;

			dp[i+1][a+L[i]] = 1;
		}
	}
	/*for(ll i = 1; i <= 3; i++){
		printf("i:%lld\n",i);
		for(int a = 0; a <= 8; a++){
				if(dp[i][a] == 1){

					printf("%dが作れる\n",a);
				}
			}
		}*/

	//累積和にする
	for(ll i = 0; i <= L.size(); i++){
		for(ll a = 1; a <= K-1; a++){
			dp[i][a] += dp[i][a-1];
		}
	}




	dp2[0][0] = 1;
	for(ll i = 0; i < R.size(); i++){
		//足さない
		for(ll a = 0; a <= K-1; a++){

			dp2[i+1][a] = dp2[i][a];
		}
		//足す
		for(ll a = 0; a+R[i] <= K-1; a++){
			if(dp2[i][a] == 0)continue;

			dp2[i+1][a+R[i]] = 1;
		}
	}
	/*printf("dp2\n");
	for(ll i = 1; i <= 3; i++){
			printf("i:%lld\n",i);
			for(int a = 0; a <= 8; a++){
					if(dp2[i][a] == 1){

						printf("%dが作れる\n",a);
					}
				}
			}*/
	//累積和にする
	for(ll i = 0; i <= R.size(); i++){
		for(ll a = 1; a <= K-1; a++){
			dp2[i][a] += dp2[i][a-1];
		}
	}


	int ans = 0;
	for(ll i = 0; i < L.size(); i++){

		bool FLG = false;
		//printf("L[%lld]:%lld\n",i,L[i]);

		for(ll a = 0; a <= K-1; a++){
			if(a == 0 || (a > 0 && dp[i][a]-dp[i][a-1] == 1)){

				ll left = max(0LL,(K-L[i])-a);
				ll right = (K-1)-a;

				//printf("a:%lld left:%lld right:%lld\n",a,left,right);

				ll tmp;

				if(left == 0){

					tmp = dp2[R.size()-(i+1)][right];

				}else{

					tmp = dp2[R.size()-(i+1)][right]-dp2[R.size()-(i+1)][left-1];
				}
				if(tmp > 0){
					FLG = true;
					break;
				}
			}
		}
		if(!FLG){ //「L[i]が無ければ良い集合にならない集合」がない

			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
