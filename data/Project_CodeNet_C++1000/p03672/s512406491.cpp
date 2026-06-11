#include <iostream>
using namespace std;

int main() {
	string ss;
	cin >> ss;
	int len = ss.length();
	int mid = len/2;
	if (len%2==0){
		mid = (len-2)/2;
	}
	
	while (ss.substr(0,mid)!=ss.substr(mid, mid)){
		mid--;
	}
	cout << mid*2 << endl;
	
	
	
}
