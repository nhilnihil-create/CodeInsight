#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	int n,sum=0;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
		sum+=v[i];
	}
	sum/=n;
	int ans=0;
	for(int i=0;i<n;++i){
		ans+=(v[i]-sum)*(v[i]-sum);
	}
	int sol=0;
	++sum;
	for(int i=0;i<n;++i){
		sol+=(v[i]-sum)*(v[i]-sum);
	}
	cout<<min(ans,sol)<<"\n";
	return 0;
}
