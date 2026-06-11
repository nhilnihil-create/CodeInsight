#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int N;
	cin >> N;
	int ans=0;
	for(int i=1;i<=N;i++) {
		if(i&&(!(i&(i-1)))) {
			ans=i;
		}
	}
	printf("%d",ans);
	return 0;
}


