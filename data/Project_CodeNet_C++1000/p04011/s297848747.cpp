#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    int N,K,X,Y;
    cin >> N >> K >> X >> Y;
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        if (i <= K) {
            total += X;
        } else {
            total += Y;
        }
    }
    cout << total << endl;
    return 0;
}

