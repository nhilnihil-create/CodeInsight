#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

int N;
int A[SIZE];
int table[SIZE];


int main(){

	scanf("%d",&N);

	for(int i = 1; i < SIZE; i++){

		table[i] = 0;
	}

	for(int i = 0; i < N; i++){

		scanf("%d",&A[i]);
		table[A[i]]++;
	}

	int ans = N;
	int num_2 = 0;

	for(int i = 1; i < SIZE; i++){
		if(table[i] <= 1)continue;

		//table[i] >= 2;
		if(table[i]%2 == 0){

			//2枚にする
			ans -= (table[i]-2);
			num_2++;

		}else{

			//1枚にする
			ans -= (table[i]-1);
		}
	}

	if(num_2%2==0){ //2枚同士のペアを作る

		ans -= num_2;
	}else{ //1枚のカードを1つ犠牲にする必要あり

		ans -= (num_2+1);
	}

	printf("%d\n",ans);

	return 0;
}
