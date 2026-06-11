#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    //-1, 0 -> None. 1 -> Inc. 2 -> Dec.
    short current_dir = -1;
    int last = 0;
    int min_subarr = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (current_dir == -1) {
            current_dir = 0;
        }
        else if (current_dir == 0) {
            if (x > last) {
                current_dir = 1;
            }
            else if (x < last) {
                current_dir = 2;
            }
            else {
                current_dir = 0;
            }
        }
        else if (current_dir == 1) {
            if (x < last) {
                min_subarr++;
                current_dir = 0;
            }
        }
        else if (current_dir == 2) {
            if (x > last) {
                min_subarr++;
                current_dir = 0;
            }
        }
        last = x;
    }
    cout << min_subarr;
}