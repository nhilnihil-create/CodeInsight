#include<bits/stdc++.h>
using namespace std;
int A,B,C;
int sum_7,sum_5;
int main(){
	scanf("%d%d%d",&A,&B,&C);
	if(A==5) sum_5++;
	if(B==5) sum_5++;
	if(C==5) sum_5++;
	if(A==7) sum_7++;
	if(B==7) sum_7++;
	if(C==7) sum_7++;
	if(sum_5==2&&sum_7==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}