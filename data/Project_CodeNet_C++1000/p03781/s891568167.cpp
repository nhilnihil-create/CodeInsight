#include <bits/stdc++.h>//所有库
using namespace std;

int main(){
	int n;
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++){
		ans+=i;
		if (ans>=n) {cout<<i;break;}
		}
	return 0; 
}