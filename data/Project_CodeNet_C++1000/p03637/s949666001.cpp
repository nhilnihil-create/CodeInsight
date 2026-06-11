#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, four = 0, two = 0, odd = 0;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
        if (A[i] % 4 == 0 ) four++;
        else if (A[i] % 2 == 0) two++;
        else odd++;
    }

    if(N / 2 <= four) cout << "Yes" << endl;
    else if(N / 2 <= odd) cout << "No" << endl;
    else if(four + two / 2 >= N / 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}