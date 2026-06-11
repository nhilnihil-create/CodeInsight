#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<char> s(n);
    rep(i, n)
        cin >> s.at(i);

    int c = 0, cb = 0;

    rep(i, n) {
        if (s.at(i) == 'a') {
            if (c < (a + b)) {
                cout << "Yes" << endl;
                c++;
            } else {
                cout << "No" << endl;
            }
        } else if (s.at(i) == 'b') {
            if (c < (a + b) && cb < b) {
                cout << "Yes" << endl;
                c++;
                cb++;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
}