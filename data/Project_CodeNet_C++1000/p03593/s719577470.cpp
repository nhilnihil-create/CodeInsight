#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int H, W;
    cin >> H >> W;
    vector<int> count(26, 0);
    for (int i = 0; i < H*W; i++) {
        char c;
        cin >> c;
        count[c-'a']++;
    }
    int s = 0, t = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) s++;
        if (count[i] % 4 >= 2) t++;
    }
    if (H*W % 2 == 1) {
        if (s == 1 && t*2 <= H+W-2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if (H%2 ^ W%2) {
        if (H % 2 == 1) swap(H, W);
        if (s == 0 && t*2 <= H) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if (H%2==0 && W%2==0) {
        if (s == 0 && t == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}