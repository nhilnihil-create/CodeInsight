#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll N,W;
ll INDEX[4],LAST;
ll table[4][105];
ll base_w;
vector<ll> V[4];

ll ans;

void recursive(ll index,ll sum,ll value){

	if(index == 4){

		//printf("sum:%lld value:%lld\n",sum,value);
		ans = max(ans,value);
		return;
	}

	//足さない
	recursive(index+1,sum,value);


	if(index == LAST){

		for(ll i = INDEX[index]-1; i >= 0; i--){
			if(sum+(base_w+index)*(i+1) > W)continue;

			ll add = table[index][i+1];
			recursive(index+1, sum+(base_w+index)*(i+1),value+add);
			return;
		}

	}else{

		for(ll i = 0; i < INDEX[index] && sum+(base_w+index)*(i+1) <= W; i++){

			ll add = table[index][i+1];
			recursive(index+1, sum+(base_w+index)*(i+1),value+add);
		}
	}
}


int main(){

	scanf("%lld %lld",&N,&W);

	for(int i = 0; i < 4; i++){

		INDEX[i] = 0;
	}

	ll tmp_w,tmp_v;

	scanf("%lld %lld",&base_w,&tmp_v);

	V[0].push_back(tmp_v);
	INDEX[0] = 1;
	LAST = 0;

	for(ll i = 1; i < N; i++){

		scanf("%lld %lld",&tmp_w,&tmp_v);
		V[tmp_w-base_w].push_back(tmp_v);

		INDEX[tmp_w-base_w]++;
		LAST = max(LAST,tmp_w-base_w);
	}

	for(int i = 0; i < 4; i++){
		if(V[i].size() == 0)continue;

		sort(V[i].rbegin(),V[i].rend());

		table[i][0] = 0;

		for(int k = 0; k < V[i].size(); k++){

			table[i][k+1] = V[i][k];
			table[i][k+1] += table[i][k];
		}
	}

	ans = -1;

	recursive(0,0,0);

	printf("%lld\n",ans);

	return 0;
}
