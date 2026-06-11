#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    int q;
    cin >> s >> t >> q;

    int n = s.length();
    int m = t.length();

    // cumulative sum
    vector<int> sa(n+1), sb(n+1), ta(m+1), tb(m+1);
    for(int i=0; i<n; i++){
        if(s[i] == 'A') sa[i+1] = 1;
        if(s[i] == 'B') sb[i+1] = 1;
        sa[i+1] += sa[i];
        sb[i+1] += sb[i];
    }
    for(int i=0; i<m; i++){
        if(t[i] == 'A') ta[i+1] = 1;
        if(t[i] == 'B') tb[i+1] = 1;
        ta[i+1] += ta[i];
        tb[i+1] += tb[i];
    }

    for(int i=0; i<q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x = (sa[b] - sa[a-1]) - (sb[b] - sb[a-1]);
        x = (x % 3 + 3) % 3;
        int y = (ta[d] - ta[c-1]) - (tb[d] - tb[c-1]);
        y = (y % 3 + 3) % 3;

        if(x == y) cout << "YES" << endl;
        if(x != y) cout << "NO"  << endl;
    }
    return 0;
}