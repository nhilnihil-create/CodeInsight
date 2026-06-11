#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	vector<int> hoge(n);
	for(int i=0;i<n;i++) cin>>hoge.at(i);
	sort(hoge.begin(),hoge.end());

	long long ans=inf;

	for(int a=hoge.at(0);a<=hoge.at(n-1);a++){
		long long pre=0;
		for(auto b:hoge){
			pre+=pow(a-b,2);
		}
		ans=min(ans,pre);
	}

	cout<<ans<<endl;

	return 0;
}
