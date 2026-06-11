#include <iostream>
using namespace std;

int main() {
	int A,B,C,D;
	cin>>A>>B>>C>>D;
	int sum=A*B>C*D? A*B:C*D;
	cout << sum << endl;
}