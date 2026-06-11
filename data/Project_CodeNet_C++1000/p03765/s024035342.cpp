#include<bits/stdc++.h>
using namespace std;

#define int long long

string s, t;
int prefa1[100005], prefa2[100005], q;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s >> t;
    prefa1[0] = (s[0] == 'A');
    for(int i = 1; i < s.length(); i++) prefa1[i] = (prefa1[i - 1] + (s[i] == 'A'));
    prefa2[0] = (t[0] == 'A');
    for(int i = 1; i < t.length(); i++) prefa2[i] = (prefa2[i - 1] + (t[i] == 'A'));
    cin >> q;
    while(q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int diff1 = 2 * (prefa1[r1 - 1] - ((l1 == 1) ? 0 : prefa1[l1 - 2])) - (r1 - l1 + 1);
        int diff2 = 2 * (prefa2[r2 - 1] - ((l2 == 1) ? 0 : prefa2[l2 - 2])) - (r2 - l2 + 1);
        if(abs(diff1 - diff2) % 3) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
}