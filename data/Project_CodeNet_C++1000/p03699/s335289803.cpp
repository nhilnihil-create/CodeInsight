#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main() {
    int N, s{}, m{100};
    cin >> N;
    while(cin >> N) {
        s += N;
        if (N % 10){
            m = min(m , N);
        }
    }
    if (m == 100){
        s = 0;
    }
    else if (s % 10 == 0){
        s -= m;
    }
    cout << s << endl;
}