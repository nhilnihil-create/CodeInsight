#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int len=b.length();
	
	for (int i=0; i<len; i++){
		cout<< a[i] << b[i];
	}
    if (a.length()>b.length()) cout << a[len];
	cout << "\n";
}