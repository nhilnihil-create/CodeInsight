#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int H, W;
    bool ok = true;
    cin >> H >> W;
    vector<string>A(H);
    set<char>s;
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }
    map<char, int>mp;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            mp[A[i][j]]++;
            s.insert(A[i][j]);
        }
    }
    int a, b, c;
    a = (H/2)*(W/2);
    b = (H%2)*(W/2) + (W%2)*(H/2);
    c = (H%2)*(W%2);
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        if (mp[*itr] % 4 == 0) {
            cnt1 += (mp[*itr]/4);
        } else if (mp[*itr] % 2 == 0) {
            cnt1 += (mp[*itr]/4);
            mp[*itr] -= (mp[*itr]/4)*4;
            cnt2 += (mp[*itr]/2);
        } else {
            cnt1 += (mp[*itr]/4);
            mp[*itr] -= (mp[*itr]/4)*4;
            cnt2 += (mp[*itr]/2);
            mp[*itr] -= (mp[*itr]/2)*2;
            cnt3 += mp[*itr];
        }
    }

    if (a <= cnt1) {
        cnt1 -= a;
        cnt2 += cnt1*2;
        if (b == cnt2 && c == cnt3) {
            cout << "Yes" << endl; 
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}
