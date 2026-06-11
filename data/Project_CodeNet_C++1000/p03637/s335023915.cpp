#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int N;
	scanf("%d",&N);
	int good=0;
	int bad=0;
	for(int i=0;i<N;i++) {
		int x;
		scanf("%d",&x);
		if(x%4==0) {
			good++;
		}else if(x%2==0){
			bad++;
		}
	}
	if(good*2 + bad >= N || (good*2+1)>=N) puts("Yes");
	else puts("No");
	return 0;
}


