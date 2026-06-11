#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<ll> a(N), sum_raw(N), sum_opt(N);
	vector<int> minus;
	cin >> a[0];
	sum_raw[0]=a[0];
	sum_opt[0]=a[0];
	for(int i=1; i<N; ++i){
	    char op;
	    cin >> op >> a[i];
	    if(op=='+') sum_raw[i]=sum_raw[i-1]+a[i];
	    else{
	        sum_raw[i]=sum_raw[i-1]-a[i];
	        minus.push_back(i);
	    }
	    sum_opt[i]=sum_opt[i-1]+a[i];
	}
	ll ans=sum_raw[N-1];
	for(int i=0; i+1<minus.size(); ++i){
	    ans=max(ans, sum_raw[minus[i]]*2-sum_raw[minus[i+1]-1]+sum_opt[N-1]-sum_opt[minus[i+1]-1]);
	}
	cout << ans << endl;
	return 0;
}
