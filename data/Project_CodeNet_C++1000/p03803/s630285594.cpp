#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	if (A == 1) { A = 14; }
	if (B == 1) { B = 14; }

	if (A > B) {
		cout<<"Alice"<<endl;
	}
	else if (A < B) {
		cout << "Bob" << endl;
	}
	else {
		cout << "Draw" << endl;
	}
	
}
