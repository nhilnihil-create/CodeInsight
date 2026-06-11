#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string s, t;
    cin >> s >> t;

    vector<long> ss(s.size()+1), tt(t.size()+1);
    for(long i=1; i<=s.size(); i++)
        ss[i] = ss[i-1] + (s[i-1] == 'A' ? 1 : 2);
    for(long i=1; i<=t.size(); i++)
        tt[i] = tt[i-1] + (t[i-1] == 'A' ? 1 : 2);

    long q;
    cin >> q;
    for(long i=0; i<q; i++) {
        long a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        cout << (((ss[b+1]-ss[a]) - (tt[d+1]-tt[c]))%3 ? "NO" : "YES") << endl;
    }
}
