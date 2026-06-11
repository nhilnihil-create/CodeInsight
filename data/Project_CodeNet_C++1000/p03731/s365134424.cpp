#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, T;
    cin >> N >> T;
    int T_time = 0;
    int total_time = 0;

    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        if(T_time > t) total_time -= T_time - t;
        T_time = t + T;
        total_time += T_time - t;
    }
    cout << total_time << endl;
}