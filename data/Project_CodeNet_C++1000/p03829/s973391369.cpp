#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long n,a,b; cin>>n>>a>>b;
	long long x[n]; for(int i = 0; i < n; i++) cin>>x[i];
	
	int now = x[0];
	long long ans = 0;
	long long w;
	for(int i = 1; i < n; i++){
		w = (x[i] - x[i-1]) * a;
		if(w < b){
			ans+=w;
		}
		else{
			ans+=b;
		}
	}
	cout<<ans<<endl;
	return 0;
}

