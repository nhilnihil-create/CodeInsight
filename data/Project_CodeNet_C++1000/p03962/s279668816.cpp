#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    map<int, bool> m;

    for(int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        m[a] = true;
    }

    cout << m.size() << endl;   
}