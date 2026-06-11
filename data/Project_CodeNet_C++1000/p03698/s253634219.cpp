#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    string s;
    cin >> s;
    string t = s;
    int n = s.size();

    rep (i, n) {
        rep(j, n) {
            if(i!=j) {
                if(s[i] == t[j]) {
                    cout << "no" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "yes" << endl;

    return 0;
}