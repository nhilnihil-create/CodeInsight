#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int N;
int table[8];


int main(){

	for(int i = 0; i < 8; i++){

		table[i] = 0;
	}

	int tmp;
	int add = 0;

	scanf("%d",&N);

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		if(tmp >= 3200){
			add++;
			continue;
		}

		table[tmp/400]++;
	}

	int count = 0;
	for(int i = 0; i < 8; i++){
		if(table[i] > 0){

			count++;
		}
	}


	printf("%d %d\n",max(1,count),count+add);

	return 0;
}
