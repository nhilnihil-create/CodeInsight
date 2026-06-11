#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    vector<pair<int, int> > A(26, make_pair(0, -1));
    vector<bool> B(26, 0);
    for(int i = 0; i < s.size(); i++) {
        int now = s.at(i) - 'a';
        A.at(now).first = max(A.at(now).first, i - A.at(now).second - 1);
        A.at(now).second = i;
        B.at(now) = 1;
    }
    for(int i = 0; i < 26; i++) {
        A.at(i).first = max(A.at(i).first, (int)s.size() - A.at(i).second - 1);
    }
    
    int ans = 10000;

    for(int i = 0; i < 26; i++) {
        //cout << i << ':' << A.at(i).first << endl;
        if(B.at(i)) {
            ans = min(ans, A.at(i).first);
        }
    }

    cout << ans << endl;



    return 0;
}