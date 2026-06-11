#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N,K;cin>>N>>K;
    vector<int> L;
    for (int i = 0;i < N; i++) {
        int l;cin>>l;
        L.push_back(l);
    }
    sort(L.begin(), L.end());
    
    int result = 0;
    for (int i = N - 1; i >= N - K; i--) {
        result += L[i];

    }
    cout << result << endl;
    return 0;
}