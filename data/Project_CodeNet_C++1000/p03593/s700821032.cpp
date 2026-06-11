#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<int> cnt(26, 0);
    char x;
    for (int i = 0; i < h * w; i++) cin >> x, cnt[x - 'a']++;
    int one = 0;
    for (int i = 0; i < 26; i++){
        if (cnt[i] % 2) one++, cnt[i]--;
    }
    if ((h * w % 2 == 0 && one) || one > 1){
        cout << "No" << endl;
        return 0;
    }
    int two = 0;
    if (h % 2) two += w / 2;
    if (w % 2) two += h / 2;
    int four = (h * w - (h * w % 2) - two * 2) / 4;
    for (int i = 0; i < 26; i++) four -= cnt[i] / 4;
    if (four > 0) cout << "No" << endl;
    else cout << "Yes" << endl;
}
