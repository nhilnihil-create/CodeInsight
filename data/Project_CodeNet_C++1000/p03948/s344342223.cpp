#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    vector<int> r(A.begin(), A.end());
    for(int i=N-2; i>=0; i--) {
        r[i] = max(r[i], r[i+1]);
    }

    map<int,int> mp;
    for(int i=0; i<N-1; i++) {
        mp[r[i] - A[i]]++;
    }

    cout << (*mp.rbegin()).second << endl;
    return 0;
}
