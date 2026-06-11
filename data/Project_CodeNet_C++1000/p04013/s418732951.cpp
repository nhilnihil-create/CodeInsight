#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, A;
    cin >> N >> A;
    
    vector<long long int> x(N);
    long long int X=0;
    for(int n=0; n<N; n++) {
        cin >> x[n];
        x[n] -= A;
        X = max(abs(x[n]), X);
    }
    
    vector<vector<long long int> > memo(N+1, vector<long long int>(2*N*X+1, 0));
    memo[0][N*X]=1;
    for(int n=1; n<=N; n++) {
        for(int t=0; t<=2*N*X; t++) {
            memo[n][t] = memo[n-1][t];
            
            if(t-x[n-1]>=0 && t-x[n-1]<=2*N*X) {
                memo[n][t] += memo[n-1][t-x[n-1]];
            }
        }
    }
    
    // for(int n=0; n<=N; n++) {
    //     for(int i=0; i<memo[n].size(); i++) {
    //         cout << memo[n][i] << " ";
    //     }
    //     cout << endl;
    // }

    cout << memo[N][N*X]-1 << endl;
    

    return 0;
    
}