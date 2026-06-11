#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, M;
    cin >> N >> M;
    int a, b;
    vector<vector<int>> island(N);
    for ( int i=0; i<M; i++ ) {
        cin >> a >> b;
        a--; b--;
        island.at(a).push_back(b);
        island.at(b).push_back(a);
    }

    bool possible = false;
    for ( auto itr1 : island.at(0) ) {
        for ( auto itr2 : island.at(itr1) ) {
            if ( itr2 == N-1 ) {
                possible = true;
                goto END;
            }
        }
    }

END:
    if ( possible )
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
