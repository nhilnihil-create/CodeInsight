#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {
    int N;
    cin >> N;
    vector<int> p(N+1);
    for(int i=1; i<=N; ++i) cin >> p[i];

    int res = 0;
    for(int i=1; i<=N; ++i) {
        if(p[i] == i) {
            if(i < N) swap(p[i], p[i+1]);
            ++res;
        }
    }
    cout << res << endl;
}