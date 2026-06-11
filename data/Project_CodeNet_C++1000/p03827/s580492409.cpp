#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'I') {
            sum++;
        }
        else {
            sum--;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}