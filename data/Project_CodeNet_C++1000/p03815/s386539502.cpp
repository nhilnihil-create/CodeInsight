#include <iostream>
using namespace std;

int main() {
	long long N;
	cin>>N;
	int r = N%11;
	long long count = N/11*2;
	if (r==0){
		cout << count << endl;
	}
	else if (r<=6){
		cout << count+1 << endl;
	}
	else{
		cout << count+2 << endl;
	}
}
