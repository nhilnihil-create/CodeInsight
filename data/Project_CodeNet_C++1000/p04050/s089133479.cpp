#include<bits/stdc++.h>
using namespace std;

int N,M,K;
int A[105];

vector<int> B;

int main(){
	int i,cnt;
	scanf("%d%d",&N,&M);
	for(i=1;i<=M;i++)
		scanf("%d",&A[i]);
	if(M<2){
		B.push_back(N-1);
		B.push_back(1);
	}
	else{
		for(i=1;i<=M;i++)
			cnt+=A[i]&1;
		if(cnt>2){
			puts("Impossible");
			return 0;
		}
		for(i=1;i<=M;i++)
			if(A[i]&1)
				swap(A[A[1]&1?M:1],A[i]);
		for(i=1;i<=M;i++)
			B.push_back(A[i]+(i<2?-1:(i==M)));
	}
	for(i=1;i<=M;i++)
		printf("%d ",A[i]);
	puts("");
	printf("%d\n",B.size()-!B[0]);
	for(i=!B[0];i<B.size();i++)
		printf("%d ",B[i]);
	return 0;
}