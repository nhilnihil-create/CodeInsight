#include<stdio.h>
#include<climits>
#define FOR(i,ii,n) for(int i=ii; i<N; i++)
#include <iostream>
#include <cstdlib>

int main(){
	int N;
	scanf("%d", &N);
	long long M[N][N];
	FOR(i,0,N){
		FOR(j,0,N){
			scanf("%lld", &M[i][j]);
		}
	}

	long long sum = 0;
	FOR(i,0,N){
		FOR(j,i+1,N){
			long long min = LLONG_MAX;
			FOR(k,0,N){
				if(i != k && j != k){
					long long tmp = M[i][k] + M[k][j];
					if(min > tmp)
						min = tmp;
				}
			}
			if(M[i][j] < min)
				sum += M[i][j];
			else if(M[i][j] > min){
				printf("-1");
				std::exit(0);
			}
		}
	}
	printf("%lld", sum);
}