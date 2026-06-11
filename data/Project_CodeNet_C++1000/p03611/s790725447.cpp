#include<iostream>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	int n;
	scanf("%d",&n);
	int ai;
	while(n--){
		scanf("%d",&ai);
		a[ai]++;   
		a[ai-1]++;
		a[ai+1]++;
	}
	int max=0;
	for(int i=0;i<N-1;i++){
	if(max<a[i])
		max=a[i];
	}
	printf("%d\n",max);
 
	return 0;
 
}
 