#include <iostream>
using namespace std;

bool ask(int64_t a){;
	cout << "? " << a << endl;
	char c;
	cin >> c;
	return c == 'Y';
}

void ans(int64_t a){
	cout << "! " << a << endl;
}

int main(){
	if(ask(1e9)){
		int64_t a = 2;
		while(!ask(a)) a *= 10;
		ans(a / 2);
	}else{
		int64_t a = 1e8;
		while(!ask(a)) a /= 10;
		int64_t l = a, r = a * 10 - 1;
		while(1 < r - l){
			int64_t mid = (l + r) / 2;
			(ask(mid * 10) ? r : l) = mid;
		}
		ans(r);
	}
}