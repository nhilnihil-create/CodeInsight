#include <iostream>

using namespace std;

int main(){
	long long s,c;
	cin >> s >> c;
	if(s>=(c/2))
		cout << c/2;
	else{
		c/=2;
		c-=s;
		s+=(c/2);
		cout << s;
	}
	return 0;
}