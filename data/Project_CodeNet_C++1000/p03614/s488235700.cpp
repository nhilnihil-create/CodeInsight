#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		A[i]--;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		if(A[i]==i){
			int j = i;
			while(j<n && A[j]==j)
				j++;
			j--;
			ans += (j-i+2)/2;
			i = j;	
		}
	}
	printf("%d\n",ans);
}