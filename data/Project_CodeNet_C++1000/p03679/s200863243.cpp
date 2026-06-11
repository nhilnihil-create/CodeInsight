#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int X, A, B;
    cin >> X >> A >> B;

    if(A >= B) {
        cout << "delicious" << endl;
    } else if(X + A >= B) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
}