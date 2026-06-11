#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
void deal(vector<int>& v) {
    string s;
    cin >> s;
    vector<int> sta;
    for(int i = 0; i < s.length(); i++) {
        if(sta.size() == 0) sta.push_back(s[i]-'A');
        else {
            sta.push_back(s[i]-'A');
            if(sta[0] == sta[1]) {
                int c = sta[0];
                sta.clear();
                sta.push_back(!c);
            } else {
                sta.clear();
            }
        }
        if(sta.size() == 0) v.push_back(-1);
        else v.push_back(sta[0]);
        // cout << v.back() << endl;
    }
}
vector<int> v[2];
int getans(int o, int l, int r) {
    l--; r--;
    if(l-1<0) return v[o][r];
    int c = v[o][l-1], g = v[o][r];
    if(c==g) return -1;
    if(g==-1) {
        return !c;
    } else if(g==0) {
        if(c==-1) return 0;
        return 1;
    } else {
        if(c==-1) return 1;
        return 0;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    deal(v[0]);
    deal(v[1]);
    // cout << getans(0, 1, 6) << " " << getans(0, 1, 9) << endl;
    // cout << getans(1, 1, 3) << endl;
    int q;
    cin >> q;
    while(q--) {
        int l0, r0, l1, r1;
        cin >> l0 >> r0 >> l1 >> r1;
        cout << (getans(0, l0, r0) == getans(1, l1, r1) ? "YES" : "NO") << '\n';
    }
    return 0;
}