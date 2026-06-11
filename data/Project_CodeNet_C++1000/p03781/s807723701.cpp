#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int x; cin>>x;
	int ans=0;
	for(int i=1; i<=x; i++){
		ans+=i;
		if(ans>=x) {cout<<i<<endl; return 0;}
	}
}