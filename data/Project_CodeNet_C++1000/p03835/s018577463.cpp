#include <bits/stdc++.h>
using namespace std;

int main(){
	int s,k;cin>>k>>s;
	int cnt=0;
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			if(s-i-j<=k&&s-i-j>=0){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
