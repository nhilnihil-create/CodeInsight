#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n / 10 == 9 || n % 10 == 9)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}
