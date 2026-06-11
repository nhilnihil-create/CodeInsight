#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    char ans = 'a';
    bool check;
    while (ans <= 'z') {
        check = true;
        for (int i = 0; i < N; i++) {
            if (S.at(i) == ans) {
                ans = ans + 1;
                check = false;
                break;
            }
        }
        if (check) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}
