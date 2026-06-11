#include <stdio.h>
#include <algorithm>
using namespace std;

//bool ans[10000000];

int N;
int sumn;
int maxnum;
int sa = -1;
int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		
		sumn += i;
		maxnum = i;
		if (sumn == N){ maxnum = i; break; }
		else if (sumn > N){
			maxnum = i;
			sa = sumn - N;
			break;
		}
	}
	if (N == 1){
		printf("1\n");
	}
	else{
		for (int i = 1; i <= maxnum; i++){
			if (i != sa){
				printf("%d\n", i);
			}
		}
	}
	
	return 0;
}