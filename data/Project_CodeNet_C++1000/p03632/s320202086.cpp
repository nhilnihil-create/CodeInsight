#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

typedef pair<ll, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int ac = max(A, C);
    int bd = min(B, D);

    cout << max(0, bd - ac) << endl;
}