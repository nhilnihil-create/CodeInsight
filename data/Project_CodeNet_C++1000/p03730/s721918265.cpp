#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    for(int i = 1; i < 10000; i++) {
        if(A * i % B == C) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}