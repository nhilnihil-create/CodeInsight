#include<bits/stdc++.h>

using namespace std;

#define int long long

int f(int i,int x = 10) {
	int ans = 1;
	while(i--)  ans *= x;
	return ans;
}

signed main()   {
	int s = 0;
	for(int i = 1 ; i < 11 ; ++i)   {
		cout << "? " << f(i) << "\n";
		cout.flush();
		char c; cin >> c;
		if(c == 'N')    {
			s = i;
			break;
		}
	}
	
	if(s == 0)
		for(int i = 1 ; i < 11 ; ++i)   {
			cout << "? " << f(i) - 1 << "\n";
			cout.flush();
			char c; cin >> c;
			if(c == 'Y')    {
				cout << "! " << f(i - 1) << "\n";
				cout.flush();   exit(0);
			}
		}
	
	int L = f(s - 1), R = f(s) - 1;
	
	while(L != R)   {
		int M = (L + R) / 2;
		cout << "? " << M * 10 << "\n";
		cout.flush();
		char c; cin >> c;
		if(c == 'Y')
			R = M;
		else
			L = M + 1;
	}
	
	cout << "! " << L << "\n";
	cout.flush();
}