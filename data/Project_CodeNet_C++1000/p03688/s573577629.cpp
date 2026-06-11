#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
int li[N+5];

int main(){
	scanf("%d",&n);
	int mini = N+5;
	int maksi = -1;
	for(int i=1;i<=n;i++){
		scanf("%d",&li[i]);
		mini = min(mini,li[i]);
		maksi = max(maksi,li[i]);
	}
	if(maksi - mini > 1){
		printf("No\n");
		return 0;
	}
	if(maksi != mini){
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(li[i] == mini) cnt++;
		}
		int sisa = n-cnt;
		int butuh = maksi - cnt;
		if(n-cnt >= 2*butuh && butuh > 0){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	} else {
		if(maksi == n-1){
			printf("Yes\n");
		} else {
			if(n >= 2*maksi){
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	return 0;
}