#include <bits/stdc++.h>
using namespace std;

#define min(a,b) (((a) > (b)) ? (b) : (a))
int main(void) {
    int64_t N,T;
    int64_t sum;
    int64_t tmp;
    cin >> N >> T;
    vector<int64_t> t(N);
    for(int i=0;i<N;i++) {
        cin >> t[i];        
    }

    sum = T;
    for(int i=1;i<N;i++) {
        sum += min(T,t[i] - t[i-1]);
    }

    cout << sum << "\n";
    return 0;
}
