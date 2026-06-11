#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(9,0);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if(temp >= 3200) {
            A.at(8)++;
        } else {
            A.at(temp/400)++;
        }
    }
    for(int i = 0; i < 8; i++) {
        if(A.at(i)) {
            ans++;
        }
    }
    cout << ans + (ans == 0) << ' ';
    ans += A.at(8);
    cout << ans << endl;
    

    return 0;
}