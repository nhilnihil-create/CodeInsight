#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    int x = A + B;

    if(x >= 10) cout << "error" << endl;
    else cout << x << endl;
}