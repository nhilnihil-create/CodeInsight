#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	long long n;
	cin>>n;
	vector<long long> fact(n+1,0);
	long long ans=1;

	for(long long i=2;i<=n;i++){
		long long I=i;
		for(long long j=2;j<=I;j++){
			long long cnt=0;

			while(I%j==0){
				cnt++;
				I/=j;
			}

			fact.at(j)+=cnt;
		}
	}

	for(auto a:fact){
		ans*=a+1;
		ans%=1000000007;
	}

	cout<<ans<<endl;

	return 0;
}
