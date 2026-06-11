#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> a(3);

    for(int i = 0; i < 3; i++) cin >> a[i];

    sort(a.begin(), a.end());

    if(a[0] + a[1] == a[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
}