#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

long long tmp[100000];
void solve(){
	for(int i=1;i<=100000;i++){
		tmp[i]=(i+1)*i/2;
	}
}

int main(){
	int x,ans;
	cin>>x;
	solve();
	for(int i=1;i<=100000;i++){
		if(tmp[i]>=x){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}