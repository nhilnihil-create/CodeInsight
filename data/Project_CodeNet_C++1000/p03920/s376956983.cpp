#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int x=1;
	while(x*(x+1)/2<=n) x++;
	int s=x*(x+1)/2-n;
	for(int i=1;i<=x;i++){
		if(i==s) continue;
		cout<<i<<endl;
	}
}
