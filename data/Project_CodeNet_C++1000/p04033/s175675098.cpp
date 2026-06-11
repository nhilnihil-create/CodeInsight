#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 2e3 + 5;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen("VLJUM.INP", "r", stdin);
        //freopen("VLJUM.OUT", "w", stdout);
        ll a, b;
        cin >> a >> b;
        if (a <= 0 && b >= 0) cout << "Zero";
        else {
                if (a > 0) {
                        cout << "Positive";
                } else {
                        if ((b - a) % 2 == 0) cout << "Negative";
                        else cout << "Positive";
                }
        }
}

