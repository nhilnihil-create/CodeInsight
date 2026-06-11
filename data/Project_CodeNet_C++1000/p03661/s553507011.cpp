#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long int> sA(N+1, 0);
    for(int n=0; n<N; n++) {
        long long int a;
        cin >> a;
        sA[n+1] = sA[n]+a;
    }
    
    long long int ans=1e14;
    for(int n=1; n<N; n++) {
        ans = min(ans, abs(2*sA[n]-sA[0]-sA[N]));
    }
    cout << ans << endl;


    return 0;
    
}