#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    map<char, int> alph;
    char maximum = 'a';
    for (int i = 0; i < s.size(); i++) {
        alph[s[i]]++;
        if (alph[s[i]] >= alph[maximum]) {
            if (alph[s[i]] == alph[maximum] && s[0] == s[i]) {
                continue;
            } else {
                maximum = s[i];
            }
        }
    }

    string t = s;
    map<char, int> alph_tmp = alph;
    int min_out = s.size();
    for (char maximum = 'a'; maximum <= 'z'; maximum++) {
        string s = t;
        alph = alph_tmp;
        while (s.size() != alph[maximum]) {
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] != maximum && s[i + 1] == maximum) {
                    alph[s[i]]--;
                    s[i] = maximum;
                    alph[maximum]++;
                }
            }
            for (int i = s.size() - 1; i >= 0; i--) {
                // if (s[i] != maximum || i == 0) {
                alph[s[i]]--;
                s.erase(i, 1);
                break;
                // }
            }
            // if (maximum == 'r') {
            // cout << s << " " << s.size() << " " << alph[maximum] << endl;
            // }
        }
        int output = t.size() - s.size();
        // if (output != t.size()) {
        // cout << maximum << " " << s << " " << output << endl;
        // }
        if (min_out > output) min_out = output;
    }
    cout << min_out << endl;

    return 0;
}
