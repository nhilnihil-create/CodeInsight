#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 405

int N,MA,MB;
int dp[2][405][405];

int main(){

	scanf("%d %d %d",&N,&MA,&MB);

	int CURRENT = 0,NEXT = 1;

	for(int i = 0; i < 2; i++){
		for(int k = 0; k < SIZE; k++){
			for(int p = 0; p < SIZE; p++){

				dp[i][k][p] = BIG_NUM;
			}
		}
	}

	//dp[current,next][aのsum][bのsum] = 最小コスト
	dp[CURRENT][0][0] = 0;

	int a,b,c;

	for(int i = 0; i < N; i++){

		scanf("%d %d %d",&a,&b,&c);

		//商品iを買わない場合
		for(int k = 0; k < SIZE; k++){
			for(int p = 0; p < SIZE; p++){

				dp[NEXT][k][p] = min(dp[NEXT][k][p],dp[CURRENT][k][p]);
			}
		}

		//商品iを買う場合
		for(int k = 0; k+a < SIZE; k++){
			for(int p = 0; p+b < SIZE; p++){
				if(dp[CURRENT][k][p] == BIG_NUM)continue;

				dp[NEXT][k+a][p+b] = min(dp[NEXT][k+a][p+b],dp[CURRENT][k][p]+c);
			}
		}
		swap(CURRENT,NEXT);
	}

	int ans = BIG_NUM;

	int A = MA,B = MB;

	while(A < SIZE && B < SIZE){

		ans = min(ans,dp[CURRENT][A][B]);

		A += MA;
		B += MB;
	}

	if(ans == BIG_NUM){

		printf("-1\n");

	}else{

		printf("%d\n",ans);
	}

	return 0;
}
