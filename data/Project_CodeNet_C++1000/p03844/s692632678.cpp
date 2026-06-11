#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B;
	char op;
	cin >> A >> op >> B;
	if(op == '+'){
		printf("%d\n", A + B);
	}
	else{
		printf("%d\n", A - B);
	}
	return 0;
}