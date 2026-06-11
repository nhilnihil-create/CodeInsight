#include<bits/stdc++.h>
using namespace std;

int A[100003] , N;

int main(){
	scanf("%d" , &N);
	for(int i = 1 ; i <= N ; ++i) scanf("%d" , &A[i]);
	sort(A + 1 , A + N + 1); int pos = 1;long long sum = 0;
	while(pos <= N){
		int p = pos + 1; sum += A[pos];
		while(p <= N && A[p] <= sum * 2) sum += A[p++];
		if(p == N + 1) cout << p - pos;
		pos = p;
	}
	return 0;
}
