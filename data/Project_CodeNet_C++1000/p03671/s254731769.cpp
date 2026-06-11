#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> a(3);

    for(int i = 0; i < 3; i++) cin >> a[i];

    sort(a.begin(), a.end());

    cout << a[0] + a[1] << endl;
}