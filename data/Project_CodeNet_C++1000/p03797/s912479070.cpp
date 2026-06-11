#include <iostream>

using namespace std;

int main() {
    long long int N, M;
    cin >> N >> M;
    
    long long int ans=0;
    if(N*2<=M) {
        ans += N;
        M -= N*2;
        
        ans += M/4;
    } else {
        ans += M/2;
    }

    cout << ans << endl;


    return 0;
    
}