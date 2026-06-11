#include<bits/stdc++.h>
using namespace std;

#define int long long

int binpw(int x){
	int ans = 1;
	for(int i = 0; i < x; i++) ans *= 10;
	return ans;
}

signed main()
{
	int x = 1;
	for(; x <= 10 ; ++x)	{
		cout << "? " << binpw(x) << endl;
		fflush(stdout);
		char a;
		cin >> a;
		if(a == 'N'){
			x--;
			break;
		}
	}
	if(x == 11){
		for(int i = 1; i <= 10; i++){
			cout << "? " << binpw(i) - 1 << endl;
			fflush(stdout);
			char a;
			cin >> a;
			if(a == 'Y'){
				cout << "! " << binpw(i - 1);
				return 0;
			}
		}
	}
	int l = binpw(x), r = binpw(x + 1) - 1;
	while(l != r){
		int mid = (l + r) / 2;
		cout << "? " << mid * 10 << endl;
		fflush(stdout);
		char a;
		cin >> a;
		if(a == 'N') l = mid + 1;
		else r = mid;
	}
	cout << "! " << l;
	return 0;
}