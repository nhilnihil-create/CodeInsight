#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 600005

int N;
int table[SIZE];
int BASE = 300000;


int main(){

	int head = BASE,tail = BASE;

	scanf("%d",&N);

	int tmp;

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);

		if(i%2 == 0){

			table[tail++] = tmp;
		}else{

			table[--head] = tmp;
		}
	}
	if(N == 1){
		printf("%d\n",tmp);
		return 0;
	}

	if(N%2 == 0){
		printf("%d",table[head]);

		for(int i = head+1; i < tail; i++){

			printf(" %d",table[i]);
		}

	}else{
		printf("%d",table[--tail]);

		for(int i = tail-1; i >= head; i--){

			printf(" %d",table[i]);
		}
	}

	printf("\n");

	return 0;
}
