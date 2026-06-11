#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t N,A,B;
    int64_t last; 
    int64_t ans = 0;
    cin >> N >> A >> B;

    vector<int> X(N);
    for(int i=0;i<N;i++) {
        cin >> X[i];
    }    

    last = X[0];
    for(int i=1;i<N;i++) {
        if(((X[i]-X[i-1]) * A) > B) {
            ans += B;
        } else {
            ans += ((X[i]-X[i-1]) * A);
        } 
    }

    cout << ans << "\n";
    return 0;
}
