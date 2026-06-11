#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	string str;
	cin >> str;
	int cnt = 0;
	int cntb = 0;
	for(int i=0; i<n; i++) {
		if(str[i]=='c') cout << "No\n";
		else if(str[i]=='a') {
			if(a+b>cnt) cout << "Yes\n";
			else cout << "No\n";
			cnt++;
		}
		else {
			if(a+b>cnt && cntb<b) {
				cout << "Yes\n";
				cnt++;
			}
			else cout << "No\n";
			cntb++;
		}
	}
	return 0;
}
