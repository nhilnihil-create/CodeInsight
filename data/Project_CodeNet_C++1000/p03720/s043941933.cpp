#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> road(N, 0);

    int a, b;

    rep2(i, 0, M){
        cin >> a >> b;
        road.at(a-1)++;
        road.at(b-1)++;
    }

    rep2(i, 0, N){
        cout << road.at(i) << endl;
    }
}
