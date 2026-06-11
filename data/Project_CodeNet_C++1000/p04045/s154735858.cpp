#include <cstdio>
using namespace std;

bool D[10];
bool isValid(int x){
	for(int d=x;d>0;d/=10){
		if(D[d%10]) return true;
	}
	return false;
}

int main(void){
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=0;i<K;i++){
		int d;
		scanf("%d",&d);
		D[d]=true;
	}
	int i;
	for(i=N;isValid(i);i++);
	printf("%d\n",i);
}