#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, A, B;
	string S;
	cin >> N >> A >> B >> S;

	int a = 0;
	int b = 0;
	for( int i = 0; i < N; i++ ) {
		if( S[i] == 'a' ) {
			string ans = "No";
			if( a + b < A + B ) {
				a++;
				ans = "Yes";
			}
			cout << ans << endl;
		}
		else if( S[i] == 'b' ) {
			string ans = "No";
			if( a + b < A + B && b + 1 <= B ) {
				b++;
				ans = "Yes";
			}
			cout << ans << endl;
		}
		else cout << "No" << endl;
	}
}
