#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n,a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i)
		if(i+1>a[i+1]){
			int tD=(upper_bound(a+1,a+n+1,i,greater<int>())-a-i-1)&1,tW=(a[i]-i)&1;
			if(tD||tW)cout<<"First\n";
			else cout<<"Second\n";
			return 0;
		}
	return 0;
}
