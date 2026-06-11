#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector< vector<int> > wf(N, vector<int>(N, 1000000000));
    vector< tuple<int,int,int> > edge;
    while(M--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        wf[a][b] = c;
        wf[b][a] = c;
        edge.emplace_back(a, b, c);
    }

    for(int k=0; k<N; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++){
                wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
                // if(wf[i][j] > wf[i][k] + wf[k][j]) {
                //     ++ans;
                //     // wf[i][j] = wf[i][k] + wf[k][j];
                // }
            }
        }
    }

    int ans = 0;
    for(auto e: edge) {
        int a = get<0>(e);
        int b = get<1>(e);
        int c = get<2>(e);
        if(wf[a][b] != c) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
