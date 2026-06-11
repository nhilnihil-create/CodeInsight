#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
ll const INF = 1LL << 60;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    int passcnt = 0;
    int passcnt_abroad = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'a') {
            if (passcnt < A+B) {
                cout << "Yes" << endl;
                passcnt++;
            } else {
                cout << "No" << endl;
            }
        } else if (S[i] == 'b') {
            if (passcnt < A+B && passcnt_abroad < B) {
                cout << "Yes" << endl;
                passcnt++;
                passcnt_abroad++;
            } else {
                cout << "No" << endl;
            }
        } else if (S[i] == 'c') {
            cout << "No" << endl;
        }        
    }

    return 0;
}