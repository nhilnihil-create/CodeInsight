#include <iostream>
using namespace std;

int main() {
	int N;
	long A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	if(abs(B-A)>D*(N-1)){
	    cout << "NO" << endl;
	    return 0;
	}
	long mx=min(C+D, 1+(D-C)*(N-1)), sa=A+D*(N-1)-B;
	cout << (sa%(C+D)<mx ? "YES" : "NO") << endl;
	return 0;
}
