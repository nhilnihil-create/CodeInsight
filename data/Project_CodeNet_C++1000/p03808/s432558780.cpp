#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<ll, int> P;
#define MOD (1000000007ll)
#define l_ength size
#define EPS (1e-10)

int main(void){
	ll n,i,a[123456],sum=0ll,d;
	bool flag = true;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	if( sum % ((n*(n+1))/2) ){
		cout << "NO" << endl;
		return 0;
	}
	d = sum / ((n*(n+1))/2); sum = 0ll;
	a[n] = a[0];
	for(i=0; i<n; ++i){
		if((a[i] - a[i+1] + d) < 0 || (a[i] - a[i+1] + d) % n){
			cout << "NO" << endl;
			return 0;
		}else{
			sum += ((a[i] - a[i+1] + d) / n);
		}
	}
	if(flag && sum == d){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
