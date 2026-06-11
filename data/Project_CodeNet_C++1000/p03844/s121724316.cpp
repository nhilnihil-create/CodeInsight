#include <iostream>
using namespace std;
int main() {
	int A , B , Ans;
	char op;
	
	cin >> A >> op >> B;
	
	if (op == '+')
	Ans = A + B;
	
	if (op == '-')
	Ans = A - B;
	
	cout << Ans << endl;
}