#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    string n;
    cin >> n;
    
    string rn = n;
    reverse(rn.begin(), rn.end());

    cout << (n == rn ? "Yes" : "No") << endl;

    return 0;
}
