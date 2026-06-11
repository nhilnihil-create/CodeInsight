#include<bits/stdc++.h>
using namespace std;

int main()
{
	int R, C;
	cin >> R >> C;
	vector<string> in(R);
	for(string& i: in) cin >> i;
	
	for(int i = 0; i < R; i++) {
		for(int k = 0; k < 2; k++) { // repeat every row two times
			cout << in[i];
			puts("");
		}
	}
}
