#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int ans = 0;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i)%2)
    {
        ans++;
    }
    
    }
    if(ans%2) {
    cout << "NO" << endl;
    } else {
    cout << "YES" << endl;
    }

    return 0;
}