#include <iostream>

using namespace std;

int main(){
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	if(max(A, C) < min(B, D)){
		cout << min(B, D) - max(A, C) << endl;
	}
	if(max(A, C) >= min(B, D)){
		cout << 0 << endl;
	}

	return 0;
}

