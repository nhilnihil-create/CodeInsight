#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long sum = 0;
    for(int i=1; i<=N; ++i) {
        sum += i;
        if(sum >= N) {
            for(int j=1; j<=i; ++j) {
                if(j == sum - N) continue;
                cout << j << endl;
            }
            return 0;
        }
    }
}