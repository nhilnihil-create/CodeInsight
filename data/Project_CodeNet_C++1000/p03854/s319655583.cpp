#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    string S;
    cin >> S;
    int N = S.size();
    vector<string> v = {"dream", "dreamer", "erase", "eraser"};

    reverse(S.begin(), S.end());
    for(auto &e: v) {
        reverse(e.begin(), e.end());
    }

    int now = 0;
    while(now < N) {
        bool flag = false;
        for(auto e: v) {
            if(S.substr(now, e.size()) == e) {
                now += e.size();
                flag = true;
            }
        }
        if(flag) continue;
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}
