#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        A.at(i)--;
    }
    int now = 0;
    for(int i = 0; i < N; i++) {
        now = A.at(now);
        if(now == 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;



    return 0;
}