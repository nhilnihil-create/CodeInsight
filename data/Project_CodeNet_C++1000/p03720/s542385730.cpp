#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> roads(M,vector<int>(2));
    for (int i=0; i<M; i++) {
        for (int j=0; j<2; j++) {
            cin >> roads.at(i).at(j);
        }
    }

    vector<int> answer(N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
        for (int k=0; k<2; k++) {
            if (roads.at(j).at(k)-1==i) {
                answer.at(i)++;
            }
        }
    }
    }

    for (int i=0; i<N; i++) {
        cout << answer.at(i) << endl;
    }
}