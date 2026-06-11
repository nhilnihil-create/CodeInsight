#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    string SA, SB, SC;
    cin >> SA >> SB >> SC;

    reverse(SA.begin(), SA.end());
    reverse(SB.begin(), SB.end());
    reverse(SC.begin(), SC.end());

    // cout << &SA << endl;
    // cout << &SB << endl;
    // cout << &SC << endl;

    string* current = &SA;    

    char currentChar = 'A';

    while (true) {
    // for (int i = 0; i < 5; i++) {

        if (current->empty()) {
            cout << currentChar << endl;
            return 0;
        }

        char c = current->back();
        current->pop_back();

        // cout << c << ", " << current << ", " << currentChar << endl;        

        if (c == 'a') {
            current = &SA;
            currentChar = 'A';
        } else if (c == 'b') {
            current = &SB;
            currentChar = 'B';
        } else {
            current = &SC;
            currentChar = 'C';
        }
    }

    return 0;
}
