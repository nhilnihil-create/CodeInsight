#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main(){
	
	int N,K;
	cin>>N>>K;
	
	vector<long long> a(N);
	rep(i,N)cin>>a[i];
	
	long long ans = Inf;
	rep(i,(1<<N)){
		vector<long long> b = a;
		int c = 0;
		long long maxi = 0;
		long long sum =0LL;
		rep(j,N){
			if((i>>j)&1){
				c++;
				if(maxi>=b[j]){
					sum += maxi+1-b[j];
					b[j] = maxi+1;
				}
				
			}
			maxi = max(maxi,b[j]);
		}
		if(c>=K)ans = min(ans,sum);
	}
	
	cout<<ans<<endl;
	
    return 0;
}

