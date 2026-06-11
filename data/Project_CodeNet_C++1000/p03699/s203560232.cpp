#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> s(N);
    int m = 1000;
    int total = 0;
    rep(i, N){
        cin >> s[i];
        if(s[i] % 10 != 0){
            m = min(m, s[i]);
        }
        total += s[i];
    }

    if(total % 10 != 0){
        cout << total << endl;
    } else {
        if(m == 1000){
            cout << 0 << endl;
        } else {
            cout << total - m << endl;
        }
    }


    return 0;
}