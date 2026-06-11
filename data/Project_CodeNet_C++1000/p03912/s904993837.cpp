#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N, M; cin >> N >> M;
	vector<int> X(100001, 0), sum(M, 0), cand(M, 0);
	for(int i=0; i<N; ++i){
	    int a; cin >> a;
	    ++X[a];
	    ++sum[a%M];
	}
	for(int i=0; i<100001; ++i) cand[i%M] += X[i]/2;
	int ans=sum[0]/2;
	for(int i=1; i*2<=M; ++i){
	    if(i*2==M){
	        ans += sum[i]/2;
	        break;
	    }
	    int mn=(sum[i]<sum[M-i] ? i : M-i);
	    ans += sum[mn];
	    ans += min((sum[M-mn]-sum[mn])/2, cand[M-mn]);
	}
	cout << ans << endl;
	return 0;
}
