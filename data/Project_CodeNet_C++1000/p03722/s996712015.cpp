#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const long long int INF=1e14;
vector<pair<pair<int, long long int>, int> > E;

int main() {
    int N, M;
    cin >> N >> M;
    E.resize(M);
    
    for(int m=0; m<M; m++) {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        
        E[m]=make_pair(make_pair(a-1, b-1), -c);
    }

    vector<long long int> score(N, INF);
    score[0]=0;

    for(int n=0; n<N; n++) {
        for(int m=0; m<M; m++) {
            int from = E[m].first.first;
            int target = E[m].first.second;
            long long int cost = E[m].second;
            if(score[from]!=INF && score[target]>score[from]+cost) {
                if(n==N-1 && target==N-1) {
                    cout << "inf" << endl;
                    return 0;
                }
                // if(n==N-1 && score[target]==INF) {
                //     cout << "inf" << endl;
                //     return 0;
                // }
                score[target] = score[from]+cost;
                // if(n==N-1) {
                //     cout << "inf" << endl;
                //     return 0;
                // }
            }
        }
    }

    cout << -score[N-1] << endl;
    
    return 0;
    
}