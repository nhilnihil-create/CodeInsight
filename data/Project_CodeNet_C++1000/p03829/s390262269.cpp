#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long int A, B;
    cin >> N >> A >> B;
    
    vector<long long int> X(N);
    long long int ans=0;
    for(int n=0; n<N; n++) {
        cin >> X[n];
        if(n>0) {
            ans += min((X[n]-X[n-1])*A, B);
        }
    }
    
    cout << ans << endl;
    

    return 0;
    
}