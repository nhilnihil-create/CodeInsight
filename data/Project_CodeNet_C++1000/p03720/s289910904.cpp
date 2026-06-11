#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> result(N);
    for (int road=0; road < M; road++) {
        int X = 0, Y = 0;
        cin >> X >> Y;
        result[X-1] += 1;
        result[Y-1] += 1;
    }
    for (int each=0; each < N; each++) {
        cout << result[each] << endl;
    }
}