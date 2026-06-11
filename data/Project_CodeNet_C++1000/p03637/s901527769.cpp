#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int N;
	scanf("%d",&N);

	int tmp;
	int num_2 = 0,num_4 = 0,num_odd = 0;

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		if(tmp%2 == 0){
			if(tmp%4 == 0){

				num_4++;
			}else{

				num_2++;
			}
		}else{

			num_odd++;
		}
	}


	if(num_2 == 0){

		if(num_4 >= num_odd-1){

			printf("Yes\n");

		}else{

			printf("No\n");
		}

	}else{ //num_2 > 0

		//2,2,2,,4,3,4,3,..

		if(num_odd == 0){

			printf("Yes\n");

		}else{

			if(num_4 >= num_odd){

				printf("Yes\n");
			}else{

				printf("No\n");
			}
		}
	}

	return 0;
}
