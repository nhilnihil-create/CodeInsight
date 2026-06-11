#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    if(S.substr(0, 4) == "YAKI") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
