#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    speed();
    int a, b; cin >> a >> b;
    if (a > 0 && b >= 0) cout << "Positive" << endl;
    if (a <= b && b < 0) {
        if ((b-a+1) % 2 == 0) cout << "Positive" << endl;
        else cout << "Negative" << endl;
    }
    if (a <= 0 && b >= 0) cout << "Zero" << endl;
    return 0;
}