#include<iostream>

using namespace std;
typedef long long ll;

int main() {
	ll K;
	cin >> K;
	cout << 50 << endl;
	ll nanjunka = K / 50;//何巡回すか
	ll amari = K % 50;//余り
	
	for (int i = 0; i < 50; i++) {
		ll tmp = 0;
		if (nanjunka == 0 || K == 50) {
			if (amari == 0 && K == 50)amari = 50;
			if (amari > i)tmp = (50 - i);
		}
		else {
			tmp = i + 1;
			tmp += nanjunka - 1;
			if ((50 - amari) <= i)tmp += 1;
		}
		cout << tmp << " ";
	}
	cout << endl;
	return 0;
}