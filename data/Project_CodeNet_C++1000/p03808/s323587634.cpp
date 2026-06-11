#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	scanf("%lld",&n);
	long long arr[n+1],ops=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);ops+=arr[i];
	}
	arr[n]=arr[0];
	if(ops%(n*(n+1)/2)!=0){printf("NO");return 0;}
	ops/=(n*(n+1)/2);
	for(int i=0;i<n;i++){
		if((ops+arr[i]-arr[i+1])%n==0&&ops+arr[i]-arr[i+1]>=0){
		}else{
			printf("NO");return 0;
		}
	}
	printf("YES");
}
