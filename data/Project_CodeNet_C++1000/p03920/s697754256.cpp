#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,a,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		sum+=i;
		if(sum>=n) break;
	}
	a=sum-n;
	for(int i=1;i<=n;i++){
		sum-=i;
		if(a==i) continue;
		cout << i << endl;
		if(sum==0) break;
	}
	
	return 0;
}
