#include <bits/stdc++.h>
#define endl '\n';

typedef long long ll;

using namespace std;

const string YES = "Yes";
const string NO  = "No";

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;

    cin >> s;

    if (s.substr(0, 4) == "YAKI") {
        cout << YES;
    } else {
        cout << NO;
    }
    cout << endl;

    return 0;
}

