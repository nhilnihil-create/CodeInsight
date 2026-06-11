#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


enum Type{
	None,
	TATE,
	YOKO,
};

int N;
char table[2][55];

int main(){

	scanf("%d",&N);

	for(int row = 0; row < 2; row++){

		scanf("%s",table[row]);
	}

	ll ans;
	int loc;
	Type pre;

	if(table[0][0] == table[1][0]){

		pre = TATE;
		ans = 3;
		loc = 1;

	}else{

		pre = YOKO;
		ans = 6;
		loc = 2;
	}

	while(loc <= N-1){

		if(table[0][loc] == table[1][loc]){

			if(pre == TATE){

				ans *= 2;
				ans %= MOD;
			}else{

				ans *= 1;
			}

			pre = TATE;
			loc++;

		}else{

			if(pre == TATE){

				ans *= 2;
				ans %= MOD;
			}else{

				ans *= 3;
				ans %= MOD;
			}

			pre = YOKO;
			loc += 2;
		}
	}

	printf("%lld\n",ans);

	return 0;
}
