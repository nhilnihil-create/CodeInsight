#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    reverse(s.begin(), s.end());

    vector<string> words = {"dream", "dreamer", "erase", "eraser"};
    for(int i = 0; i < 4; i++){
        reverse(words[i].begin(), words[i].end());
    }

    string cal;
    for(int i = 0; i < (int)s.size(); i++){
        cal += s[i];
        for(int j = 0; j < 4; j++){
            if((string)cal == words[j]){
                cal = "";
            }
        }
    }

    cout << (cal == "" ? "YES" : "NO") << endl;

    return 0;
}
