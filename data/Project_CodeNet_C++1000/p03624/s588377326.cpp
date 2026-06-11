#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    string s;
    cin >> s;
    bool abc[26];
    rep(i, 26) {
        abc[i] = false;
    }
    rep(i, s.size()) {
        abc[s[i] - 'a'] = true; //char型小文字アルファベットを数値に変換 -'a'
    }
    rep(i, 26) {
        if(!abc[i]) {
            char ans = i + 'a'; //数値を適合する小文字アルファベットに変換 +'a'
            printf("%c\n", ans);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}