#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



char S[205];

int main(){

	scanf("%s",S);

	int LEN;
	for(LEN = 0; S[LEN] != '\0'; LEN++);


	int ans = 0;

	for(int tail = 1; tail < LEN-1; tail += 2){
		bool FLG = true;

		int len = (tail+1)/2;

		for(int i = 0; i < len; i++){
			if(S[i] != S[len+i]){
				FLG = false;
				break;
			}
		}
		if(!FLG)continue;
		ans = (tail+1);
	}

	printf("%d\n",ans);

	return 0;
}
