#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 0, s = 0, n;
	scanf("%d",&n);
	while(1){
		++s;
		t+=s;
		if(t >= n){
			t -= n;
			break;
		}
	}
	for(int i=1; i<=s; i++)if(i!=t)
		printf("%d\n",i);
	return 0;
}
