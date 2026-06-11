#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long int> A(N), B(N);
    for(int n=0; n<N; n++) {
        cin >> A[n] >> B[n];
    }
    long long int cnt=0;
    for(int n=N-1; n>=0; n--) {
        cnt += (B[n]-(A[n]+cnt)%B[n])%B[n];
    }
    
    cout << cnt << endl;


    return 0;
    
}