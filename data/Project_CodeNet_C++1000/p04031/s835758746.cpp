#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int N;
int calc(int x){
	int ret=0;
	for(int i=0;i<N;i++) ret+=(A[i]-x)*(A[i]-x);
	return ret;
}

int main(void){
	int ans=999999999;
	scanf("%d",&N);
	A.resize(N);
	for(int i=0;i<N;i++) scanf("%d",&A[i]);
	for(int i=-100;i<=100;i++) ans=min(ans,calc(i));
	printf("%d\n",ans);
}