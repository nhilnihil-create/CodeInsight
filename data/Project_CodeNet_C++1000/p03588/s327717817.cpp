#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
const int MAX_N = 1.0e5 + 100;
pair<int, int> AB[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }

    sort(AB, AB+N);

    cout << AB[N-1].first + AB[N-1].second << endl;
    
    return 0;
}
