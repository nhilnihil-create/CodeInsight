#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int a[200010];
	long S=0;
	for(int i=0; i<N; ++i){
	    cin >> a[i];
	    S += a[i];
	}
	long M=abs(a[0]-(S-a[0]));
	long P=a[0];
	for(int i=1; i<N-1; ++i){
	    P += a[i];
	    M=min(M, abs(P-(S-P)));
	}
	cout << M << endl;
	return 0;
}
