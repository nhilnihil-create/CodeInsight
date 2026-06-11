#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {   
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    reverse(sc.begin(), sc.end());
    char last = 'a';
    while (1) {
        if (last == 'a') {
            if (sa.empty()) {
                cout << "A" << endl;
                return 0;
            }
            last = sa.back();
            sa.pop_back();
        } else if (last == 'b') {
            if (sb.empty()) {
                cout << "B" << endl;
                return 0;
            }
            last = sb.back();
            sb.pop_back();
        } else {
            if (sc.empty()) {
                cout << "C" << endl;
                return 0;
            }
            last = sc.back();
            sc.pop_back();
        }
    }
}


