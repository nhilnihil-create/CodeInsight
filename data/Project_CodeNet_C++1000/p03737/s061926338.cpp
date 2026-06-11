#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

string s1, s2, s3;

int main() {
    cin >> s1 >> s2 >> s3;
    cout << char(toupper(s1[0])) << char(toupper(s2[0])) << char(toupper(s3[0])) << endl;
    return 0;
}
