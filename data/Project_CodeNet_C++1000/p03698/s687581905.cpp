#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define int long long
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

signed main() {

    string s;
    int n;
    set<char> S;

    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i ++){
        S.insert(s[i]);
    }
    if(n == S.size()) cout << "yes";
    else cout << "no";
    return 0;
}