#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5+5;

int N;
int A[MaxN];

bool Check(){
	int i,f=0,cnt=0,g=0;
	for(i=1;i<=N;i++)
		A[i]&1?cnt++:f^=1;
	if(f)
		return true;
	if(cnt>1)
		return false;
	for(i=1;i<=N;i++)
		if(A[i]&1){
			if(A[i]<2)
				return false;
			A[i]--;
		}
	for(i=1;i<=N;i++)
		g=__gcd(g,A[i]);
	for(i=1;i<=N;i++)
		A[i]/=g;
	return Check()^1;
}

int main(){
	int i;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&A[i]);
	puts(Check()?"First":"Second");
	return 0;
}