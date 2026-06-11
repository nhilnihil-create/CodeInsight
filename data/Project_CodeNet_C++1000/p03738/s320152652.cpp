#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



char A[105],B[105];

int main(){

	scanf("%s %s",A,B);

	int len_A,len_B;

	for(len_A = 0;A[len_A] != '\0'; len_A++);
	for(len_B = 0;B[len_B] != '\0'; len_B++);

	if(len_A > len_B){

		printf("GREATER\n");

	}else if(len_A < len_B){

		printf("LESS\n");

	}else{

		for(int i = 0; i < len_A; i++){
			if(A[i] != B[i]){
				if(A[i] > B[i]){

					printf("GREATER\n");

				}else{

					printf("LESS\n");
				}
				return 0;
			}
		}

		printf("EQUAL\n");
	}

	return 0;
}
