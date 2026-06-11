#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    if(A <= C && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}