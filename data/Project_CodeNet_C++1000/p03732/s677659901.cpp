#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<long long int> W;
vector<long long int> V;
int N;

int main() {
    long long int maxW;
    cin >> N >> maxW;
    
    W.resize(N+1);
    V.resize(N+1);
    for(int n=1; n<N+1; n++) {
        cin >> W[n] >> V[n];
    }

    long long int dpnum=N;
    long long int cycle=dpnum*3+1;
    dpnum = cycle*dpnum;
    vector<vector<long long int> > dp(2, vector<long long int>(dpnum+1, -1));
    dp[0][0]=0;
    
    for(int n=0; n<N; n++) {
        for(int w=0; w<dpnum+1; w++) {
            if(n%2==0) {
                if(dp[0][w]!=-1) {
                    dp[1][w] = max(dp[1][w], dp[0][w]);
                    
                    if(w==0) {
                        dp[1][W[n+1]-W[1]+1] = max(dp[1][W[n+1]-W[1]], dp[0][w]+V[n+1]);
                    } else {
                        dp[1][w+cycle+W[n+1]-W[1]] = max(dp[1][w+cycle+W[n+1]-W[1]], dp[0][w]+V[n+1]);
                    }
                }
            } else {
                if(dp[1][w]!=-1) {
                    dp[0][w] = max(dp[0][w], dp[1][w]);
                    
                    if(w==0) {
                        dp[0][W[n+1]-W[1]+1] = max(dp[0][W[n+1]-W[1]], dp[1][w]+V[n+1]);
                    } else {
                        dp[0][w+cycle+W[n+1]-W[1]] = max(dp[0][w+cycle+W[n+1]-W[1]], dp[1][w]+V[n+1]);
                    }
                }
            }
        }
    }
    
    // cout << endl;
    long long int ans=0;
    for(int w=1; w<dpnum+1; w++) {
        // cout << ((w-1)/cycle+1)*W[1]+(w-1)%cycle << endl;
        if(((w-1)/cycle+1)*W[1]+(w-1)%cycle<=maxW) {
            if((N-1)%2==0) {
                ans = max(ans, dp[1][w]);
            } else {
                ans = max(ans, dp[0][w]);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
    
}