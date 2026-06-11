#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

#define INF 1e9
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int main() {
    string s;
    cin >> s;
    vector<bool> a(26, false);
    rep(i, s.size()) {
        if (a.at(s.at(i) - 'a')) {
            cout << "no" << endl;
            return 0;
        }
        else a.at(s.at(i) - 'a') = true;
    }
    cout << "yes" << endl;
}