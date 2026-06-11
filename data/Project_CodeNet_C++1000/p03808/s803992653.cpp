#include <iostream>
#include <vector>
using namespace std;

int main() {
	long N; cin >> N;
	vector<long> a(N);
	long sum=0, dd=((1+N)*N)/2;
	for(int i=0; i<N; ++i){
	    cin >> a[i];
	    sum += a[i];
	}
	if(sum%dd>0){
	    cout << "NO" << endl;
	    return 0;
	}
	sum /= dd;
	long cnt=0;
	for(int i=0; i<N; ++i){
	    if((a[i]-a[(i+1)%N]+sum)%N>0 || a[i]-a[(i+1)%N]+sum<0){
	        cout << "NO" << endl;
	        return 0;
	    }
	    cnt += (a[i]-a[(i+1)%N]+sum)/N;
	}
	if(cnt==sum) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
