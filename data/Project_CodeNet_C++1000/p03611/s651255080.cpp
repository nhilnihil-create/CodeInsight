#include <iostream>
#include <algorithm>
using namespace std;
int cnt[100005];
int main(){
	int n;
	cin >> n;
	int ai;
	while(n--){
		scanf("%d",&ai);
		cnt[ai-1]++;
		cnt[ai]++;
		cnt[ai+1]++;
	}
	int max=0;
	for(int i=0;i<100005;i++){
		if(cnt[i]>max) max=cnt[i];
	}
	printf("%d\n",max);
	return 0;
}
