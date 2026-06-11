#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int INF=1e5;

int main() {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    
    vector<vector<int> > dp(401, vector<int>(401, INF));
    dp[0][0]=0;
    
    vector<pair<pair<int, int>, int> > abc(N);
    for(int n=0; n<N; n++) {
        int a, b, c;
        cin >> a >> b >> c;
        abc[n]=make_pair(make_pair(a, b), c);
    }
    
    // dp
    for(int n=0; n<N; n++) {
        vector<vector<int> > dptmp(401, vector<int>(401));
        dptmp=dp;
        for(int wa=0; wa<401; wa++) {
            for(int wb=0; wb<401; wb++) {
                if(wa-abc[n].first.first>=0 && wb-abc[n].first.second>=0 &&\
                 dp[wa-abc[n].first.first][wb-abc[n].first.second]!=INF) {
                    dptmp[wa][wb] \
                    = min(dp[wa][wb], \
                        dp[wa-abc[n].first.first][wb-abc[n].first.second]+abc[n].second);
                }
            }
        }
        dp=dptmp;
    }
    
    // cout << "Searching Ma:Mb" << endl;
    // Searching Ma : Mb 
    int mmax=max(Ma, Mb);
    int ma=Ma, mb=Mb;
    int min_cost=INF;
    while(mmax<=400) {
        for(int wa=0; wa<401; wa++) {
            for(int wb=0; wb<401; wb++) {
                min_cost = min(min_cost, dp[ma][mb]);
            }
        }
        
        mmax+=mmax;
        ma += Ma;
        mb += Mb;
    }

    if(min_cost==INF) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }

    return 0;
    
}