#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    if(A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}