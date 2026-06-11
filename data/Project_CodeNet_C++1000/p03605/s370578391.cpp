#include <bits/stdc++.h>
#define nl ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define pi acos(-1)

using namespace std;

int main() {
    nl // Bazzi - Paradise

    string s; cin >> s;

    bool a = 0;

    for(auto x : s) {
        if(x == '9') a = 1;
    }
    cout << (a ? "Yes" : "No");
    return 0;
}