#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

struct Info{
	Info(ll arg_value){
		value = arg_value;
	}
	bool operator<(const struct Info &arg) const{

		return value < arg.value; //降順
	}

	ll value;
};
struct Data{
	Data(ll arg_value){

		value = arg_value;
	}
	bool operator<(const struct Data &arg) const{

		return value > arg.value; //昇順
	}

	ll value;
};


ll N;
ll A[3*SIZE];
ll L[3*SIZE],R[3*SIZE];



int main(){

	scanf("%lld",&N);

	for(ll i = 0; i < 3*N; i++){

		scanf("%lld",&A[i]);
	}


	priority_queue<Data> LQ; //上位N件を持つPQ

	//左の上位N件を求める
	ll sum = 0;
	for(ll i = 0; i < N; i++){

		sum += A[i];
		LQ.push(Data(A[i]));
	}
	L[N-1] = sum;
	//printf("L sum:%lld\n",sum);

	for(ll i = N; i <= 2*N-1; i++){

		if(A[i] > LQ.top().value){

			sum -= LQ.top().value;
			LQ.pop();
			LQ.push(Data(A[i]));
			sum += A[i];
		}
		L[i] = sum;
		//printf("L[%lld]:%lld\n",i,L[i]);
	}

	priority_queue<Info> RQ; //下位N件を持つPQ

	//右の下位N件を求める
	sum = 0;
	for(ll i = 3*N-1; i >= 2*N; i--){

		sum += A[i];
		RQ.push(Info(A[i]));
	}
	R[2*N] = sum;
	//printf("R sum:%lld\n",sum);

	for(ll i = 2*N-1; i >= N; i--){

		if(A[i] < RQ.top().value){
			//printf("A[%lld]:%lld top:%lld\n",i,A[i],RQ.top().value);
			sum -= RQ.top().value;
			RQ.pop();
			RQ.push(Info(Info(A[i])));
			sum += A[i];
			//printf("sum;%lld\n",sum);
		}
		R[i] = sum;
		//printf("R[%lld]:%lld\n",i,R[i]);
	}

	ll ans = -HUGE_NUM;
	for(ll i = N-1; i <= 2*N-1; i++){

		ans = max(ans,L[i]-R[i+1]);
	}

	printf("%lld\n",ans);

	return 0;
}
