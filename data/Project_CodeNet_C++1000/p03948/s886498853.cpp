#include <iostream>
using namespace std;

int main() {
	int N;
	long T, mn=1e10, MaxAbs=0, num=0;
	cin >> N >> T;
	for(int i=0; i<N; ++i){
	    long A; cin >> A;
	    if(mn>A) mn=A;
	    if(A-mn>MaxAbs){
	        MaxAbs=A-mn;
	        num=1;
	    }
	    else if(A-mn==MaxAbs) ++num;
	}
	cout << num << endl;
	return 0;
}

