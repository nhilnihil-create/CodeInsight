#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x;
	int m4=0, m2=0, m1=0;
	for (int i=0; i<n; i++){
		cin >> x;
		if (x%4==0) m4++;
		else if (x%2==0) m2++;
		else m1++;
	}
	//cout << m4 << m2 << m1;
	if (m2==0){
		if (m4+1>=m1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else{
		if (m4 >= m1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}