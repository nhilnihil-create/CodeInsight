#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll oo = 1e18;
const ll mod = 1e9 + 7,maxn = 100000000;
const double PI = acos(-1);

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;

    for (int i=0; i<a.size(); i++){
        cout << a[i];
        if (i < b.size())cout << b[i];
    }

    cout << endl;
    return 0;
}