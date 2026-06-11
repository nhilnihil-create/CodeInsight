#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> l;
priority_queue<int> r;

int main() {
	int N, A[300010]; cin >> N;
	long L=0, R=0;
	for(int i=0; i<3*N; ++i){
	    cin >> A[i];
	    if(i<N){
	        L += A[i];
	        l.push(A[i]);
	    }
	    if(i>=N*2){
	        R += A[i];
	        r.push(A[i]);
	    }
	}
	long P[100010], Q[100010];
	P[0]=L, Q[N]=R;
	for(int i=0; i<N; ++i){
	    if(l.top()<A[N+i]){
	        P[i+1]=P[i]-l.top()+A[N+i];
	        l.pop();
	        l.push(A[N+i]);
	    }
	    else P[i+1]=P[i];
	    if(r.top()>A[N*2-i-1]){
	        Q[N-i-1]=Q[N-i]-r.top()+A[N*2-i-1];
	        r.pop();
	        r.push(A[N*2-i-1]);
	    }
	    else Q[N-i-1]=Q[N-i];
	}
	long ans=P[0]-Q[0];
	for(int i=1; i<=N; ++i) ans=max(ans, P[i]-Q[i]);
	cout << ans << endl;
	return 0;
}
