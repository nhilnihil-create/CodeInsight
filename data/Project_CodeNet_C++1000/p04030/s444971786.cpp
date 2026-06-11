#include <bits/stdc++.h>

#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    string in;
    cin >> in;

    vector<string> s;

    int curr;

    for (int i = 0; i < in.length(); ++i) {
        if (in[i] == '0') {
            s.pb("0");
        } else if(in[i] == '1') {
            s.pb("1");
        } else if (in[i] == 'B' && s.size()) {
            s.pop_back();
        }
    }

    for (string ss : s) {
        cout << ss;
    }
}
