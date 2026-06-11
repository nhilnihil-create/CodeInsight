#include <iostream>
#include <string>
using namespace std;
int sa[100002], sb[100002], ta[100002], tb[100002];

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for(int i = 1; i <= n; i++){
        sa[i] = sa[i - 1], sb[i] = sb[i - 1];
        if(s[i - 1] == 'A') sa[i]++;
        else sb[i]++;
    }
    for(int i = 1; i <= m; i++){
        ta[i] = ta[i - 1], tb[i] = tb[i - 1];
        if(t[i - 1] == 'A') ta[i]++;
        else tb[i]++;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((((sa[b] - sa[a - 1]) - (sb[b] - sb[a - 1])) - ((ta[d] - ta[c - 1]) - (tb[d] - tb[c - 1]))) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}